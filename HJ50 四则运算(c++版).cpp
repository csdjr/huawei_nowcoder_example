#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isHigher(char c1, char c2)
{
    if (c1 == '(')
        return true;
    if (c1 == '+' || c1 == '-')
    {
        if (c2 == '+' || c2 == '-')
            return false;
        if (c2 == '*' || c2 == '/')
            return true;
    }
    return false;
}

int calc(int n1, int n2, char c)
{
    switch (c)
    {
    case '+':
        return n1 + n2;
    case '-':
        return n1 - n2;
    case '*':
        return n1 * n2;
    case '/':
        return n1 / n2;
    }
    return 0;
}

int main()
{
    string s;
    while (getline(cin, s) && s.length())
    {
        int len = s.length();
        int i;
        for (i = 0; i < len; i++)
        {
            if (s[i] == '[' || s[i] == '{')
                s[i] = '(';
            else if (s[i] == ']' || s[i] == '}')
                s[i] = ')';
        }

        int n1, n2;
        char c;
        stack<int> nums;
        stack<char> calcs;
        for (i = 0; i < len; i++)
        {
            if (isdigit(s[i]) ||
                (s[i] == '-' && (i == 0 || s[i - 1] == '(')))
            {
                char *p;
                n1 = strtoul(&s[i], &p, 10);
                nums.push(n1);
                i = p - &s[0] - 1;
                continue;
            }
            if (s[i] == '(')
            {
                calcs.push(s[i]);
                continue;
            }
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                if (calcs.empty())
                {
                    calcs.push(s[i]);
                    continue;
                }
                c = calcs.top();
                if (isHigher(c, s[i]))
                {
                    calcs.push(s[i]);
                    continue;
                }
                n2 = nums.top(), nums.pop();
                n1 = nums.top(), nums.pop();
                calcs.pop();
                n1 = calc(n1, n2, c);
                nums.push(n1);
                i--;
                continue;
            }
            if (s[i] == ')')
            {
                while ((c = calcs.top()) != '(')
                {
                    n2 = nums.top(), nums.pop();
                    n1 = nums.top(), nums.pop();
                    c = calcs.top(), calcs.pop();
                    n1 = calc(n1, n2, c);
                    nums.push(n1);
                }
                calcs.pop();
            }
        }
        while (!calcs.empty())
        {
            n2 = nums.top(), nums.pop();
            n1 = nums.top(), nums.pop();
            c = calcs.top(), calcs.pop();
            n1 = calc(n1, n2, c);
            nums.push(n1);
        }
        cout << nums.top() << endl;
    }
}
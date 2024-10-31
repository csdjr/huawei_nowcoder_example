#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

int main()
{
    string s;
    while (getline(cin, s) && s.length())
    {
        stack<string> sk;
        int len = s.length();
        int i;

        for (i = 0; i < len; i++) //提取单词，入栈
        {
            string s2;
            if (isalpha(s[i]))
            {
                while (isalpha(s[i]))
                {
                    s2.push_back(s[i]);
                    i++;
                }
                sk.push(s2);
            }
        }
        while (!sk.empty()) //出栈
        {
            cout << sk.top() << " ";
            sk.pop();
        }
        cout << endl;
    }
}
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

bool cmp(char c1, char c2)
{
    c1 = tolower(c1);
    c2 = tolower(c2);
    if (c1 < c2)
        return true;
    else
        return false;
}

int main()
{
    string s;
    while (getline(cin, s) && s.length())
    {
        int len = s.length();
        string s2;
        int i, j;
        for (i = 0; i < len; i++)
        {
            if (isalpha(s[i]))
                s2.push_back(s[i]);
        }
        stable_sort(s2.begin(), s2.end(), cmp);
        for (i = 0, j = 0; i < len; i++)
        {
            if (isalpha(s[i]))
            {
                s[i] = s2[j++];
            }
        }
        cout << s << endl;
    }
}
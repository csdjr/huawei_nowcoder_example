#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
    int flag[256];
    string s;
    char c;
    while (getline(cin, s) && s.length()) //注意该输入方法
    {
        int len = s.length();
        memset(flag, 0, sizeof(flag));
        for (int i = 0; i < len; i++)
        {
            flag[tolower(s[i])]++;
        }
        cin >> c;
        cout << flag[tolower(c)] << endl;
    }
}
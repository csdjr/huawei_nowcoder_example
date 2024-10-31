#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <utility>

using namespace std;

bool check(string s)
{
    int len = s.length();
    if (len != 2 && len != 3)
        return false;
    if (s[0] != 'A' && s[0] != 'S' && s[0] != 'W' && s[0] != 'D')
        return false;
    for (int i = 1; i < len; i++)
    {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

int main()
{
    string s;
    while (getline(cin, s) && s.length())
    {
        int n1 = 0, n2 = 0;
        int pos1 = 0, pos2 = 0;
        while (pos2 != string::npos) //提取短句
        {
            pos1 = s.find_first_not_of(";", pos2);
            pos2 = s.find_first_of(";", pos1);
            string s2;
            if (pos1 != string::npos)
                s2 = s.substr(pos1, pos2 - pos1);
            else
                break;
            pos1 = pos2;

            if (!check(s2)) //检查参数合法性
                continue;

            int n3 = strtoul(s2.c_str() + 1, NULL, 10);
            if (s2[0] == 'A')
                n1 -= n3;
            else if (s2[0] == 'S')
                n2 -= n3;
            else if (s2[0] == 'W')
                n2 += n3;
            else if (s2[0] == 'D')
                n1 += n3;
        }
        cout << n1 << "," << n2 << endl;
    }
}

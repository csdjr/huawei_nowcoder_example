#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    while (getline(cin, s) && s.length())
    {
        int len = s.length();
        int pos = 0;
        while (pos < len)
        {
            string s2 = s.substr(pos, 8);
            if (s2.length() != 8)
            {
                int len2 = 8 - s2.length();
                s2.append(len2, '0');
            }
            cout << s2 << endl;
            pos = pos + 8;
        }
    }
}
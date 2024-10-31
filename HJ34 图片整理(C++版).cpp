#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    while (getline(cin, s) && s.length())
    {
#if 0
        int len = s.length();
        int i, j;
        for (i = 0; i < len - 1; i++)
            for (j = 0; j < len - 1 - i; j++)
            {
                if (s[j] > s[j + 1])
                {
                    char c = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = c;
                }
            }
#else
        sort(s.begin(), s.end());
#endif
        cout << s << endl;
    }
}
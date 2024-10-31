#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char convert(char c)
{
    int n;
    if (c >= '0' && c <= '9')
        n = c - '0';
    else if (c >= 'a' && c <= 'f')
        n = c - 'a' + 10;
    else if (c >= 'A' && c <= 'F')
        n = c - 'A' + 10;
    else
        return c;

    char b1, b2, b3, b4;
    b1 = n & 0b0001;
    b2 = n & 0b0010;
    b3 = n & 0b0100;
    b4 = n & 0b1000;
    n = b1 << 3 | b2 << 1 | b3 >> 1 | b4 >> 3;
    if (n >= 10)
        return toupper(n - 10 + 'a');
    else
        return n + '0';
}

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        string s = s1 + s2;
        s1.clear(), s2.clear();
        int len = s.length();
        int i, j;
        for (i = 0; i < len; i = i + 2)
            s1.push_back(s[i]);
        for (i = 1; i < len; i = i + 2)
            s2.push_back(s[i]);

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        for (i = 0, j = 0; j < s1.length(); i = i + 2, j++)
            s[i] = s1[j];
        for (i = 1, j = 0; j < s2.length(); i = i + 2, j++)
            s[i] = s2[j];

        for (i = 0; i < len; i++)
            s[i] = convert(s[i]);

        cout << s << endl;
    }
}
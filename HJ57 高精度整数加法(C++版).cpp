#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        int len1, len2;
        len1 = s1.length();
        len2 = s2.length();
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        if (len1 < len2)
        {
            swap(s1, s2);
            int tmp = len1;
            len1 = len2;
            len2 = tmp;
        }
        int i;
        int n1, n2, n3;
        n3 = 0;
        for (i = 0; i < len2; i++)
        {
            n1 = s1[i] - '0';
            n2 = s2[i] - '0';
            n2 = n1 + n2 + n3;
            n1 = n2 % 10;
            n3 = n2 / 10;
            s1[i] = n1 + '0';
        }
        for (i = len2; i < len1; i++)
        {
            n1 = s1[i] - '0';
            n2 = n1 + n3;
            n1 = n2 % 10;
            n3 = n2 / 10;
            s1[i] = n1 + '0';
        }
        if (n3 != 0)
            s1.push_back(n3 + '0');
        reverse(s1.begin(), s1.end());
        cout << s1 << endl;
    }
}
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>

using namespace std;

char convert(char p)
{
    int n;
    //转为数字
    if (isdigit(p))
        n = p - '0';
    else
    {
        p = tolower(p);
        n = p - 'a' + 10;
    }
    //位运算
    char b1, b2, b3, b4;
    b1 = n & 0b0001;
    b2 = n & 0b0010;
    b3 = n & 0b0100;
    b4 = n & 0b1000;
    n = (b1 << 3) | (b2 << 1) | (b3 >> 1) | (b4 >> 3);
    //转为字母
    if (n < 10)
        p = n + '0';
    else
        p = n - 10 + 'A';
    return p;
}

int main()
{
    string s1, s2, s3;
    int len1;
    int i, j;
    while (cin >> s1 && cin >> s2)
    {
        s1.append(s2);
        s2.clear();
        s3.clear();
        len1 = s1.length();
        for (i = 0; i < len1; i = i + 2)
            s2.push_back(s1[i]);
        for (i = 1; i < len1; i = i + 2)
            s3.push_back(s1[i]);
        sort(s2.begin(), s2.end(), less<char>());
        sort(s3.begin(), s3.end(), less<char>());
        s1.clear();
        int len2, len3;
        len2 = s2.length(), len3 = s3.length();
        for (i = 0, j = 0; i < len2 && j < len3; i++, j++)
        {
            s1.push_back(s2[i]);
            s1.push_back(s3[j]);
        }
        if (i < len2)
            s1.push_back(s2[i]);
        len1 = s1.length();
        for (i = 0; i < len1; i++)
            if (isdigit(s1[i]) || (s1[i] >= 'a' && s1[i] <= 'f') || (s1[i] >= 'A' && s1[i] <= 'F'))
                s1[i] = convert(s1[i]);
        cout << s1 << endl;
    }
}
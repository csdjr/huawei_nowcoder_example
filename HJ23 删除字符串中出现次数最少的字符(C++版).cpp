#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

int main()
{
    string s;
    char flag[256];
    while (getline(cin, s) && s.length())
    {
        memset(flag, 0, sizeof(flag));
        int len = s.length();
        int min = numeric_limits<int>::max();
        bool once = true;
        int i;
        for (i = 0; i < len; i++) //统计个数
            flag[s[i]]++;
        for (i = 0; i < 128; i++) //查找最小的个数
        {
            if (flag[i])
                min = min >= flag[i] ? flag[i] : min;
        }
        for (i = 0; i < 128; i++) //删除最小个数对应的所有字符
        {
            if (flag[i] == min)
                s.erase(remove(s.begin(), s.end(), i), s.end()); //这个stl的remove好用
        }
        cout << s << endl;
    }
}
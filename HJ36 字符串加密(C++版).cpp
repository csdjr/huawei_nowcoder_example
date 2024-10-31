#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s1, s2;
    while (getline(cin, s1) && s1.length())
    {
        int flag[128] = {0};
        int i;
        transform(s1.begin(), s1.end(), s1.begin(), ::tolower); //全部转为小写,注意::tolower的::必须要
        //提取不重复的字母
        int len = s1.length();
        for (i = 0; i < len; i++)
        {
            if (flag[s1[i]] == 0)
            {
                s2.push_back(s1[i]);
                flag[s1[i]] = 1;
            }
        }
        //拼接剩下的字母
        for (char c = 'a'; c <= 'z'; c++)
            if (flag[c] == 0)
                s2.push_back(c);
        //输入并加密输出
        getline(cin, s1);
        len = s1.length();
        for (i = 0; i < len; i++)
        {
            if (::isalpha(s1[i]))
            {
                char s1l = ::tolower(s1[i]);
                int dis = s1[i] - s1l;
                s1[i] = s2[s1l - 'a'] + dis;
            }
        }
        cout << s1 << endl;
    }
}
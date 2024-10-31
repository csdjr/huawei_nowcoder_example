#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<string> vs;
        string s;
        int i;
        //输入
        for (i = 0; i < n; i++)
        {
            cin >> s;
            vs.push_back(s);
        }
        string s2;
        int n2;
        cin >> s2 >> n2;
        string s22 = s2;
        sort(s22.begin(), s22.end());

        //提取兄弟单词
        vector<string> vs2;
        for (i = 0; i < n; i++)
        {
            string s3 = vs[i];
            string s33 = s3;
            sort(s33.begin(), s33.end());
            if (s22 == s33 && s2 != s3) //排序后相等，但原单词不等，才是兄弟单词
                vs2.push_back(s3);
        }

        //输出
        sort(vs2.begin(), vs2.end());
        cout << vs2.size() << endl;
        if (n2 <= vs2.size())
        {
            cout << vs2[n2 - 1] << endl;
        }
    }
}

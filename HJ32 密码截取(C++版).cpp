#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        int len = s.length();
        bool dp[2505][2505] = {0};
        int i, j;
        int max = 0;
        for (i = 1; i <= len; i++)
            for (j = 0; j + i - 1 < len; j++)
            {
                dp[j][j + i - 1] = (i == 1) || ((i == 2 || dp[j + 1][j + i - 2]) && s[j] == s[j + i - 1]);
                if (dp[j][j + i - 1])
                {
                    if (max < i)
                        max = i;
                }
            }
        cout << max << endl;
    }
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s1, s2;
    while (getline(cin, s1) && s1.length())
    {
        getline(cin, s2);
        int len1 = s1.length();
        int len2 = s2.length();

        int i, j;
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (i = 0; i <= len1; i++)
            dp[i][0] = i;
        for (j = 0; j <= len2; j++)
            dp[0][j] = j;
        for (i = 1; i <= len1; i++)
            for (j = 1; j <= len2; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i-1][j])) + 1;
            }
        cout << dp[len1][len2] << endl;
    }
}
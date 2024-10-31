#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> v;
        int i, j;
        for (i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        vector<int> dp1(n, 1);
        for (i = 0; i < n; i++)
            for (j = 0; j < i; j++)
            {
                if (v[i] > v[j] && dp1[i] < dp1[j] + 1)
                    dp1[i] = dp1[j] + 1;
            }
        vector<int> dp2(n, 1);
        for (i = n - 1; i >= 0; i--)
            for (j = n - 1; j > i; j--)
            {
                if (v[i] > v[j] && dp2[i] < dp2[j] + 1)
                    dp2[i] = dp2[j] + 1;
            }
        int max = 0;
        for (i = 0; i < n; i++)
        {
            dp1[i] += dp2[i];
            if (dp1[i] > max)
                max = dp1[i];
        }
        cout << n - max + 1 << endl;
    }
}
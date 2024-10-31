#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int m[11];
    int x[11];
    while (cin >> n)
    {
        //输入
        int i, j, k;
        for (i = 0; i < n; i++)
        {
            cin >> k;
            m[i] = k;
        }
        for (i = 0; i < n; i++)
        {
            cin >> k;
            x[i] = k;
        }

        //计算最大重量
        int max = 0;
        for (i = 0; i < n; i++)
            max += m[i] * x[i];
        vector<bool> w(max + 1, false);

        //动态规划
        w[0] = true;
        for (i = 0; i < n; i++)
            for (j = max; j >= 0; j--)
            {
                if (w[j] == true)
                {
                    for (k = 1;
                         k <= x[i] && (j + k * m[i] <= max);
                         k++)
                    {
                        w[j + k * m[i]] = true;
                    }
                }
            }

        int count = 0;
        for (i = 0; i <= max; i++)
            if (w[i] == true)
                count++;

        cout << count << endl;
    }
}
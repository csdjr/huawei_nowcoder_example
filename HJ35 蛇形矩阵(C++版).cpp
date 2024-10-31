#include <iostream>

using namespace std;

int main()
{
    int n;

    while (cin >> n)
    {
        //申请空间
        int **m = (int **)malloc(n * sizeof(int *));
        int i, j, k;
        for (i = 0; i < n; i++)
            m[i] = (int *)malloc((n - i) * sizeof(int));
        //赋值
        int index = 1;
        for (i = 0; i < n; i++)
            for (j = 0, k = i; j <= i; k--, j++)
                m[k][j] = index++;
        //打印
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n - i; j++)
                cout << m[i][j] << " ";
            cout << endl;
        }
        //释放空间
        for (i = 0; i < n; i++)
            free(m[i]);
        free(m);
    }
}
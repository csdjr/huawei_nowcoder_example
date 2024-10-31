#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int a[100][100];
    int n;
    int i, j, k;
    int x;
    while (scanf("%d", &n) != EOF)
    {
        x = 1;
        for (i = 0; i < n; i++)
        {
            k = i;
            j = 0;
            while (j <= i) //斜角赋值
                a[k--][j++] = x++;
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n - i; j++)
                printf("%d ", a[i][j]);
            printf("\n");
        }
    }
}
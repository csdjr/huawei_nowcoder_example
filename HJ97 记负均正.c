#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n1, n2, n3, n5;
    long int n4;
    int i;
    while (scanf("%d", &n1) != EOF)
    {
        n3 = 0;
        n4 = 0;
        n5 = 0;
        for (i = 0; i < n1; i++)
        {
            scanf("%d", &n2);
            if (n2 < 0)
                n3++;
            else if(n2>0)
            {
                n4 = n4 + n2;
                n5++;
            }
        }
        if (n5 == 0)
            printf("%d %.1f\n", n3, 0);
        else
            printf("%d %.1f\n", n3, n4 * 1.0 / n5);
    }
}


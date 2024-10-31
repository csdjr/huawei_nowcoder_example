#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int n1, n2;
    while (scanf("%d", &n1) != EOF)
    {
        n2 = 0;
        while (n1 > 0)
        {
            if (n1 % 2 == 1)
                n2++;
            n1 = n1 / 2;
        }
        printf("%d\n",n2);
    }
}
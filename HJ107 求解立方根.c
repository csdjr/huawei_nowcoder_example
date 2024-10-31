#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    double n1;
    while(scanf("%lf",&n1)!=EOF)
    {
        printf("%.1f\n",pow(n1,1*1.0/3));
    }
}

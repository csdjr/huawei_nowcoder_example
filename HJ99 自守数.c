#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int isZSS(int figure)
{
    int num1 = figure*figure;
    int i=0;
    int num2=1;
    int num = figure;
    while(num>0)
    {
        num=num/10;
        i++;
    }
    
    while (i>0) {
        num2=num2*10;
        i--;
    }
    
    if((num1 % num2) == figure)
        return 1;
    else
        return 0;
}

int main()
{
    int num;
    int i;
    int count;
    
    while(scanf("%d",&num)!=EOF)
    {
        if(num>0)
        {    count =1;
            for(i=1;i<=num;i++)
            {
                if(isZSS(i))
                    count++;
            }
        }
        else
            count =1;
        printf("%d\n",count);
    }
}

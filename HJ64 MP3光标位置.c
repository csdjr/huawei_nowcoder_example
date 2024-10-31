#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int n;
    int start,end,select;
    char str[5000];
    int len,i;
    while (scanf("%d %s", &n, str) != EOF)
    {
        len = strlen(str);

        select = 1;
        start = 1;
        if (n < 4)
            end = n;
        else
            end = 4;

        for (i = 0; i < len; i++)
        {
            if (str[i] == 'U')
            {
                //当前选中
                if (select == 1)
                {
                    select = n;
                    if(n>4)
                    {
                        start = n - 3;
                        end = n; 
                    }
                }
                else
                {
                    select = select - 1;
                    if (select < start)
                    {
                        start = select;
                        end = start + 3;  
                    }
                }
            }
            else if (str[i] == 'D')
            {
                //当前选中
                if (select == n)
                {
                    select = 1;
                    if (n > 4)
                    {
                        start = 1;
                        end = 4;
                    }
                }
                else
                {
                    select = select + 1;
                    if (select > end)
                    {
                        end = select;
                        start = end - 3;
                    }
                }
            }
            else
                continue;
        }
        for (i = start; i <= end; i++)
        {
            printf("%d", i);
            if (i != end)
                printf(" ");
            else
                printf("\n");
        }
        printf("%d\n",select);
    }
}

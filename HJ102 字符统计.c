#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main()
{
    int  count[128];
    char str[1000];
  
    int len, i, j, tmp;
    int max, index;

    while (scanf("%s",str)!=EOF)
    {
        memset(count, 0, sizeof(count));
        len = strlen(str);
        max = 0;
        for (i = 0; i < len; i++)
        {  
                count[str[i]]++;       
        }
        for (j = 0; j < 128; i++)
        {
            for (i = 0; i < 128; i++)
            {
                if (count[i] > max)
                {
                    max = count[i];
                    index = i;
                }
            }
            if (max != 0)
            {
                printf("%c", index);
                max = 0;
                count[index] = 0;
            }
            else
            {
                printf("\n");
                break;
            }
        }
    }
}
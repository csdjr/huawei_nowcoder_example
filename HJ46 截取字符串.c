#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[5000];
    int len;
    int k;
    while (gets(str))
    {
        scanf("%d", &k);
        len = strlen(str);

        if (k < 0 || k > len)
            printf("");
        else
        {
            str[k] = '\0';
            printf("%s\n", str);
        }
    }
}
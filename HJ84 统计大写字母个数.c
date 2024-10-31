#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str[5000];
	int i;
	int len;
	int n;

	while (gets(str))
	{
		n = 0;

		len = strlen(str);

		for(i=0;i<len;i++)
			if (isupper(str[i]))
			{
				n++;
			}
		printf("%d\n",n);
	}
}
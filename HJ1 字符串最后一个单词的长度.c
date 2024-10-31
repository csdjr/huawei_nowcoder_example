#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str[5000];
	int len;
	int i;
	int count;

	while (gets(str))
	{
		len = strlen(str);
		for (i = len - 1; i >= 0; i--)
		{
			count = 0;
			if (isalpha(str[i]))
			{
				while (i >= 0 && isalpha(str[i--]))
					count++;
				break;
			}
		}
		printf("%d\n", count);
	}
}
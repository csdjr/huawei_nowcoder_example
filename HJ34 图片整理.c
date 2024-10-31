#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char str[1025], c;
	int len;
	while (scanf("%s", str) != EOF)
	{
		len = strlen(str);
		for (int i = 0; i < len - 1; i++)
			for (int j = 0; j < len - 1 - i; j++)
			{
				if (str[j] > str[j + 1])
				{
					c = str[j];
					str[j] = str[j + 1];
					str[j + 1] = c;
				}
			}
		printf("%s\n", str);
	}
}
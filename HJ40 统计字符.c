#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str[5000];
	int len;
	int i;
	int n1, n2, n3, n4;
	while (gets(str))
	{
		n1 = 0;
		n2 = 0;
		n3 = 0;
		n4 = 0;
		len = strlen(str);
		for (i = 0; i < len; i++)
		{
			if (isalpha(str[i]))
				n1++;
			else if (str[i] == ' ')
				n2++;
			else if (isdigit(str[i]))
				n3++;
			else
				n4++;
		}
		printf("%d\n%d\n%d\n%d\n", n1, n2, n3, n4);
	}
}
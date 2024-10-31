#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int n;
	char str[5000];
	int i,j;
	int len;
	int max,start;
	int count;
	while (scanf("%s %d", str, &n) != EOF)
	{
		len = strlen(str);
		max = 0;
		start = 0;
		for (i = 0; i + n <= len; i++)
		{
			count = 0;
			for (j = i; j < i + n; j++)
			{
				if (str[j] == 'G' || str[j] == 'C')
					count++;
			}
			if (max < count)
			{
				max = count;
				start = i;
			}
		}
		str[start + n] = '\0';
		printf("%s\n",str+start);
	}
}
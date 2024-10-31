#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	char str[5000];
	int len;
	int flag[128];
	int i;
	int count;
	while (gets(str))
	{
		memset(flag, 0, sizeof(flag));
		count = 0;

		len = strlen(str);
		for (i = 0; i < len; i++)
			flag[str[i]]++;

		for (i = 0; i < 128; i++)
			if (flag[i] > 0)
				count++;
		printf("%d\n",count);

	}
}
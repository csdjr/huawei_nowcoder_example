#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int n1, n2;
	int i;
	int flag[1001];

	while (scanf("%d", &n1) != EOF)
	{
		memset(flag,0,sizeof(flag));

		for (i = 0; i < n1; i++)
		{
			scanf("%d",&n2);
			flag[n2]++;
		}

		for (i = 0; i < 1001; i++)
		{
			if (flag[i] != 0)
				printf("%d\n",i);
		}
	}
}

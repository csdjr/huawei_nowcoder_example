#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n1, n2,n3;
	int flag[10];

	while (scanf("%d", &n1) != EOF)
	{
		n3 = 0;
		memset(flag,0,sizeof(flag));

		while (n1 != 0)
		{
			n2 = n1 % 10;
			if (flag[n2] == 0)
			{
				n3 = n3 * 10 + n2;
			}
			flag[n2]++;
			n1 = n1 / 10;
		}
		printf("%d\n",n3);
	}
}
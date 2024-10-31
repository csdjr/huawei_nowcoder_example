#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main()
{
	int n1, n2;
	int num[5000];
	int i, j;
	int len;
	int temp;

	while (scanf("%d", &n1) != EOF)
	{
		for (i = 0; i < n1; i++)
			scanf("%d",&num[i]);
		scanf("%d", &n2);
		for (i = 0; i < n2; i++)
			scanf("%d", &num[n1+i]);

		len = n1 + n2;
		for(i=0;i<len-1;i++)
			for (j = 0; j < len - 1 - i; j++)
			{
				if (num[j] > num[j + 1])
				{
					temp = num[j];
					num[j] = num[j + 1];
					num[j + 1] = temp;
				}
			}

		for (i = 0; i < len-1; i++)
		{
			if (num[i] == num[i + 1])
			{
				for (j = i + 1; j < len-1; j++)
					num[j] = num[j + 1];
				len--;
			}
		}

		for (i = 0; i < len; i++)
			printf("%d",num[i]);
		printf("\n");
		
	}
}
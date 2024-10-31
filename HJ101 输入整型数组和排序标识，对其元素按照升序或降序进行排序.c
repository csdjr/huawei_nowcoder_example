#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
	int n1,n2;
	int num[5000];
	int i, j;
	int temp;

	while (scanf("%d",&n1)!=EOF)
	{
		for (i = 0; i < n1; i++)
			scanf("%d",&num[i]);
		scanf("%d",&n2);

		for(i=0;i<n1-1;i++)
			for (j = 0; j < n1 - 1 - i; j++)
			{
				if (n2 == 0)
				{
					if (num[j] > num[j + 1])
					{
						temp = num[j];
						num[j] = num[j + 1];
						num[j + 1] = temp;
					}
				}
				else
				{
					if (num[j] < num[j + 1])
					{
						temp = num[j];
						num[j] = num[j + 1];
						num[j + 1] = temp;
					}
				}
			}
		for (i = 0; i < n1; i++)
			printf("%d ",num[i]);
		printf("\n");
	}
	
}
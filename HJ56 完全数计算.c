#include <stdlib.h>
#include <stdio.h>


int func(int n)
{
	int i;
	int n1 = 0;
	if (n <= 5)
		return 0;
	for (i = 1; i <= n/2; i++)
	{
		if (n % i == 0)
			n1 = n1 + i;
	}
	if (n1 == n)
		return 1;
	else
		return 0;
}


int main()
{
	int n1;
	int i;
	int n2;
	while (scanf("%d", &n1)!= EOF)
	{
		n2 = 0;

		for (i = 1; i <= n1; i++)
		{
			n2 = n2 + func(i);
		}

		printf("%d\n",n2);
	}
}
#include <stdio.h>
#include <stdlib.h>

int func(int m, int n)
{
	if (m == 0 || n == 1)
		return 1;
	else if (n > m)
		return func(m, m);
	else
		return func(m, n - 1) + func(m - n, n);
}


int main()
{
	int m, n;
	
	while (scanf("%d %d", &m, &n) != EOF)
	{
		printf("%d\n",func(m,n));
	}
}
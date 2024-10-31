#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n1;
	float n2;
	while (scanf("%f", &n2) != EOF)
	{
		n1 = (int)n2;
		if (n2 - n1 >= 0.5)
			n1++;
		printf("%d\n",n1);
	}
}
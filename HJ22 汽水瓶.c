#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n1,n2;

	while (scanf("%d", &n1) != EOF)
	{
        if(n1==0) return 0;
		n2 = 0;
		while (n1 /3 != 0)
		{
			n2 += n1 / 3;
			n1 = n1 % 3 + n1/3;
		}
		if (n1 == 2)
			n2++;
		printf("%d\n",n2);
	}
}
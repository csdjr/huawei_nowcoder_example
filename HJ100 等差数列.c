#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int n;
	int an;

	while (scanf("%d", &n) != EOF)
	{
		an = 2 + (n -1)* 3;
		printf("%d\n",(2+an)*n/2);
	}
}
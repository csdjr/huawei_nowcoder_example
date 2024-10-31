#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str[100];
	
	while (gets(str))
	{
		printf("%d\n",strtoul(str,NULL,16));
	}
}
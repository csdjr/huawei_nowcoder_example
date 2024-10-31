#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[1000][101];
	int n;
	int i,j;
	char tmp[101];

	while (scanf("%d", &n) != EOF)
	{
		memset(str,0,sizeof(str));

		for (i = 0; i < n; i++)
			scanf("%s", str[i]);
		
		for(i=0;i<n-1;i++)
			for(j=0;j<n-1-i;j++)
				if (strcmp(str[j], str[j + 1]) > 0)
				{
					strcpy(tmp,str[j]);
					strcpy(str[j],str[j+1]);
					strcpy(str[j+1],tmp);
				}

		for (i = 0; i < n; i++)
			printf("%s\n",str[i]);
	}
}
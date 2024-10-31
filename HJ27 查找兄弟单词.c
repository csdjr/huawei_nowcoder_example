#include <stdio.h>
#include <string.h>


int main()
{
	char str1[1000][51];
	char str2[51], tmp[51],c, str2swap[51];
	char str3[1000][51];
	int n1, n2;
	int i, j,k,len;
	int count;
	int flag1[128], flag2[128];
	while (scanf("%d", &n1) != EOF)
	{
		count = 0;
		memset(str1, 0, sizeof(str1));
		for (i = 0; i < n1; i++)
		{
			scanf("%s", str1[i]);
		}
		scanf("%s", str2);
		scanf("%d", &n2);

		for(i=0;i<n1-1;i++)
			for (j = 0; j < n1 - 1 - i; j++)
			{
				if (strcmp(str1[j], str1[j + 1]) > 0)
				{
					strcpy(tmp,str1[j]);
					strcpy(str1[j], str1[j+1]);
					strcpy(str1[j+1], tmp);
				}
			}

		strcpy(str2swap, str2);
		len = strlen(str2);
		for(i=0;i< len-1;i++)
			for (j = 0; j < len - 1 - i; j++)
			{
				if (str2swap[j] > str2swap[j + 1])
				{
					c = str2swap[j];
					str2swap[j] = str2swap[j + 1];
					str2swap[j + 1] = c;
				}
			}
		

		for (i = 0; i < n1; i++)
		{
			if (strcmp(str1[i], str2) == 0)
				continue;
			strcpy(tmp,str1[i]);
			len = strlen(tmp);
			for(j=0;j<len-1;j++)
				for (k = 0; k < len - 1 - j; k++)
				{
					if (tmp[k] > tmp[k + 1])
					{
						c = tmp[k];
						tmp[k] = tmp[k + 1];
						tmp[k + 1] = c;
					}
				}
			if (strcmp(tmp, str2swap) == 0)
			{
				strcpy(str3[count++], str1[i]);
			}
		}
	
		printf("%d\n", count);

		if(n2<=count)
			printf("%s\n", str3[n2-1]);
	}
}

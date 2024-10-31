#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void swap(char* str,int len)
{
	int i, j;
	char c;
	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
	}
}

void add(char* str1, char* str2, int len1, int len2)
{
	int i, j;
	int n1 = 0,n2;
	for (i = 0; i < len2; i++)
	{
		n2 = str1[i] - '0' + str2[i] - '0' + n1;
		str1[i] = n2 % 10 + '0';
		n1 = n2 / 10;
	}
	for (; i < len1; i++)
	{
		n2 = str1[i] - '0' + n1;
		str1[i] = n2 % 10 + '0';
		n1 = n2 / 10;
	}
	if (n1 > 0)
	{
		str1[i++] = n1 + '0';
		str1[i] = '\0';
	}
	swap(str1, i);
	printf("%s\n",str1);
}

int main()
{
	char str1[10002],str2[10002];
	int len1,len2;
	int i,j;

	while (scanf("%s %s",str1,str2)!=EOF)
    {
		len1 = strlen(str1);
		len2 = strlen(str2);
		swap(str1,len1);
		swap(str2, len2);
		if (len1 >= len2)
			add(str1, str2, len1, len2);
		else
			add(str2, str1, len2, len1);
	}
}
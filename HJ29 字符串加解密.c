#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char jiami(char c)
{
	if (isalpha(c))
	{
		if (c == 'z') c = 'a';
		else if (c == 'Z') c = 'A';
		else c = c + 1;
		c = isupper(c) ? tolower(c) : toupper(c);
		return c;
	}
	if (isdigit(c))
	{
		if (c == '9') c = '0';
		else c = c + 1;
		return c;
	}
}

char jiemi(char c)
{
	if (isalpha(c))
	{
		if (c == 'a') c = 'z';
		else if (c == 'A') c = 'Z';
		else c = c - 1;
		c = isupper(c) ? tolower(c) : toupper(c);
		return c;
	}
	if (isdigit(c))
	{
		if (c == '0') c = '9';
		else c = c - 1;
		return c;
	}
}

int main()
{
	char str1[1000], str2[1000];
	int len1,len2;
	int i;
	while (scanf("%s %s", str1, str2) != EOF)
	{
		len1=strlen(str1);
		len2 = strlen(str2);
		for (i = 0; i < len1; i++)
		{	
			str1[i] = jiami(str1[i]);
		}
		for (i = 0; i < len2; i++)
		{
			str2[i] = jiemi(str2[i]);
		}
		printf("%s\n%s\n", str1, str2);
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char convert(char p)
{
	char one, two, three, four;
	char c;
	if (p >= '0' && p <= '9')
	{
		p = p - '0';
	}
	if ((p >= 'a' && p <= 'f'))
	{
		p = p - 'a'+10;
	}
	if ((p >= 'A' && p <= 'F'))
	{
		p = p - 'A' + 10;
	}
	c = p;
	one = c << 3; 
	one = one & 0b1000;
	c = p;
	two = c << 1; 
	two = two & 0b0100;
	c = p;
	three = c >> 1; 
	three = three & 0b0010;
	c = p;
	four = c >> 3;
	four = four & 0b0001;
	c = one | two | three | four;
	if (c >= 0 && c <= 9)
		c = c + '0';
	else
		c = c -10 + 'A';
	return c;
}


int main()
{
	char str1[1000], str2[1000],*str,c;
	int len1, len2,len;
	int i,j;
	while (scanf("%s %s",str1,str2)!=EOF)
	{
		len1 = strlen(str1);
		len2 = strlen(str2);
		len = len1 + len2;
		str = (char*)malloc(len + 1);
		str[0] = '\0';
		strcat(str,str1);
		strcat(str, str2);
		for(i=0;i<len;i=i+2)
			for (j = i + 2; j < len; j = j + 2)
				if (str[i] > str[j])
				{
					c = str[i]; str[i] = str[j]; str[j] = c;
				}
		for (i = 1; i < len; i = i + 2)
			for (j = i + 2; j < len; j = j + 2)
				if (str[i] > str[j])
				{
					c = str[i]; str[i] = str[j]; str[j] = c;
				}
		for (i = 0; i < len; i++)
		{
			if (isdigit(str[i]) || (str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F'))
				str[i] = convert(str[i]);
		}
		printf("%s\n",str);
		free(str);
	}

}
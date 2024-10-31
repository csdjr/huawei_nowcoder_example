#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char alpha2digit(char c)
{
	switch (c)
	{
	case 'a':
	case 'b':
	case 'c':
		return '2';
	case 'd':
	case 'e':
	case 'f':
		return '3';
	case 'g':
	case 'h':
	case 'i':
		return '4';
	case 'j':
	case 'k':
	case 'l':
		return '5';
	case 'm':
	case 'n':
	case 'o':
		return '6';
	case 'p':
	case 'q':
	case 'r':
	case 's':
		return '7';
	case 't':
	case 'u':
	case 'v':
		return '8';
	case 'w':
	case 'x':
	case 'y':
	case 'z':
		return '9';
	}
}

char upper2lower(char c)
{
	char x = 'a' - 'A';
	if (c == 'Z')
		return 'a';
	else
		return c + x + 1;
}

int main()
{
	char str[1000];
	int len;
	int i;
	while (gets(str))
	{
		len = strlen(str);
		for (i = 0; i < len; i++)
		{
			if (islower(str[i]))
				str[i] = alpha2digit(str[i]);
			else if(isupper(str[i]))
				str[i]= upper2lower(str[i]);
		}
		printf("%s\n",str);
	}
}
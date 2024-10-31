#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str[1000];
	int len;
	int n;
	int flag_lower;
	int flag_upper;
	int flag_num;
	int flag_word;
	int i;

	while (gets(str))
	{
		n = 0;
		flag_lower = 0;
		flag_upper = 0;
		flag_num = 0;
		flag_word = 0;

		len = strlen(str);
		
		if (len <= 4)
			n += 5;
		else if (len >= 5 && len <= 7)
			n += 10;
		else
			n += 25;

		for (i = 0; i < len; i++)
		{
			if (islower(str[i]))
				flag_lower++;
			else if (isupper(str[i]))
				flag_upper++;
			else if (isdigit(str[i]))
				flag_num++;
			else
				flag_word++;
		}

		if (flag_lower == 0 && flag_upper == 0)
			n += 0;
		else if (flag_lower == 0 && flag_upper != 0)
			n += 10;
		else if (flag_lower != 0 && flag_upper == 0)
			n += 10;
		else
			n += 20;


		if (flag_num == 0)
			n += 0;
		else if (flag_num == 1)
			n += 10;
		else
			n += 20;

		if (flag_word == 0)
			n += 0;
		else if (flag_word == 1)
			n += 10;
		else
			n += 25;

		if((flag_lower!=0 && flag_upper!=0) && flag_num!=0 && flag_word!=0)
			n += 5;
		else if((flag_lower != 0 || flag_upper != 0) && flag_num != 0 && flag_word != 0)
			n += 3;
		else if ((flag_lower != 0 || flag_upper != 0) && flag_num != 0)
			n += 2;

		if (n >= 90)
			printf("VERY_SECURE\n");
		else if (n >= 80)
			printf("SECURE\n");
		else if (n >= 70)
			printf("VERY_STRONG\n");
		else if (n >= 60)
			printf("STRONG\n");
		else if (n >= 50)
			printf("AVERAGE\n");
		else if (n >= 25)
			printf("WEAK\n");
		else
			printf("VERY_WEAK\n");
	}
}
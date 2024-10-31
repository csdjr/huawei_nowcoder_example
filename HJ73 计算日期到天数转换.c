#include <stdio.h>
#include <stdlib.h>

int month2Day(int month)
{
	month--;
	switch (month)
	{
	case 1:return 31;
	case 2:return 31+28;
	case 3:return 31 + 28+31;
	case 4:return 31 + 28 + 31+30;
	case 5:return 31 + 28 + 31 + 30+31;
	case 6:return 31 + 28 + 31 + 30 + 31+30;
	case 7:return 31 + 28 + 31 + 30 + 31 + 30+31;
	case 8:return 31 + 28 + 31 + 30 + 31 + 30 + 31+31;
	case 9:return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31+30;
	case 10:return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30+31;
	case 11:return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31+30;
	}
	return 0;
}

int isRunNian(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
		return 1;
	else
		return 0;
}




int main()
{
	int year, month, day;

	while (scanf("%d %d %d", &year, &month, &day) != EOF)
	{
		day = day + month2Day(month);
		if (month >= 3)
			day = day + isRunNian(year);

		printf("%d\n",day);
	}
}
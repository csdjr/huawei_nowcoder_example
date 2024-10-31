#include <stdio.h>
#include <math.h>


int isSuShu(int n)
{
	int i;
	for (i = 2; i <= sqrt(n); i++)
	{
		if (n % i != 0) 
			continue;
		else
			return 0;
	}
	return 1;
}

int main()
{
	int low, high;
	int num;
	while (scanf("%d", &num) != EOF)
	{
		for (low = num / 2, high = num - low; low >= 1, high < num; low--, high++)
		{
			if (isSuShu(low) && isSuShu(high))
			{
				printf("%d\n%d\n",low,high);
				break;
			}
		}

	}
}

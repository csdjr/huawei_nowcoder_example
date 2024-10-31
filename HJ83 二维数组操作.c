#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int m, n;
	int x1, y1, x2, y2;
	int x, y;
	while (scanf("%d %d", &m, &n) != EOF)
	{
		if (m <= 0 || m > 9 || n <= 0 || n > 9)
			printf("-1\n");
		else
			printf("0\n");


		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n
			|| x2 < 0 || x2 >= m || y2 < 0 || y2 >= n)
			printf("-1\n");
		else
			printf("0\n");


		scanf("%d", &x);
		if (x < 0 || x >= m || 1 + m > 9)
			printf("-1\n");
		else
			printf("0\n");


		scanf("%d", &y);
		if (y < 0 || y >= n || 1 + n > 9)
			printf("-1\n");
		else
			printf("0\n");


		scanf("%d %d", &x, &y);
		if (x < 0 || x >= m || y < 0 || y >= n)
			printf("-1\n");
		else
			printf("0\n");
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
	char name[100];
	int count;
}People;


int main()
{
	int n1, n2;
	People people[1000];
	int i,j;
	char name[100];
	int invalid;

	while (scanf("%d", &n1) != EOF)
	{
		invalid = 0;

		for (i = 0; i < n1; i++)
		{
			scanf("%s", people[i].name);
			people[i].count = 0;
		}

		scanf("%d",&n2);
		for (i = 0; i < n2; i++)
		{
			scanf("%s",name);
			for (j = 0; j < n1; j++)
				if (strcmp(name, people[j].name) == 0)
				{
					people[j].count++;
					break;
				}
			if (j >= n1)
				invalid++;
		}

		for (i = 0; i < n1; i++)
		{
			printf("%s : %d\n", people[i].name, people[i].count);
		}

		printf("Invalid : %d\n", invalid);



	}
	
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char part1[50];
	char part2[50];
}ML;

int isPiPei(char *str1, char *str2) //str1是ML的part，str2是s1 s2
{
	int i;
	int flag = 1;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 == 0 || len2 == 0)
		return 0;
	if (len2 > len1)
		return 0;
	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
		{
			flag = 0;
			break;
		}
	}
	return flag;
}


int main()
{
	ML ml[6];
	strcpy(ml[0].part1, "reset"); strcpy(ml[0].part2, "");
	strcpy(ml[1].part1, "reset"); strcpy(ml[1].part2, "board");
	strcpy(ml[2].part1, "board"); strcpy(ml[2].part2, "add");
	strcpy(ml[3].part1, "board"); strcpy(ml[3].part2, "delete");
	strcpy(ml[4].part1, "reboot"); strcpy(ml[4].part2, "backplane");
	strcpy(ml[5].part1, "backplane"); strcpy(ml[5].part2, "abort");

	char result[7][20] = {"reset what","board fault","where to add","no board at all","impossible","install first","unknown command"};

	char str[500], s1[500], s2[500];

	char* p;

	int i;
	int once;
	int index;

	while (gets(str))
	{
		//分解输入的字符串，分解成命令
		p = strtok(str, " ");
		strcpy(s1, p);
		p = strtok(NULL, " ");
		if (p != NULL)
			strcpy(s2, p);
		else
			memset(s2, 0, sizeof(s2));


		//--------------------------------
		if (s2[0] == '\0')
		{
			if (isPiPei(ml[0].part1, s1))
				printf("%s\n", result[0]);
			else
				printf("unknown command\n");
			continue;
		}

		once = 0;
		for (i = 1; i < 6; i++)
		{
			if (isPiPei(ml[i].part1, s1) && isPiPei(ml[i].part2, s2))
			{
				once++;
				index = i;
			}
		}
		if(once ==1)
			printf("%s\n", result[index]);
		else
			printf("unknown command\n");
	}
}
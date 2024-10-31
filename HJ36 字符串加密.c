#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str1[1000];
	char str2[26];
	char str3[1000];
	int len;
	int flag[26];
	int i, j;
	int index;
	while (scanf("%s %s", str1, str3) != EOF)
	{
		memset(flag, 0, sizeof(flag));
		len = strlen(str1);

		for (i = 0, j = 0; i < len; i++) //提取str1中不重复的字母
		{
			index = tolower(str1[i]) - 'a';
			if (flag[index] == 0)
			{
				str2[j++] = tolower(str1[i]);
				flag[index] = 1;
			}
		}

		for (i = 0; i < 26; i++) //按顺序补足str2中未出现的字母
		{
			if (flag[i] == 0)
				str2[j++] = 'a' + i;
		}

		len = strlen(str3);
		for (i = 0; i < len; i++)
		{
			str3[i] = str2[tolower(str3[i]) - 'a'] + (str3[i] - tolower(str3[i])); //转换为小写后对应的字母 + 原本的大小写
		}

		printf("%s\n", str3);
	}
}
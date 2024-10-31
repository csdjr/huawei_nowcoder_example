#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

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
        p = p - 'a' + 10;
    }
    if ((p >= 'A' && p <= 'F'))
    {
        p = p - 'A' + 10;
    }
    //二进制位调整
    c = p;
	one = c << 3; 
	one = one & 0b1000;
	two = c << 1; 
	two = two & 0b0100;
	three = c >> 1; 
	three = three & 0b0010;
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
    char str1[1000], str2[1000];
    char *str;
    int len1, len2;
    int i, j, k;
    char c;
    while (scanf("%s%s", str1, str2))
    {
        len1 = strlen(str1), len2 = strlen(str2);
        str = (char *)malloc(len1 + len2 + 1);
        strcat(str, str1), strcat(str, str2);
        //提取奇偶位提取字符串
        for (i = 0, j = 0, k = 0; i < len1 + len2 - 1; i = i + 2)
        {
            str1[j++] = str[i];
            if (str[i + 1] != '\0')
                str2[k++] = str[i + 1];
        }
        str1[j] = '\0', str[k] = '\0';
        //提取的字符串排序
        len1 = strlen(str1), len2 = strlen(str2);
        for (i = 0; i < len1 - 1; i++)
            for (j = 0; j < len1 - 1 - i; j++)
                if (str1[j] > str1[j + 1])
                {
                    c = str1[j];
                    str1[j] = str1[j + 1];
                    str1[j + 1] = c;
                }
        for (i = 0; i < len2 - 1; i++)
            for (j = 0; j < len2 - 1 - i; j++)
                if (str2[j] > str2[j + 1])
                {
                    c = str2[j];
                    str2[j] = str2[j + 1];
                    str2[j + 1] = c;
                }
        //根据计奇偶位，合并字符串
        for (i = 0, j = 0, k = 0; i < len1 && j < len2; i++, j++)
        {
            str[k++] = str1[i];
            str[k++] = str2[j];
        }
        while (i < len1)
            str[k++] = str1[i++];
        while (j < len2)
            str[k++] = str2[j++];
        str[k] = '\0';
        //转换
        for (i = 0; i < k; i++)
        {
            if (isdigit(str[i]) || (str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F'))
                str[i] = convert(str[i]);
        }
        cout << str << endl;
        free(str);
    }
}
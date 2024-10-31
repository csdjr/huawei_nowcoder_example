#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cctype>

using namespace std;

int valid(char *p)
{
    int len = strlen(p);
    if (len != 2 && len != 3)
        return -1;
    if (*p != 'A' && *p != 'D' && *p != 'W' && *p != 'S')
        return -1;
    if (!isdigit(*(p + 1)))
        return -1;
    if (len == 3 && !isdigit(*(p + 2)))
        return -1;
    return 1;
}

int main()
{
    int num1, num2, num3;
    char str[10005];
    char *p;
    int result;
    while (cin.getline(str, 10005))
    {
        num1 = 0, num2 = 0;
        p = strtok(str, ";");
        while (p != nullptr)
        {
            result = valid(p);
            if (result > 0)
            {
                num3 = strtoul(p + 1, nullptr, 10);
                switch (*p)
                {
                case 'A':
                    num1 = num1 - num3;
                    break;
                case 'D':
                    num1 = num1 + num3;
                    break;
                case 'S':
                    num2 = num2 - num3;
                    break;
                case 'W':
                    num2 = num2 + num3;
                    break;
                }
            }
            p = strtok(NULL, ";");
        }
        cout << num1 << "," << num2 << endl;
    }
}
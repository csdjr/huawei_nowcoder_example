#include <iostream>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        unsigned int count = 0;
        char *str = (char *)malloc(s.length() * sizeof(char) + 1);
        strcpy(str, s.c_str());
        char *p = strtok(str, ".");
        while (p != NULL)
        {
            int n = strtoul(p, NULL, 10);
            count = count * 256 + n;
            p = strtok(NULL, ".");
        }
        cout << count << endl;

        //输入数字
        cin >> count;
        //提取每一小段数字
        stack<string> sk;
        while (count > 0)
        {
            int n = count % 256;
            string s2 = to_string(n);
            sk.push(s2);
            count = count / 256;
        }
        //高位补0
        int size = sk.size();
        string s3;
        for (int i = 4; i > size; i--)
        {
            s3 = "0.";
        }
        //拼接后面的数字
        while (!sk.empty())
        {
            string s4 = sk.top();
            sk.pop();
            s3 += s4;
            if (!sk.empty())
                s3 += ".";
        }
        cout << s3 << endl;
        free(str);
    }
}
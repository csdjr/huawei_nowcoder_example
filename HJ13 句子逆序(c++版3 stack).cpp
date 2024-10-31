#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string s;
    while (getline(cin, s) && s.length())
    {
        int len = s.length();
        stack<string> sk;
        int pos1 = 0, pos2 = 0;
        string s2;
        while (pos2 != string::npos)
        {
            pos1 = s.find_first_not_of(" ", pos2);
            pos2 = s.find_first_of(" ", pos1);
            s2 = s.substr(pos1, pos2 - pos1);
            sk.push(s2);
        }
        while (!sk.empty())
        {
            s2 = sk.top(), sk.pop();
            cout << s2 << " ";
        }
        cout << endl;
    }
}
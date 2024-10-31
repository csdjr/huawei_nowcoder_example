#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    string s;
    while (getline(cin, s) && s.length())
    {
        int len = s.length();
        multiset<char> mc;
        for (int i = 0; i < len; ++i)
            mc.insert(::tolower(s[i]));
        char c;
        cin >> c;
        cout << mc.count(c) << endl;
    }
}
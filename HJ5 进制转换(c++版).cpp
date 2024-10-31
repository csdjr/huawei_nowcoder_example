#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    while (getline(cin, s) && s.length())
    {
        cout << strtoul(s.c_str(), NULL, 16) << endl;
    }
}
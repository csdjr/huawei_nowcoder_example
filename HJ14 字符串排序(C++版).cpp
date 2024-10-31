#include <iostream>
#include <string>
#include <list>
#include <functional>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int i;
        string s;
        list<string> l;
        for (i = 0; i < n; i++)
        {
            cin >> s;
            l.push_back(s);
        }
        l.sort(less<string>());
        list<string>::iterator it;
        for (it = l.begin(); it != l.end(); ++it)
        {
            cout << *it << endl;
        }
    }
}
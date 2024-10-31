#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n1;
    while (cin >> n1)
    {
        string s;
        do
        {
            int n2 = n1 % 10;
            s.push_back(n2 + '0');
            n1 = n1 / 10;
        } while (n1 > 0);
        cout << s << endl;
    }
}
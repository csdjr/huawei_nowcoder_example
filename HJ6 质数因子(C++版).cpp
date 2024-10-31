#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 2; i <= n; i++)
        {
            while (n % i == 0)
            {
                n = n / i;
                cout << i << " ";
            }
        }
        cout << endl;
    }
}
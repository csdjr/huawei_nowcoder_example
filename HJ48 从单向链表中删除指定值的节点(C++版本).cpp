#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int n1, n2;
        cin >> n1;
        list<int> l{n1};
        list<int>::iterator it;

        for (int i = 1; i < n; i++)
        {
            cin >> n1 >> n2;
            it = find(l.begin(), l.end(), n2);
            advance(it, 1);
            l.insert(it, n1);
        }

        cin >> n1;
        it = find(l.begin(), l.end(), n1);
        l.erase(it);

        for (it = l.begin(); it != l.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
}
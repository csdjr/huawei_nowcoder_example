#include <iostream>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

struct Node
{
    int index;
    int value;
    Node(int n1, int n2) : index(n1), value(n2){};
    bool operator==(const Node &node)
    {
        return index == node.index;
    }
    bool operator<=(const Node &node) const //注意这个const必须要
    {
        return index < node.index;
    }
};

int main()
{
    int n1, n2, n3;
    while (cin >> n1)
    {
        list<Node> l;
        list<Node>::iterator it;
        for (int i = 0; i < n1; i++)
        {
            cin >> n2 >> n3;
            Node node(n2, n3);
            it = find(l.begin(), l.end(), node);
            if (it != l.end())
                it->value += node.value;
            else
                l.push_back(node);
        }
        l.sort(less_equal<Node>());
        for (it = l.begin(); it != l.end(); ++it)
            cout << it->index << " " << it->value << endl;
    }
}

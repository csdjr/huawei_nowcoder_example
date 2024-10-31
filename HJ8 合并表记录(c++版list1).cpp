#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

struct Node
{
    int index;
    int value;

    Node(int a, int b) : index(a), value(b){};

    bool operator==(const Node &node)
    {
        return this->index == node.index;
    }
};

struct cmp
{
    bool operator()(Node &a, Node &b)
    {
        return a.index < b.index;
    }
};

int main()
{
    int n;
    int index, value;
    while (scanf("%d", &n) != EOF)
    {
        int i;
        list<Node> lNode;
        list<Node>::iterator it;

        //思想：先插入，再排序
        for (i = 0; i < n; i++)
        {
            scanf("%d%d", &index, &value);
            it = find(lNode.begin(), lNode.end(), Node(index, value));//查找
            if (it != lNode.end())
                it->value += value;
            else
                lNode.push_back(Node(index, value));
        }
        lNode.sort(cmp());  //排序
        for (it = lNode.begin(); it != lNode.end(); ++it)
            printf("%d %d\n", it->index, it->value);
    }
}
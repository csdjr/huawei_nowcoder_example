#include <iostream>
#include <cstdio>
#include <list>
#include <iterator>

using namespace std;

struct node
{
    int index;
    int value;

    node(int x, int y) : index(x), value(y){};
};

int main()
{
    int n;
    int index, value;
    int i;
    while (scanf("%d", &n) != EOF)
    {
        list<node> lNode;
        list<node>::iterator it;

        //思想：在插入过程中排序
        for (i = 0; i < n; i++)
        {
            scanf("%d%d", &index, &value);
            bool find = false;
            for (it = lNode.begin(); it != lNode.end(); ++it) //查找
            {
                if (it->index == index)
                {
                    find = true;
                    it->value += value;
                    break;
                }
                else if (index > it->index)
                    continue;
                else
                    break;
            }
            if (!find) //插入
                lNode.insert(it, node(index, value));
        }
        for (it = lNode.begin(); it != lNode.end(); ++it)
            printf("%d %d\n", it->index, it->value);
    }
}

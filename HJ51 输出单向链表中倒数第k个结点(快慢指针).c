#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct ListNode
{
    int m_nKey;
    ListNode *m_pNext;
    ListNode(int key = -1) : m_nKey(key), m_pNext(NULL) {}
} * ListHead;

void initList(ListHead *head)
{
    *head = new ListNode();
}

void insertListTail(ListHead head, int e)
{
    ListNode *node = new ListNode(e);
    ListNode *p1, *p2;
    p1 = head->m_pNext;
    p2 = head;
    while (p1 != NULL)
    {
        p2 = p1;
        p1 = p1->m_pNext;
    }
    p2->m_pNext = node;
}

void listFree(ListHead *head)
{
    ListNode *p1 = *head;
    ListNode *p2;
    while (p1 != NULL)
    {
        p2 = p1;
        p1 = p1->m_pNext;
        delete (p2);
    }
    *head = NULL;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int i;
        int k;
        ListHead head;
        initList(&head);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &k);
            insertListTail(head, k);
        }
        scanf("%d", &k);
        {
            ListNode *p1, *p2;
            p1 = head->m_pNext;
            p2 = p1;
            while (k-- > 0)
            {
                p1 = p1->m_pNext;
            }
            while (p1)
            {
                p2 = p2->m_pNext;
                p1 = p1->m_pNext;
            }
            printf("%d\n", p2->m_nKey);
        }
        listFree(&head);
    }
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	struct node *next;
} * ListHead, *ListNode;

void initList(ListHead *head)
{
	*head = (ListHead)malloc(sizeof(struct node));
	(*head)->next = NULL;
}

void insertList(ListHead head, int key)
{
	ListNode node = head->next;
	ListNode pre = head;
	ListNode add = NULL;
	while (node != NULL)
	{
		pre = node;
		node = node->next;
	}
	add = (ListNode)malloc(sizeof(struct node));
	add->key = key;
	add->next = NULL;
	pre->next = add;
}

void findNode(ListHead head, int index)
{
	int i = 1;
	int count = 0;
	ListNode node = head->next;
	while (node != NULL)
	{
		node = node->next;
		count++;
	}
	if (index > count || index <= 0)
	{
		printf("0\n");
		return;
	}

	index = count - index + 1;
	node = head->next;
	while (node != NULL && i < index)
	{
		node = node->next;
		i++;
	}

	printf("%d\n", node->key);
}

void freeList(ListHead *head)
{
	ListNode node = *head;
	ListNode pre = NULL;
	while (node != NULL)
	{
		pre = node;
		node = node->next;
		free(pre);
	}
	*head = NULL;
}

int main()
{
	int n;
	int i;
	int key;
	ListHead listHead;
	while (scanf("%d", &n) != EOF)
	{
		initList(&listHead);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &key);
			insertList(listHead, key);
		}
		scanf("%d", &n);
		findNode(listHead, n);
		freeList(&listHead);
	}
}
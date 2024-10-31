#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
	int key;
	struct node *next;
} * ListHead, *ListNode;

void initList(ListHead *head)
{
	(*head) = (ListHead)malloc(sizeof(struct node));
	(*head)->next = NULL;
}

void listInsert(ListHead head, int key1, int key2)
{
	ListNode node = head->next;
	ListNode pre = head;
	ListNode add = (ListNode)malloc(sizeof(struct node));
	add->key = key1;
	while (node != NULL && node->key != key2)
	{
		pre = node;
		node = node->next;
	}
	if (node != NULL)
	{
		add->next = node->next;
		node->next = add;
	}
	else
	{
		pre->next = add;
		add->next = NULL;
	}
}

void deleteNode(ListHead head, int key)
{
	ListNode node = head->next;
	ListNode pre = head;
	while (node != NULL && node->key != key)
	{
		pre = node;
		node = node->next;
	}
	if (node != NULL)
	{
		pre->next = node->next;
		free(node);
	}
}

void listShow(ListHead head)
{
	ListNode node = head->next;
	while (node != NULL)
	{
		printf("%d ", node->key);
		node = node->next;
		// if (node != NULL)
		//	printf(" ");
	}
	printf("\n");
}

void listFree(ListHead *head)
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
	ListHead listHead;
	int n;
	int n1;
	int n2, n3;
	int n4;
	int i;
	while (scanf("%d %d", &n, &n1) != EOF)
	{
		initList(&listHead);
		listInsert(listHead, n1, 0);
		for (i = 1; i < n; i++)
		{
			scanf("%d %d", &n2, &n3);
			listInsert(listHead, n2, n3);
		}

		scanf("%d", &n4);
		deleteNode(listHead, n4);

		listShow(listHead);

		listFree(&listHead);
	}
}
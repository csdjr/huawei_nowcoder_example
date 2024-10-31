#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	int index;
	int value;
	struct node* next;
}Node,*ListHead,*ListNode;

void initList(ListHead* head)
{
	(*head) = (ListHead)malloc(sizeof(Node));
	(*head)->next = NULL;
}

void insertList(ListHead head, int index, int value)
{
	ListNode node = head->next;
	ListNode pre = head;
	ListNode insertNode = NULL;
	while (node != NULL)
	{
		if (node->index == index)
		{
			node->value += value;
			return;
		}
		else if (node->index < index)
		{
			pre = node;
			node = node->next;
		}
		else
			break;
	}
	insertNode = (ListNode)malloc(sizeof(Node));
	insertNode->index = index;
	insertNode->value = value;
	pre->next = insertNode;
	insertNode->next = node;
}

void listShow(ListHead head)
{
	ListNode node = head->next;
	while (node != NULL)
	{
		printf("%d %d\n", node->index, node->value);
		node = node->next;
	}
}

void listFree(ListHead* head)
{
	ListNode node = *head;
	ListNode tmp;
	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	*head = NULL;
}



int main()
{
	int figure[1000][1000];
	int n;
	int index, value;
	int i;
	ListHead head;
	while (scanf("%d", &n) != EOF)
	{
		initList(&head);
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &index, &value);
			insertList(head,index,value);
		}
		listShow(head);
		listFree(&head);
	}
}
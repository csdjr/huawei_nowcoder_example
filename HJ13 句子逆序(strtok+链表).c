#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node
{
	char *s;
	struct node* pre;
	struct node* next;
}LISTNODE, * ListNode;

typedef struct
{
	ListNode front;
	ListNode tail;
}HEAD,*ListHead;

void initList(ListHead* head)
{
	(*head) = (ListHead)malloc(sizeof(HEAD));
	(*head)->front = NULL;
	(*head)->tail = NULL;
}

void insertListTail(ListHead head, char *s)
{
	ListNode node = (ListNode)malloc(sizeof(LISTNODE));
	int len = strlen(s);
	node->s = (char*)malloc(len + 1);
	strcpy(node->s,s);

	if (head->tail == NULL)
	{
		node->pre = NULL;
		node->next = NULL;
		head->front = node;
		head->tail = node;
	}
	else
	{
		head->tail->next = node;
		node->pre = head->tail;
		node->next = NULL;
		head->tail = node;
	}
}

void listShow(ListHead head)
{
	ListNode node = head->tail;
	while (node != NULL)
	{
		printf("%s", node->s);
		node = node->pre;
		if (node != NULL)
			printf(" ");
	}
	printf("\n");
}

void listFree(ListHead* head)
{
	ListNode node = (*head)->front;
	ListNode tmp;
	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		free(tmp->s);
		free(tmp);
	}
	free(*head);
	*head = NULL;
}


int main()
{
	char str[5000];
	int len;
	int i;
	ListHead head;
	while (gets(str))
	{
		len = strlen(str);
		char* p;

		initList(&head);

		p = strtok(str," ");
		while (p != NULL)
		{
			insertListTail(head, p);
			p = strtok(NULL, " ");
		}

		listShow(head);
		listFree(&head);
	}
}
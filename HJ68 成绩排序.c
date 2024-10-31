#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char* name;
	int score;
	struct node* next;
}*ListHead,*ListNode;

void initList(ListHead* head)
{
	(*head) = (ListHead)malloc(sizeof(struct node));
	(*head)->name = NULL;
	(*head)->score = 0;
	(*head)->next = NULL;
}

void listInsertHigh(ListHead head, ListNode insert)
{
	ListNode node = head->next;
	ListNode pre = head;

	if (node == NULL)
	{
		insert->next = NULL;
		pre->next = insert;
		return;
	}
	while (node != NULL)
	{
		if (insert->score > node->score)
		{
			insert->next = node;
			pre->next = insert;
			return;
		}
		pre = node;
		node = node->next;
	}
	insert->next = NULL;
	pre->next = insert;
}

void listInsertLow(ListHead head, ListNode insert)
{
	ListNode node = head->next;
	ListNode pre = head;

	if (node == NULL)
	{
		insert->next = NULL;
		pre->next = insert;
		return;
	}
	while (node != NULL)
	{
		if (insert->score < node->score)
		{
			insert->next = node;
			pre->next = insert;
			return;
		}
		pre = node;
		node = node->next;
	}
	insert->next = NULL;
	pre->next = insert;
}

void showList(ListHead head)
{
	ListNode node = head->next;
	while (node != NULL)
	{
		printf("%s %d\n", node->name, node->score);
		node = node->next;
	}
}

void destroyList(ListHead head)
{
	ListNode tmp;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->name);
		free(tmp);
	}
}


int main()
{
	int count, category;
	char name[100];
	int	 score;
	ListHead head;
	ListNode insert;
	while (scanf("%d %d", &count, &category) != EOF)
	{
		initList(&head);
		for(int i=0;i<count;i++)
		{
			scanf("%s %d", name, &score);
			insert = (ListNode)malloc(sizeof(struct node));
			insert->name = (char*)malloc(100);
			strcpy(insert->name, name);
			insert->score = score;
			if (category == 0)
				listInsertHigh(head, insert);
			else
				listInsertLow(head, insert);
		}
		showList(head);
		destroyList(head);
	}
}
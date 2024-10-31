#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char* str;
	struct node *pre;
	struct node *next;
}LISTNODE, * ListNode;

typedef struct
{
	ListNode first;
	ListNode tail;
	int num;
}LISTHEAD,*ListHead;

void initList(ListHead* head)
{
	*head = (ListHead)malloc(sizeof(LISTHEAD));
	(*head)->first = NULL;
	(*head)->tail = NULL;
	(*head)->num = 0;
}

void insertList(ListHead head, char* str)
{
	ListNode node = (ListNode)malloc(sizeof(LISTNODE));
	int len = strlen(str);
	
	node->str = (char*)malloc(len + 1);
	strcpy(node->str,str);
	
	if (head->first == NULL)
	{
		node->pre = NULL;
		node->next = NULL;
		head->first = node;
		head->tail = node;
	}
	else
	{
		node->pre = head->tail;
		node->next = NULL;
		head->tail->next = node;
		head->tail = node;
	}
	head->num++;
}

void listShow(ListHead head)
{
	ListNode node = head->first;
	printf("%d\n",head->num);
	while (node != NULL)
	{
		printf("%s\n", node->str);
		node = node->next;
	}
}

void listFree(ListHead head)
{
	ListNode node = head->first;
	ListNode tmp;
	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		free(tmp->str);
		free(tmp);
	}
	free(head);
}


int main()
{
	char str1[5000];
	char str2[5000];
	int i,j;
	int len;
	int flag;
	ListHead head;

	while (gets(str1))
	{
		initList(&head);

		len = strlen(str1);
		for (i = 0; i < len; i++)
		{
			j = 0;
			flag = 0;
			if (str1[i] != ' ')
			{
				while(i < len && (str1[i] != ' ' || (str1[i] == ' ' && flag == 1)))
				{
					if (str1[i] == '"')
					{
						flag++;
						i++;
						if (flag == 2)
							break;
					} 
					else
						str2[j++] = str1[i++];
				}
				str2[j] = '\0';

				insertList(head,str2);
			}
		}
		listShow(head);
		listFree(head);
	}
}
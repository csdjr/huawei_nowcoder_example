#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
	int *base;
	int *top;
} Stack;

void initStack(Stack *s)
{
	s->base = (int *)malloc(1000 * sizeof(int));
	s->top = s->base;
}

void pushStack(Stack *s, int e)
{
	*(s->top) = e;
	s->top++;
}

void popStack(Stack *s, int *e)
{
	s->top--;
	*e = *(s->top);
}

int getStackTop(Stack *s)
{
	return *(s->top - 1);
}

int isStackEmpty(Stack *s)
{
	return s->base == s->top;
}

void freeStack(Stack *s)
{
	free(s->base);
	s->base = NULL;
	s->top = NULL;
}

int isHigh(int c1, int c2)
{
	if (c1 == '(')
		return 1;
	if (c1 == '*' || c1 == '/')
		return 0;
	if (c1 == '+' || c1 == '-')
	{
		if (c2 == '+' || c2 == '-')
			return 0;
		else
			return 1;
	}
	return 0;
}

int calc(int n1, int n2, int c)
{
	switch (c)
	{
	case '+':
		return n1 + n2;
	case '-':
		return n1 - n2;
	case '*':
		return n1 * n2;
	case '/':
		return n1 / n2;
	}
	return 0;
}

int main()
{
	char str[1000];
	int len;
	int i;
	int num;
	char *p;
	Stack nums, calcs;
	int n1, n2, c;

	while (gets(str))
	{
		initStack(&nums);
		initStack(&calcs);

		len = strlen(str);
		for (i = 0; i < len; i++)
		{
			if (str[i] == '[' || str[i] == '{')
				str[i] = '(';
			else if (str[i] == ']' || str[i] == '}')
				str[i] = ')';
		}

		for (i = 0; i < len; i++)
		{
			if (isdigit(str[i]) || ((i == 0 || str[i - 1] == '(') && str[i] == '-'))
			{
				num = strtod(&str[i], &p);
				pushStack(&nums, num);
				i = p - str - 1;
				continue;
			}
			if (str[i] == '(')
			{
				pushStack(&calcs, str[i]);
				continue;
			}
			if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
			{
				if (isStackEmpty(&calcs))
				{
					pushStack(&calcs, str[i]);
					continue;
				}
				c = getStackTop(&calcs);
				if (isHigh(c, str[i]))
				{
					pushStack(&calcs, str[i]);
					continue;
				}
				else
				{
					popStack(&nums, &n2);
					popStack(&nums, &n1);
					popStack(&calcs, &c);
					n2 = calc(n1, n2, c);
					pushStack(&nums, n2);
					i--;
					continue;
				}
			}
			if (str[i] == ')')
			{
				while ((c = getStackTop(&calcs)) != '(')
				{
					popStack(&nums, &n2);
					popStack(&nums, &n1);
					popStack(&calcs, &c);
					n2 = calc(n1, n2, c);
					pushStack(&nums, n2);
				}
				popStack(&calcs, &c);
				continue;
			}
		}

		while (!isStackEmpty(&calcs))
		{
			popStack(&nums, &n2);
			popStack(&nums, &n1);
			popStack(&calcs, &c);
			n2 = calc(n1, n2, c);
			pushStack(&nums, n2);
		}
		popStack(&nums, &n2);
		printf("%d\n", n2);

		freeStack(&calcs);
		freeStack(&nums);
	}
}

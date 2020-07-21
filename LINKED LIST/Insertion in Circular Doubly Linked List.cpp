#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
}*Head;

void create(int A[], int n)
{
	struct Node *t;
	struct Node *last;
	int i;
	
	t = (struct Node *)malloc(sizeof(struct Node));
	t->data = A[0];
	t->next = t->prev = t;
	Head = last = t; 
	
	for(i=1;i<n;i++)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = A[i];
		last->next = t;
		t->prev = last;
		last = t;
		last->next = Head;
		Head->prev = last;
	}
}

void display(struct Node *p)
{
	do
	{
		printf("%d->",p->data);
		p = p->next;
	}while(p != Head);
}

void Insert(struct Node *p, int pos, int x)
{
	struct Node *t;
	int i;
	
	if(pos == 0)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = x;
		if(Head == NULL)
		{
			Head = t;
			Head->next = Head->prev = t;
		}
		else
		{
			t->next = Head;
			t->prev = Head->prev;
			Head->prev->next = t;
			Head->prev = t;
			Head = t;
		}
	}
	else
	{
		for(i=0;i<pos-1;i++)
			p = p->next;
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = x;
		t->next = p->next;
		t->prev = p;
		p->next->prev = t;
		p->next = t;
	}
}

int main()
{
	int A[] = {1,2,3,4,5};
	create(A,sizeof(A)/sizeof(int));
	Insert(Head, 5, 99);
	display(Head);
	return 0;
}

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

void Delete(struct Node *p, int index)
{
	struct Node *q;
	int i;
	
	if(index == 1)
	{
		q = p;
		Head = Head->next;
		Head->prev = q->prev;
		q->prev->next = Head;
		free(q);
	}
	else
	{
		for(i=0;i<index-1;i++)
			p = p->next;
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}
}

int main()
{
	int A[] = {1,2,3,4,5};
	create(A,sizeof(A)/sizeof(int));
	Delete(Head, 4);
	display(Head);
	printf("\n");
	
	return 0;
}

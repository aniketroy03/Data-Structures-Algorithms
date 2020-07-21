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

int main()
{
	int A[] = {1,2,3,4,5};
	create(A,sizeof(A)/sizeof(int));
	display(Head);
	printf("\n");
	
	return 0;
}

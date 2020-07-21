#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
}*first = NULL;

void create(int A[], int n)
{
	struct Node *t;
	struct Node *last;
	int i;
	
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = A[0];
	first->prev = first->next = NULL;
	last = first;
	
	for(i=1;i<n;i++)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = last->next; 							//here last->next is always NULL, hence the next of newly created node is always NULL
		t->prev = last;									//previous of newly create node points to the previus node
		last->next = t;									//previous node's next (which was NULL) now points to the newly created node
		last = t;										//last is updated to point on newly created node which will help in repeating the same procedure after every iteration
	}
}

void Display(struct Node *p)
{
	while(p)
	{
		printf("%d->",p->data);
		p = p->next;
	}
}

int Length(struct Node *p)
{
	int len = 0;
	while(p)
	{
		len++;
		p = p->next;
	}
	return len;
}


void Insert(struct Node *p, int index, int x)
{
	struct Node *t;
	int i;
	
	if(index < 0 && index > Length(p))
		return;
		
	if(index == 0)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = x;
		t->prev = NULL;
		t->next = first;
		first->prev = t;
		first = t;
	}
	else
	{
		for(i=0;i<index-1;i++)
			p = p->next;
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = x;
		
		t->prev = p;
		t->next = p->next;
		if(p->next)							//checks if there is any next node //specially for insertion after the last node
			p->next->prev = t;
		p->next = t;
	}
}
int main()
{
	int A[] = {1,2,3,4,5};
	
	create(A,sizeof(A)/sizeof(int));
	Insert(first, 5, 99);
	Display(first);
	
	
	return 0;
}

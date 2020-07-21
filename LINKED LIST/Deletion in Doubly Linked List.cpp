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

void Delete(struct Node *p, int index)
{
	struct Node *q;
	int i;
	
	if(index < 1 || index > Length(p))
		return;
		
	if(index == 1)
	{
		first = first->next;
		if(first)								//If node is present
			first->prev = NULL;
			
		free(p);
	}
	else
	{
		for(i=0;i<index-1;i++)
			p = p->next;
		p->prev->next = p->next;
		if(p->next)								//If p->next is present or not //special condition for the last node
			p->next->prev = p->prev;
		
		free(p);
	}
}

int main()
{
	int A[] = {1,2,3,4,5};
	
	create(A,sizeof(A)/sizeof(int));
	
	Delete(first, 5);
	Display(first);
	
	
	return 0;
}

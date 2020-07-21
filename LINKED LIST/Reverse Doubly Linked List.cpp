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

void Reverse(struct Node *p)
{
	struct Node *t;								//temporary pointer for swapping nodes
	while(p)
	{
		t = p->next;							//the next of a node is stored in a temporary pointer     /*****************************
		p->next = p->prev;						//next is changed to point on previous					   SWAPPING OF POINTERS OR LINKS
		p->prev = t;							//previous is changed to the temporary pointer			   *****************************/
		p = p->prev;
		if(p && p->next == NULL)				//checks if p is a valid address or not and its next is pointing to NULL or not	
			first = p;
	}
}

int main()
{
	int A[] = {1,2,3,4,5,6};
	
	create(A,sizeof(A)/sizeof(int));
	
	Reverse(first);
	Display(first);
	
	
	return 0;
}

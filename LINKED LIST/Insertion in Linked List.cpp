#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first = NULL;					//Global Pointer //Can be directly accessed and can pass as parameter

void create(int A[], int n)
{
	int i;
	struct Node *t;				//temporary node help in creating new node
	struct Node *last;			//pointer to point at last node //helps in adding new node in end of linked list
	
	first = (struct Node *)malloc(sizeof(struct Node));        //creates space for first node in heap
	first->data = A[0];										  //data part is assigned as first element of the array
	first->next = NULL;										  //next pointer points to NULL only
	last = first;										     //last pointer made to point at first node //helps in linking nodes [V. Imp]
	
	for(i=1; i<n; i++)										//starting from 1 as already 0th element is created
	{
		t = (struct Node *)malloc(sizeof(struct Node));     //everytime a new space is created in heap for a new node represented by t
		t->data = A[i];										//data part is assigned according to array element
		t->next = NULL;										//everytime the node is created its next points to NULL as there is no node after that
		last->next = t;										//helps in linking the previous node with the newly created node
		last = t;											//last refreshes its pointer to the newly created node that will help again in linking a newly created node in next iteration
	}
	
}

void display(struct Node *p)
{
	while(p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
}

void Insert(struct Node *p, int index, int x)
{
	struct Node *t;                                   //for new node that is to be inserted
	int i;
	
	/*
	if(index < 0 || index > count(p))                 //to check if index is valid or not //count is a function which counts the length of the linked list (used in previous programs)
		return;
	*/
	
	t = (struct Node *)malloc(sizeof(struct Node));     //creates space for the new node in the HEAP
	t->data = x;										//assigns the data part of the node
	
	if(index == 0)										//for insertion at the very beginning
	{
		t->next = first;
		first = t;	
	}
	else												//for insertion after a given node
	{
		for(i=0;i<index-1;i++)
			p = p->next;
		t->next = p->next;
		p->next = t;
	}
	
	
	
}

int main()
{
	int A[] = {3,5,7,10,15};
	
	create(A,sizeof(A)/sizeof(int));
	
	Insert(first, 5, 99);
	display(first);
	
	return 0;
}

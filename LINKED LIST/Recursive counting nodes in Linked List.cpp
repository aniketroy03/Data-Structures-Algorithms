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

//counting nodes in linked list
int count(struct Node *p)
{
	int c = 0;                                             //flag variable for counting nodes
	while(p)
	{
		c++;
		p = p->next;
	}
	return c;
}

//Recursive function for counting nodes in linked list
int RCount(struct Node *p)
{
	if(p == NULL)
		return 0;
	else
		return RCount(p->next) + 1;
}

int main()
{
	int A[] = {3,5,7,10,15,20};
	
	create(A,sizeof(A)/sizeof(int));
	display(first);
	printf("\nNo. of nodes are: %d", RCount(first));			//calling recursive function for counting
	
	return 0;
}

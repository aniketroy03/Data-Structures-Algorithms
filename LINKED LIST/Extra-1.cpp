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

int f(struct Node *p)
{

		if(p->next == NULL)
			return 1;
		else if(p->data < p->next->data)
			f(p->next);
		else
			return 0;

}

int f2(struct Node *p)
{
	return(p->next == NULL || (p->data < p->next->data) && f2(p->next));    //same as the above procedure //new to learn for me :)
}


int main()
{
	int A[] = {3,5,7,95,15};
	
	create(A,sizeof(A)/sizeof(int));
	printf("%d",f2(first));
	
	return 0;
}

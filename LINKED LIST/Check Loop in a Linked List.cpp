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

int checkLoop(struct Node *f)
{
	struct Node *p, *q;
	p = q = f;
	
	do
	{
		p = p->next;
		q = q->next;
		if(q != NULL)									//checks if q has become null or not. If not, increment it again such that it will be ahead of the p pointer
			q = q->next;
		
		if(p == q)										//if p and q pointer meet each other at same address at some time 
			return 1;
	}
	while(p && q && p != q);							//checks if p and q has become null or not and p and q has become equal
	return -1;
}

int main()
{
	struct Node *t1, *t2;								//the t1 and t2 pointers will help in making a loop within the linked list 
	int A[] = {3,5,7,10,15};
	
	create(A,sizeof(A)/sizeof(int));
	//display(first);
	
	t1 = first->next->next->next;
	t2 = first->next->next->next->next;
	t2->next = t1;										//***creating the loop link***
	
	printf("%d ",checkLoop(first));
	
	return 0;
}

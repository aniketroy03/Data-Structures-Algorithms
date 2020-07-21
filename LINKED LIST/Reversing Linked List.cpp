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

void Reverse1(struct Node *p)
{
	int *A,i=0;										//Auxilliray array for copying the elements from the linked list whose size equals to the length of the linked list
	struct Node *q = p;								//using q for traversing instead of p since p is the first node here :)
	A = (int *)malloc(sizeof(int) * count(p));                  //Array memory is allocated inside the HEAP //count function returns the length of the linked list 
	
	while(q != NULL)
	{
		A[i] = q->data;								//copying elements of linked list in array
		q = q->next;
		i++;
	}
	
	q = p;											//making q node as the first node
	i--;											//decrementing i so that it points to the last index of the array after getting out of the array by the action of the previous loop
	
	while(q != NULL)
	{
		q->data = A[i];							//copying elements of the array to the linked list
		q = q->next;
		i--;
	}
}

void Reverse2(struct Node *p)
{
	struct Node *q = NULL, *r = NULL;
	
	while(p != NULL)
	{
		r = q;                    //sliding pointers concept
		q = p;
		p = p->next;
		q->next = r;
	}
	first = q;
}

void RecursiveReverse(struct Node *q, struct Node *p)
{
	if(p)
	{
		RecursiveReverse(p, p->next);
		p->next = q;								//p->next changes to q on returning time
	}
	else
		first = q;
}

int main()
{
	int A[] = {1,2,3,4,5,6,7,8,9,10};

	create(A,sizeof(A)/sizeof(int));
	
	RecursiveReverse(NULL, first);
	display(first);

	return 0;
}

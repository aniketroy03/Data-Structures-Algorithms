#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*Head;

void create(int A[], int n)
{
	int i;
	struct Node *t;                           //temporary pointer to create node in the Heap
	struct Node *last;                        //last pointer will help in linking the previous node to latest created node //helps in linking node
	
	Head = (struct Node *)malloc(sizeof(struct Node));
	Head->data = A[0];
	Head->next = Head;								//next of first node is pointing on itself creating a loop //hence it is a circular linked list
	last = Head;
	
	for(i=1;i<n;i++)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = last->next;						//here last->next is always the Head //everytime the newly created node will point to the Head node
		last->next = t; 							//previous node now links to the newly created node
		last = t;									//last pointer is updated on the newly create node
	}
}

void Display(struct Node *h)
{
	do
	{
		printf("%d->", h->data);
		h = h->next;
		
		/*if(h == Head)							//If we use while(h) then this condition will help in terminating the loop once h becomes equal to head again
			break;*/
			
	}while(h != Head);
}

void RecursiveDisplay(struct Node *h)
{
	static int flag = 0;					//this static variable will let us know if h and Head are equal for the first time or the second time //it is used just for terminating the loop
	
	if(h != Head || flag==0)
	{
		flag = 1;
		printf("%d->",h->data);
		RecursiveDisplay(h->next);
	}
	flag = 0;
}

int main()
{
	int A[] = {1,2,3,4,5};
	
	create(A,sizeof(A)/sizeof(int));
	Display(Head);
	printf("\n");
	
	printf("%d",(Head->next->next->next->next->next)->data);
	
	printf("\n");
	RecursiveDisplay(Head);
	
	return 0;
}

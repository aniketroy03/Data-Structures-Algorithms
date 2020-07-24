#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
}*top = NULL;						//initialising top pointer to NULL //indicates no elements inside the stack

void push(int x)
{
	struct Node *t;												//temporary pointer to create a new node in HEAP
	t = (struct Node *)malloc(sizeof(struct Node));				//allocating memory for the newly create node in HEAP
	
	if(t == NULL)												//if no more nodes can be created it means t is NULL hence HEAP is full //StackOverflow condition
		printf("Stack Overflow\n");
	else
	{
		t->data = x;											//t->data is assigned
		t->next = top;											//t->next points to the top
		top = t;												//now top points on the newly created node
	}
}

int pop()
{
	int x = -1;
	struct Node *t;									//temporary pointer to point on the node that is to be deleted
	
	if(top == NULL)
		printf("Stack Underflow\n");
	else
	{
		t = top;									//t points to the top node which is to be popped out
		top = top->next;							//top points to its next as the previous node now will be popped out	
		x = t->data;								//x assigns t->data
		free(t);									//t is freed
	}
	return x;
}

void Display()
{
	struct Node *p;
	p = top;
	while(p)
	{
		printf("%d->", p->data);
		p = p->next;
	}	
	printf("\n");	
}

int peek(int pos)
{
	struct Node *p;
	p = top;
	int i;
	
	for(i=0; p && i<pos-1; i++)					//check if p is valid or not //if valid p will increment till the mentioned position
		p = p->next;
	if(p)										//if p is a valid address it will return the data of that address 
		return p->data;
	else										//if p is invalid return -1
		return -1;
}

int stackTop()
{
	if(top)
		return top->data;					//if top exists that is top is not NULL it will return its data
	return -1;	
}

int isEmpty()
{	
	return top?0:1;							//if(top) that is top is a valid address then the function will return false as 0 otherwise top is NULL hence the function will return true as 1
}

int isFull()
{
	struct Node *t;
	t = (struct Node *)malloc(sizeof(struct Node));			//node is tried to create inside HEAP to check if it creates a node or not
	int r;
	r = t?0:1;												//if t is a valid address that means the node has been successfully created inside the HEAP hence it will assign false to r as 0 otherwise it means t is NULL hence a node could not be created inside HEAP
	free(t);												//whether or not t is created it is freed from the memory
	return r;
}

int main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	Display();
	
	pop();
	Display();
	
	printf("%d peeked.\n", peek(2));
	printf("%d top element\n", stackTop());
	printf("%d isEmpty?\n", isEmpty());
	printf("%d isFull?\n", isFull());
	
	pop();
	pop();
	pop();
	printf("%d isEmpty?\n", isEmpty());
	
	return 0;
}

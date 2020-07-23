#include<stdio.h>
#include<stdlib.h>

struct Stack
{
	int size;							//size of the array representing the stack
	int top;							//top which points to the top most element in the stack
	int *S;								//pointer to an array to create the stack in the HEAP dynamically
};

void create(struct Stack *st)
{
	printf("Enter Size: ");
	scanf("%d", &st->size);									//size of the array 
	
	st->top = -1;											//top is initialised with -1 as there are no elements inside the stack
	
	st->S = (int *)malloc(st->size * sizeof(int));			//memory for the array is allocated in the HEAP of size st->size
}

void Display(struct Stack st)
{
	int i;
	
	for(i=st.top; i>=0; i--)
		printf("%d ",st.S[i]);
}

void push(struct Stack *st, int x)
{
	if(st->top == st->size - 1)					//checks if top has become size-1 or not //if it equals size-1 then stack is full
		printf("Stack Overflow\n");
	else
	{
		st->top++;								//top is incremented
		st->S[st->top] = x;						//element is inserted at S[top]
	}
}

int pop(struct Stack *st)
{
	int x = -1;									//initialising x with -1 //if stack is empty the function will return -1
	
	if(st->top == -1)
		printf("Stack Underflow\n");
	else
		x = st->S[st->top--];					//first x is assigned with S[top] and then top is decremented using top--
	
	return x;
}

int peek(struct Stack st, int index)
{
	int x = -1;								//initialising x with -1 //if index is invalid then the function will return -1
	
	if(st.top-index+1 < 0)					//condition to check for valid index   //top-index+1 : formula for accessing the position
		printf("Invalid Index");
	else
		x = st.S[st.top-index+1];			//x is assigned with the value of S[top-index+1] where top-index+1 is the formula for mapping position with the correct index
		
	return x;
}

int isEmpty(struct Stack st)				//function to check if the stack is empty or not
{
	if(st.top == -1)						//if top equals -1 it means there are no elements inside the stack
		return 1;
	return 0;
}

int isFull(struct Stack st)					//function to check if the stack is full or not
{
	return st.top == st.size - 1;   		//this return statement checks if top equals size-1 or not //if it is true it will return 1 or if it is false it will return 0 //another way of writing return statements
}

int stackTop(struct Stack st)				//function to return the top most element inside the stack
{
	if(!isEmpty(st))						//checks if the stack is empty or not using isEmpty() function 
		return st.S[st.top];                //if not then it returns the top most element in the stack S[Top]
	return -1;								//if empty it returns -1
}

int main()
{
	struct Stack st;
	
	create(&st);
	
	push(&st,10);
	push(&st,20);
	push(&st,30);
	push(&st,40);
	push(&st,50);
	
	Display(st);
	
	printf("\n");	
	printf("%d",peek(st, 5));
	
	printf("\n");	
	printf("%d",isEmpty(st));
	
	printf("\n");	
	printf("%d",isFull(st));
	
	pop(&st);
	printf("\n");	
	printf("%d",stackTop(st));
	
	
	return 0;
}

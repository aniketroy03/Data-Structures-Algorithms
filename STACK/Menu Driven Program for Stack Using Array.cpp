#include<stdio.h>
#include<stdlib.h>

struct Stack
{
	int size;
	int top;
	int *S;
};

void create(struct Stack *st)
{
	printf("Enter the size of the Stack: ");
	scanf("%d", &st->size);
	
	st->top = -1;
	
	st->S = (int *)malloc(st->size * sizeof(int));
}

int isEmpty(struct Stack *st)
{
	if(st->top == -1)
		return 1;
	return 0;
}

int isFull(struct Stack *st)
{
	return st->top == st->size - 1;
}

void Display(struct Stack *st)
{
	int i;
	for(i=st->top; i>=0; i--)
		printf("%d ", st->S[i]);
}

void push(struct Stack *st, int x)
{
	if(isFull(st))
		printf("Stack Overflow\n");
	else
	{
		st->S[++st->top] = x;
	}
}

int pop(struct Stack *st)
{
	int x = -1;								
	
	if(isEmpty(st))
		printf("Stack Underflow\n");
	else
		x = st->S[st->top--];					
	
	return x;
}

int peek(struct Stack *st, int index)
{
	int x = -1;
	if(st->top-index+1 < 0)
		printf("Invalid Index\n");
	else
		x = st->S[st->top-index+1];
		
	return x;	
}

int stackTop(struct Stack *st)
{
	if(isEmpty(st))
		return -1;
	return st->S[st->top];
}

int spaceLeft(struct Stack *st)
{
	if(st->top != st->size - 1)
		return 1;
	return 0;
}

int main()
{
	int choice = 0;
	int x;
	int returnValue;
	
	struct Stack *st;
	st = (struct Stack *)malloc(sizeof(struct Stack));
	create(st);

	while(choice != -1)
	{
		printf("\n1. push()\n");
		printf("2. pop()\n");
		printf("3. Display()\n");
		printf("4. peek()\n");
		printf("5. stackTop()\n");
		printf("6. isEmpty()\n");
		printf("7. isFull()\n");
		printf("8. spaceLeft()\n");
		printf("Enter your choice or -1 to end: \n\n");
		scanf("%d", &choice);
		
		if(choice == 1)
		{
			printf("\nEnter the value to be pushed: \n");
			scanf("%d", &x);
			push(st, x);
		}
		else if(choice == 2)
		{
			returnValue = pop(st);
			if(returnValue != -1)
				printf("\n%d is popped out\n", returnValue);
		}
		else if(choice == 3)
		{
			printf("\n");
			Display(st);
			printf("\n");
		}
		else if(choice == 4)
		{
			printf("\nEnter the index to peek: ");
			scanf("%d", &x);
			returnValue = peek(st, x);
			if(returnValue != -1)
				printf("\nThe element at %d index is %d\n", x, returnValue);
		}
		else if(choice == 5)
		{
			returnValue = stackTop(st);
			if(returnValue != -1)
				printf("\nThe topmost element is %d\n", returnValue);
			else
				printf("\nThe Stack is Empty\n");
		}
		else if(choice == 6)
		{
			if(isEmpty(st))
				printf("\nYes, the stack is Empty\n");
			else
				printf("\nNo, the stack is not Empty\n");
		}
		else if(choice == 7)
		{
			if(isFull(st))
				printf("\nYes, the stack is full\n");
			else
				printf("\nNo, the stack is not full\n");
		}
		else if(choice == 8)
		{
			if(spaceLeft(st))
				printf("\nYes, space is left inside stack\n");
			else
				printf("\nNo, there is no space left inside stack\n");
		}
		else if(choice == -1)
		{
			printf("\nExited. See you again...\n");
		}
		else
		{
			printf("\nInvalid choice. Enter Again...\n");
		}
	}
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	char data;
	struct Node *next;
}*top = NULL;						

void push(char x)
{
	struct Node *t;												
	t = (struct Node *)malloc(sizeof(struct Node));			
	
	if(t == NULL)												
		printf("Stack Overflow\n");
	else
	{
		t->data = x;											
		t->next = top;										
		top = t;											
	}
}

char pop()
{
	char x = -1;
	struct Node *t;								
	
	if(top == NULL)
		printf("Stack Underflow\n");
	else
	{
		t = top;								
		top = top->next;						
		x = t->data;							
		free(t);								
	}
	return x;
}

int isBalanced(char *exp)
{
	int i;
	
	for(i=0; exp[i] != '\0'; i++)				//for loop to scan through the entire expression
	{
		if(exp[i] == '(')				//if '(' appears in the expression push exp[i] ie '(' inside the stack
			push(exp[i]);
		else if(exp[i] == ')')				//if ')' appears in the expression 
		{
			if(top == NULL)				//if ')' appears but the stack is empty which means there is extra ')' in the expression
				return 0;			//return false //parenthesis are not balanced
			else					//if ')' appears and inside the stack '(' is present
				pop();				//pop the element out from the stack that is '(' is popped from the stack
		}
		else
			continue;
	}
	if(top == NULL)						//if after complete scan of the expression the stack is empty it means '(' and ')' has balanced each other
		return 1;					//return true //parenthesis are balanced
	return 0;						//Else return false //parenthesis are not balanced
}

int main()
{
	char *exp = "((a+b)*(c-d))";
	int returnValue;
	returnValue = isBalanced(exp);
	if(returnValue == 1)
		printf("Parenthesis are balanced");
	else
		printf("Parenthesis are not balanced");
	
	return 0;
}

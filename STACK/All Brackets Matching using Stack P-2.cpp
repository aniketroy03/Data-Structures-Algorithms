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
	
	for(i=0; exp[i] != '\0'; i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			push(exp[i]);
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(top == NULL)				//stack empty condition //important condition //if any closing bracket appears but the stack is empty which means there is no opening brackets inside the stack hence the closing bracket is extra or unneccessary 
				return 0;
			else
			{
				if( (exp[i]<50 && top->data<50) || ( (exp[i]>=50 && exp[i]<=100) && (top->data>=50 && top->data<=100) ) || (exp[i]>100 && top->data>100) )
					pop();
				else
					return 0;
			}
		}
		else
			continue;
	}
	if(top == NULL)
		return 1;
	return 0;
}

int main()
{
	char *exp = "{([a+b]*[c-d])/e}";
	int returnValue;
	returnValue = isBalanced(exp);
	if(returnValue == 1)
		printf("Parenthesis are balanced");
	else
		printf("Parenthesis are not balanced");
	
	return 0;
}

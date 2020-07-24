#include<iostream>
#include<stdlib.h>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

class Stack
{
	private:
		Node *top;					//top is a pointer of type Node  //"Node is a structure or class" which contains data and a pointer of type node(self referential) //helps to form a linked list 
	public:
		Stack()						//default constructor //non-parameterised constructor //since there is no size in the stack top is NULL
		{
			top = NULL;
		}
		~Stack();					//Destructor
		void push(int x);			//function to push elements inside the stack
		int pop();					//function to pop elements from the stack
		void Display();				//function to display elements inside the stack
};

void Stack::push(int x)
{
	Node *t = new Node;				//temporary pointer t is created to allocate memory space inside the HEAP
	if(t == NULL)
		printf("Stack Overflow\n");
	else
	{
		t->data = x;				/*Procedure for push*/
		t->next = top;
		top = t;
	}
}

int Stack::pop()
{
	int x = -1;
	if(top == NULL)
		cout<<"Stack Underflow"<<endl;
	else
	{
		x = top->data;
		Node *t = top;						//t is temp pointer to point on top so that it could be later deleted
		top = top->next;					/*procedure for pop*/
		delete t;
	}
	return x;
}

void Stack::Display()
{
	Node *p;
	p = top;
	while(p)
	{
		cout<<p->data<<"->";
		p = p->next;
	}
	cout<<endl;
}

Stack::~Stack() 
{
    Node* p = top;
    while (top)
	{
        top = top->next;
        delete p;
        p = top;
    }
}

int main()
{
	Stack stk;
	stk.push(10);
	stk.push(20);
	stk.push(30);
	stk.push(40);
	stk.Display();
	stk.pop();
	stk.Display();
	stk.pop();
	stk.Display();
	stk.pop();
	stk.Display();
	stk.pop();
	stk.Display();
	stk.pop();
	return 0;
}

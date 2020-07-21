#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

class LinkedList
{
	private:
		Node *first;
	public:
		LinkedList()							//default constructor
		{
			first = NULL;
		}
		LinkedList(int A[], int n); 			//parameterized constructor
		~LinkedList();							//destructor
		
		void display();
		void insert(int index, int x);
		int Delete(int index);
		int count();
};

LinkedList::LinkedList(int A[], int n)
{
	int i;
	Node *t;													//temporary node help in creating new node
	Node *last;													//pointer to point at last node //helps in adding new node in end of linked list
	
	first = new Node;      										//creates space for first node in heap
	first->data = A[0];										  //data part is assigned as first element of the array
	first->next = NULL;										  //next pointer points to NULL only
	last = first;										     //last pointer made to point at first node //helps in linking nodes [V. Imp]
	
	for(i=1; i<n; i++)										//starting from 1 as already 0th element is created
	{
		t = new Node;									     //everytime a new space is created in heap for a new node represented by t
		t->data = A[i];										//data part is assigned according to array element
		t->next = NULL;										//everytime the node is created its next points to NULL as there is no node after that
		last->next = t;										//helps in linking the previous node with the newly created node
		last = t;											//last refreshes its pointer to the newly created node that will help again in linking a newly created node in next iteration
	}
}

LinkedList::~LinkedList()
{
	Node *p = first;
	while(first)
	{
		first = first->next;
		delete p;
		p = first;
	}
}

void LinkedList::display()
{
	Node *p = first;
	while(p)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}

int LinkedList::count()
{
	Node *p = first;
	int len = 0;
	
	while(p)
	{
		len++;
		p = p->next;
	}
	return len;
}

void LinkedList::insert(int index, int x)
{
	Node *p = first;
	Node *t;                                   //for new node that is to be inserted
	int i;
	
	/*
	if(index < 0 || index > count(p))                 //to check if index is valid or not //count is a function which counts the length of the linked list (used in previous programs)
		return;
	*/
	
	t = new Node;   //creates space for the new node in the HEAP
	t->data = x;										//assigns the data part of the node
	
	if(index == 0)										//for insertion at the very beginning
	{
		t->next = first;
		first = t;	
	}
	else												//for insertion after a given node
	{
		for(i=0;i<index-1;i++)
			p = p->next;
		t->next = p->next;
		p->next = t;
	}
}

int LinkedList::Delete(int index)
{
	Node *p;
	Node *q = NULL;										//tail pointer
	int x = -1,i;
	
	/*if(index < 1 || index > count(p))					//to check if a given index is valid or not
		return -1; */
		
	if(index == 1)
	{
		p = first;
		x = first->data;
		first = first->next;
		delete p;
		return x;
	}
	else
	{
		p = first;
		for(i=0;i<index-1;i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		x = p->data;
		delete p;
		return x;
	}
}

int main()
{
	
	int A[] = {1,2,3,4,5};
	
	LinkedList l(A,5);
	
	l.insert(3,10);
	l.display();
	
	
	return 0;
}

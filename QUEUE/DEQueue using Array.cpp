#include<iostream>
using namespace std;

class DEQueue
{
	private:
		int front;
		int rear;
		int size;
		int *Q;
	public:
		DEQueue(int size);
		~DEQueue();
		void display();
		void enqueueFront(int x);
		void enqueueRear(int x);
		int dequeueFront();
		int dequeueRear();
		bool isEmpty();
		bool isFull();
};

DEQueue::DEQueue(int size)
{
	this->size = size;
	front = -1;
	rear = -1;
	Q = new int[size];
}

DEQueue::~DEQueue()
{
	delete []Q;
}

bool DEQueue::isEmpty()
{
	if(front == rear)
		return true;
	return false;
}

bool DEQueue::isFull()
{
	if(rear == size-1)
		return true;
	return false;
}

void DEQueue::enqueueFront(int x)
{
	if(front == -1)
		cout<<"DEQueue OverFlow"<<endl;
	else
	{
		Q[front] = x;
		front--;
	}
}

void DEQueue::enqueueRear(int x)
{
	if(isFull())
		cout<<"DEQueue OverFlow"<<endl;
	else
	{
		rear++;
		Q[rear] = x;
	}
}

int DEQueue::dequeueFront()
{
	int x = -1;
	if(isEmpty())
		cout<<"DEQueue Underflow"<<endl;
	else
	{
		front++;
		x = Q[front];
	}
	return x;
}

int DEQueue::dequeueRear()
{
	int x = -1;
	if(isEmpty())
		cout<<"DEQueue Underflow"<<endl;
	else
	{
		x = Q[rear];
		rear--;
	}
	return x;
}

void DEQueue::display()
{
	for(int i=front+1; i<=rear; i++)
		cout<<Q[i]<<" ";
	cout<<endl;
}

int main()
{
	DEQueue deq(5);
	
	deq.enqueueRear(10);
	deq.enqueueRear(20);
	deq.enqueueRear(30);
	deq.enqueueRear(40);
	deq.enqueueRear(50);
	deq.display();
	
	deq.dequeueRear();
	deq.display();
	
	deq.dequeueFront();
	deq.display();
	
	deq.enqueueFront(60);
	deq.display();
	
	deq.enqueueRear(70);
	deq.display();
	
	deq.dequeueFront();
	deq.dequeueFront();
	deq.dequeueFront();
	deq.display();
	
	deq.dequeueRear();
	deq.dequeueRear();
	deq.display();
	
	deq.dequeueRear();
	
	return 0;
}

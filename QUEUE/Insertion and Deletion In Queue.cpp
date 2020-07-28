#include<stdio.h>
#include<stdlib.h>

struct Queue
{
	int size;						//size for the fixed size array which is going to be the Queue
	int front;						//index pointer for deletion from Queue
	int rear;						//index pointer for insertion in Queue
	int *Q;							//pointer to create the Queue dynamically in the HEAP
};

void create(struct Queue *q, int size)
{
	q->size = size;											//size of array assigned
	q->front = q->rear = -1;								//front and rear are initialised with -1 //indicates Queue is empty initially
	q->Q = (int *)malloc(q->size * sizeof(int));			//Array is created dynamically in HEAP of size equal to q->size
}

void enqueue(struct Queue *q, int x)						//Function to insert element in the Queue
{
	if(q->rear == q->size - 1)								//Condition to check Queue is full or not //Queue is full when rear points to size-1
		printf("Queue is Full\n");
	else
	{
		q->rear++;											//rear is incremented first
		q->Q[q->rear] = x;									//value is inserted in Q[rear]
	}
}

int dequeue(struct Queue *q)								//Function to delete element from the queue
{
	int x = -1;												//x will store the deleted value //initialised with -1 //if queue is empty the function will return -1
		
	if(q->front == q->rear)									//Condtion to check if Queue is empty or not //Queue is empty when front equals rear
		printf("Queue is Empty\n");
	else
	{
		q->front++;											//front is incremented first
		x = q->Q[q->front];									//x is assigned with the value of Q[front]
	}
	return x;												//return x
}

void display(struct Queue q)
{
	for(int i=q.front+1; i<=q.rear; i++)							//Since, front points the index just before the first element, i should start from front+1 //rear points exactly to the last element																
		printf("%d ", q.Q[i]);
	printf("\n");
}

int main()
{
	struct Queue q;
	create(&q,5);
	
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	
	display(q);
	
	dequeue(&q);
	
	display(q);
	
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int col;
	int val;
	struct Node *next;
};

void create(struct Node *A[], int m)
{
	struct Node *last = NULL;                 //last pointer to link newly created node with the previously created node
	struct Node *p = NULL;					  //pointer to create new node in the HEAP
	int i,j,x;								  //x for asking number of non zero elements in a particular row
	
	for(i=0; i<m; i++)
	{
		A[i] = NULL;							//initialising array with NULL with every new iteration
		
		printf("Enter the number of non zero elements in Row %d: ",i);
		scanf("%d", &x);
		
		for(j=0; j<x; j++)                              //j loop works for the number of non zero elements in a row //not for column
		{
			p = (struct Node *)malloc(sizeof(struct Node));
			printf("Enter the column no and the value of the %d element: ",j+1);
			scanf("%d%d", &p->col, &p->val);
			p->next = NULL;
			
			if(A[i] == NULL)                            //checks if the A[i] is NULL then it is the first node in that index
			{
				A[i] = p;								//A[i] equals to the value of p
				last = p;								//last pointer equals to p
			}
			else										//checks if A[i] != NULL which means first node is already present in the row hence it links the newly created node with the previous one
			{
				last->next = p;							//last->next now updates to the newly created node
				last = p;								//last is updated to the newly created node
			}
		}
	}
}

void display(struct Node *A[], int m, int n)
{
	int i,j;
	struct Node *p = NULL;										//pointer for traversing
	
	for(i=0; i<m; i++)
	{
		p = A[i];                                       //making p point to the array index //it works just like the "first" used in previous programs for accessing the nodes 
		
		for(j=0; j<n; j++)
		{
			if(p && j == p->col)						//checks if p is valid or not //if j equals to p->col it means at that column a value is present and hence prints its value
			{
				printf("%d ",p->val);					//prints value
				p = p->next;							//moves p pointer ahead
			}
			else										//if p is NULL or if j != p->col which means either pointer p is NULL or in jth column there is no value
				printf("0 ");
		}
		printf("\n");
	}
}

int main()
{
	int row, col;
	printf("Enter the number of the rows and columns: \n");
	scanf("%d%d", &row, &col);
	struct Node *A[row];                                     //pointer to an array of type struct Node //to build array of linked lists
	create(A, row);
	display(A, row, col);
	
	return 0;
}

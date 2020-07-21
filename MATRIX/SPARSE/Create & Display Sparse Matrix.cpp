#include<stdio.h>
#include<stdlib.h>

struct Element
{
	int i;        //for row number
	int j;		  //for column number
	int x;        //for the element itself
};

struct Sparse
{
	int m;    					//no of rows
	int n;    					//no of columns
	int num;  					//number of non zero elements
	struct Element *ele;       //create an array of element structure dynamically
};

void create(struct Sparse *s)
{
	int i;
	printf("Enter dimensions: \n");
	scanf("%d %d", &s->m, &s->n);
	printf("Enter number of non zero elements: \n");
	scanf("%d", &s->num);
	
	s->ele = (struct Element *)malloc(s->num * sizeof(struct Element));
	printf("Enter all non zero elements \n");
	for(i=0;i<s->num;i++)
		scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
}

void display(struct Sparse s)
{
	int i,j,k=0;      //k for non zero elements
	
	for(i=0;i<s.m;i++)
	{
		for(j=0;j<s.n;j++)
		{
			if( i == s.ele[k].i && j == s.ele[k].j) 			//for checking if i equals to the i of element array and if j equals to the j of element array
			{
				printf("%d ",s.ele[k++].x);						//incrementing k also 
			}
			else
				printf("0 ");
		}
		printf("\n");
	}
}

int main()
{
	struct Sparse s;
	
	create(&s);
	printf("\n");
	display(s);
	
	return 0;
}

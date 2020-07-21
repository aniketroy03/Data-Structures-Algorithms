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
				printf("%d ",s.ele[k++].x);
			}
			else
				printf("0 ");
		}
		printf("\n");
	}
}

struct Sparse *add(struct Sparse *s1, struct Sparse *s2)
{
	int i,j,k;
	i = j = k = 0;
	
	if(s1->n != s2->n && s1->m != s2->m)
 		return NULL;
	
	struct Sparse *sum;
	sum = (struct Sparse *)malloc(sizeof(struct Sparse));
	
	sum->ele = (struct Element *)malloc( (s1->num+s2->num)*sizeof(struct Element));
	
	while(i<s1->num && j<s2->num)
	{
		if(s1->ele[i].i < s2->ele[j].i)
			sum->ele[k++] = s1->ele[i++];
		else if(s1->ele[i].i > s2->ele[j].i)
			sum->ele[k++] = s2->ele[j++];
		else
		{
			if(s1->ele[i].j < s2->ele[j].j)
				sum->ele[k++] = s1->ele[i++];
			else if(s1->ele[i].j > s2->ele[j].j)
				sum->ele[k++] = s2->ele[j++];
			else
			{
				sum->ele[k] = s1->ele[i]; //copying the row number, column number and the element in sum sparse matrix from first sparse matrix s1
				sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x; //adding the element of s1 and s2 at sum sparse matrix and incrementing i j and k all together
			}
		}
	}
	for(;i<s1->num;i++)					//for copying the leftover elements if either of the matrix is finished according to the while condition ie while(i<s1->num && j<s2->num)
		sum->ele[k++] = s1->ele[i];
	for(;j<s2->num;j++)					//for copying the leftover elements if either of the matrix is finished according to the while condition ie while(i<s1->num && j<s2->num)
		sum->ele[k++] = s2->ele[j]; 
		
	//dimensions
	sum->m = s1->m;
	sum->n = s1->n;
	sum->num = k;
	
	//returning sum matrix
	return sum;
}

int main()
{
	struct Sparse s1,s2,*s3;
	
	create(&s1);
	create(&s2);
	s3 = add(&s1,&s2);
	
	printf("\n");
	printf("First Matrix: \n");
	display(s1);
	printf("Second Matrix: \n");
	display(s2);
	printf("Sum Matrix: \n");
	display(*s3); //dereferencing for call by value
	
	return 0;
}

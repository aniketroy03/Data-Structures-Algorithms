#include<stdio.h>
#include<stdlib.h>
struct Matrix
{
	int *A;					//single dimension array
	int n;
};

void set(struct Matrix *m,int i,int j,int x)
{
	if(i>=j)		//if i is greater than or equal to j ie condition for lower traingular matrix
	{
		m->A[i*(i-1)/2 + j-1] = x;    //formula for lower traingular matrix using ROW MAJOR MAPPING
	}
}
int get(struct Matrix m,int i,int j)
{
	if(i>=j)
		return m.A[i*(i-1)/2 + j-1] ;
	return 0;
}
void display(struct Matrix m)
{
	int i,j;
	for(i=1;i<=m.n;i++)
	{
		for(j=1;j<=m.n;j++)
		{
			if(i>=j)
				printf("%d ",m.A[i*(i-1)/2 + j-1]);
			else
				printf("0 ");
		}
		printf("\n");
	}
}
int main()
{
	struct Matrix m;
	int i,j,x;
	
	printf("Enter dimension: ");
	scanf("%d",&m.n);
	m.A = (int *)malloc(m.n*(m.n+1)/2 * sizeof(int));  //since single dimension array will have number of elements equal to n*(n+1)/2 ie sum of first n natural numbers where n is the dimension of the array
	
	printf("Enter all elements: \n");
	for(i=1;i<=m.n;i++)
	{
		for(j=1;j<=m.n;j++)
		{
			scanf("%d",&x);
			set(&m,i,j,x);
		}
	}
	printf("\n");
	display(m);
	
	return 0;
}

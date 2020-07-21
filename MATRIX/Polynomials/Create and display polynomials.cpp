#include<stdio.h>
#include<stdlib.h>

struct Term
{
	int coeff;
	int exp;
};

struct Poly
{
	int n;
	struct Term *terms;
};

void create(struct Poly *p)
{
	printf("Enter number of terms: \n");
	scanf("%d", &p->n);
	p->terms = (struct Term *)malloc(p->n * sizeof(struct Term));
	
	printf("Enter the terms: \n");
	for(int i=0;i<p->n;i++)
	{
		scanf("%d",&p->terms[i].coeff);
		scanf("%d",&p->terms[i].exp);
	}
}

void display(struct Poly p)
{
	int i;
	for(i=0; i<p.n; i++)
		printf("%dx%d+",p.terms[i],p.terms[i].exp);
	printf("\n");
}

int main()
{
	struct Poly p1;
	create(&p1);
	display(p1);
	
	return 0;
}

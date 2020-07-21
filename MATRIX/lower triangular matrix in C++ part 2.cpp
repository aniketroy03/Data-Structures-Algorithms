#include<iostream>
using  namespace std;
class LowerTri
{
	private:
		int n;
		int *A;    //single dimension array
	public:
		LowerTri()			//default constructor
		{
			n=2;
			A = new int[2*(2+1)/2];
		}
		LowerTri(int n)			//parameterized constructor
		{
			this->n = n;
			A = new int[n*(n+1)/2];			//n*(n+1)/2 is the total number of elements in the array where n is the dimension of the array
		}
		~LowerTri()
		{
			delete []A;
		}
		void set(int i,int j,int x);
		int get(int i,int j);
		void display();
};
void LowerTri::set(int i,int j, int x)
{
	if(i>=j)
		A[n*(j-1)-(j-2)*(j-1)/2+(i-j)] = x;  // formula for lower triangular matrix in COLUMN MAJOR MAPPING
}
int LowerTri::get(int i,int j)
{
	if (i>=j)
		return A[n*(j-1)-(j-2)*(j-1)/2+(i-j)];
	return 0;
}
void LowerTri::display()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i>=j)
				cout<<A[n*(j-1)-(j-2)*(j-1)/2+(i-j)]<<" ";
			else
				cout<<"0 ";
		}
		cout<<endl;
	}
		
}
int main()
{
	int d;
	cout<<"Enter dimension: "<<endl;
	cin>>d;
	LowerTri lm(d);
	cout<<"Enter all elements: "<<endl;
	int i,j,x;
	for(i=1;i<=d;i++)
	{
		for(j=1;j<=d;j++)
		{
			cin>>x;
			lm.set(i,j,x);
		}
	}
	cout<<endl;
	lm.display();
	return 0;
}

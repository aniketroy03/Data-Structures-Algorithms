#include<iostream>
using namespace std;
class element
{
	public:
		int i;
		int j;
		int x;
};

class Sparse
{
	private:
		int m;
		int n;
		int num;
		element *ele;
	public:
		Sparse(int m,int n,int num)
		{
			this->m = m;
			this->n = n;
			this->num = num;
			
			ele = new element[this->num];   //creating an array of type class Element dynamically
		}
		~Sparse()
		{
			delete []ele;
		}
		
		friend istream & operator>>(istream &is, Sparse &s);    //istream operator signature
		friend ostream & operator<<(ostream &os, Sparse &s);    //ostream operator signature
};

//operator overloading 
istream & operator>>(istream &is, Sparse &s)
{
	cout<<"Enter the non zero elements: \n";
	for(int i=0; i<s.num; i++)
	{
		cin>>s.ele[i].i;		//for row number
		cin>>s.ele[i].j;		//for column number
		cin>>s.ele[i].x;		//for element itself
	}
	return is;
}
ostream & operator<<(ostream &os, Sparse &s)
{
	int k=0;                //for tracking the non zero elements in array ele
	for(int i=0; i<s.m; i++)
	{
		for(int j=0; j<s.n; j++)
		{
			if(s.ele[k].i == i && s.ele[k].j == j)    //for checking if i and j of array ele is equal to loop's i and j. If true display the element present in that i and j of array ele
				cout<<s.ele[k++].x<<" ";            //incrementing the k also
			else
				cout<<"0 ";
		}
		cout<<endl;
	}
	return os;
}

int main()
{
	Sparse *s;
	s = new Sparse(5,5,5);
	cin>>*s;
	cout<<*s;
	
	return 0;
}

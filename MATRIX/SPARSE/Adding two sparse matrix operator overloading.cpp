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
		
		Sparse operator+(Sparse &s);   							//adding two sparse matrices signature	//s for second sparse matrix
		friend istream & operator>>(istream &is, Sparse &s);    //istream operator signature
		friend ostream & operator<<(ostream &os, Sparse &s);    //ostream operator signature
};

Sparse Sparse::operator+(Sparse &s)  //here s refers to the second sparse matrix
{
	int i,j,k;
	i = j = k = 0;
	
	Sparse *sum;
	sum = new Sparse(m,n,num+s.num);     //adding number of non zero element of first and second sparse matrix
	
	while(i<num && j<s.num)
 	{
 		if(ele[i].i<s.ele[j].i)
 			sum->ele[k++]=ele[i++];
 		else if(ele[i].i > s.ele[j].i)
 			sum->ele[k++]=s.ele[j++];
 		else
 		{
 			if(ele[i].j<s.ele[j].j)
 				sum->ele[k++]=ele[i++];
 			else if(ele[i].j > s.ele[j].j)
 				sum->ele[k++]=s.ele[j++];
 			else
			{
 				sum->ele[k]=ele[i];
 				sum->ele[k++].x=ele[i++].x+s.ele[j++].x;
 			}
 		}
 	}
 	
	for(;i<num;i++)
		sum->ele[k++]=ele[i];
 	for(;j<s.num;j++)
	 	sum->ele[k++]=s.ele[j];

	sum->num=k;
	return *sum;
}

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
	Sparse s1(3,3,3);
	Sparse s2(3,3,3);
	
	cin>>s1;
	cin>>s2;
	
	Sparse sum = s1+s2;				//example of operator overloading
	
	cout<<"First Matrix"<<endl<<s1;    //dispay first sparse matrix
	cout<<"Second Matrix"<<endl<<s2;   //display second sparse matrix
	cout<<"Sum Matrix"<<endl<<sum;	   //display sum of first and second matrix
	
	return 0;
}

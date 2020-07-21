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
		void read()
		{
			cout<<"Enter the non zero elements: \n";
			for(int i=0; i<num; i++)
			{
				cin>>ele[i].i;		//for row number
				cin>>ele[i].j;		//for column number
				cin>>ele[i].x;		//for element itself
			}
		}
		void display()
		{
			int k=0;                //for tracking the non zero elements in array ele
			for(int i=0; i<m; i++)
			{
				for(int j=0; j<n; j++)
				{
					if(ele[k].i == i && ele[k].j == j)    //for checking if i and j of array ele is equal to loop's i and j. If true display the element present in that i and j of array ele
						cout<<ele[k++].x<<" ";            //incrementing the k also
					else
						cout<<"0 ";
				}
				cout<<endl;
			}
		}
};

int main()
{
	Sparse *s;
	s = new Sparse(5,5,5);
	s->read();
	s->display();
	
	return 0;
}

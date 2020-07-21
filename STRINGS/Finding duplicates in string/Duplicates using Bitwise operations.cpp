#include<iostream>
using namespace std;
int main()
{
	char word[]="finding";
	int H=0,a=0;					
	for(int i=0; word[i]!='\0'; i++)
	{
		a = 1;
		a = a << (word[i]-97);
		if((a&H)>0)
			cout<<word[i]<<" is duplicate."<<endl;
		else
			H = a | H;	
	}
	cout<<endl;
	return 0;
}

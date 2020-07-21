#include<iostream>
using namespace std;
int main()
{
	char a[] = "AnIkEt";
	int i;
	for(i=0;a[i]!='\0';i++)					//'\0' is used to check the last terminating index of a string
	{
		if(a[i]>=65 && a[i]<=90)
			a[i] = a[i]+32;						//32 is the ascii code difference between lower case and upper case
		else if(a[i]>='a' && a[i]<='z')
			a[i] = a[i]-32;
	}
	cout<<a<<endl;
	return 0;
}

#include<iostream>
using namespace std;
int main()
{
	char s[] = "aniket";
	int i;
	for(i=0;s[i]!='\0';i++);
	cout<<"The length of string is: "<<i<<endl;
	return 0;
}

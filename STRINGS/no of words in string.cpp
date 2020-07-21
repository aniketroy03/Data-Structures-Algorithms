#include<iostream>
using namespace std;
int main()
{
	char a[] = "how are   you                      aniket";
	int i;
	int words=1;					//to count the words
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]==' ' && a[i-1]!=' ')				//checking for spaces as it will help to determine the no of words //second condition is to eliminate consecutive appearing spaces called as whitespace
			words++;
	}
	cout<<"No of words in the string: "<<words<<endl;
	return 0;
}

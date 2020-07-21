#include<iostream>
using namespace std;
int main()
{
	int a[11] = { 2,6,8,8,10,12,15,15,15,20,20 };
	int lastDuplicate = 0;							//variable to track and keep record of lastDuplicate //to prevent multiple checking for same repeating element
	for (int i = 0; i < 11; i++)
	{
		if (a[i] == a[i + 1] && a[i] != lastDuplicate)  //checking adjacent elements for repetation and checking lastDuplicate condition to prevent checking for same repeating element
		{
			cout << "Ducplicate element is: " << a[i] << endl;
			lastDuplicate = a[i];
		}
	}
	cout << endl;
	return 0;
}
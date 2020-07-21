#include<iostream>
using namespace std;
int main()
{
	int a[11] = { 1,2,3,4,5,6,8,9,12,13,14 };
	int n = sizeof(a) / sizeof(int);
	int diff = a[0];							//initialising diff with first index element of array

	//We will check for the differnce between the index element and the array index
	//Wherever the difference will not be equal, a missing element is there
	//will increment diff till the difference a[i]-i not equal to diff to continue as soon as we find the missing element

	for (int i = 0; i < n; i++)
	{
		if (a[i] - i != diff)
		{
			while (diff < a[i] - i)
			{
				cout << "Missing element is: " << i + diff << endl;
				diff++;
			}
		}
	}
	return 0;
}

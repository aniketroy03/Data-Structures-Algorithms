#include<iostream>
using namespace std;
int main()
{
	int a[11] = { 3,6,8,8,10,12,15,15,15,20,20 };
	int h[20] = { 0 };							//initialising hash table if size equal to the largest element in the array
	for (int i = 0; i < 11; i++)
		h[a[i]]++;
	for (int i = 0; i <= 20; i++)				//checking hash table for values greater than 0 so those elements are duplicate
		if (h[i] > 1)
			cout << "Duplicate is: " << i << endl;
	cout << endl;
	return 0;
}

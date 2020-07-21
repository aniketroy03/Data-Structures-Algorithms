#include<iostream>
using namespace std;
int main()
{
	int a[10] = { 6,3,8,10,16,7,5,2,9,14 };
	int n = sizeof(a) / sizeof(int);
	int h[17] = { 0 };							//Initialising hash table with size equal to the largest element in the array
	int k = 10;									//sum
	for (int i = 0; i < n; i++)
	{
		if (h[k - a[i]] != 0 && k-a[i]>=0)			//Note: the condition k-a[i]>=0 must be checked because there are some cases like h[-6]=4 due to which h[-6]!=0 and if condition takes place
			cout << a[i] << "+" << k - a[i] << "=" << k << endl;
		h[a[i]]++;
	}
	cout << endl;
	return 0;
}
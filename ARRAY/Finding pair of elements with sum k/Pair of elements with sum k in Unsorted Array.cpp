#include<iostream>
using namespace std;
int main()
{
	int a[10] = { 6,3,8,10,16,7,5,2,9,14 };
	int n = sizeof(a) / sizeof(int);
	int k = 10;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] + a[j] == k)
				cout << a[i] << "+" << a[j] << "=" << k << endl;
	cout << endl;
	return 0;
}
//Time complexity: O(n^2)
#include<iostream>
using namespace std;
int main()
{
	int a[10] = { 5,8,3,9,6,2,10,7,-1,4 };
	int n = sizeof(a) / sizeof(int);
	int min = a[0];
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
		else if (a[i] > max)
			max = a[i];
		else
			continue;
	}
	cout << "Minimum element is: " << min << endl;
	cout << "Maximum element is: " << max << endl;
	return 0;
}
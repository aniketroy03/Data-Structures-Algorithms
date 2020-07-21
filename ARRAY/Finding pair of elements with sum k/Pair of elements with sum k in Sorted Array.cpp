#include<iostream>
using namespace std;
int main()
{
	int a[10] = { 1,3,4,5,6,8,9,10,12,14 };
	int n = sizeof(a) / sizeof(int);
	int k = 10;										//sum of two elements
	int i, j;
	i = 0;
	j = n - 1;
	while (i < j)
	{
		if (a[i] + a[j] == k)
		{
			cout << a[i] << "+" << a[j] << "=" << k << endl;
			i++;
			j--;
		}
		else if (a[i] + a[j] < k)
		{
			i++;							//increment i if the sum of two elements is less than k
		}
		else
			j--;							//decremnt j if the sum of two elements is greater than k
	}
	cout << endl;
	return 0;

}
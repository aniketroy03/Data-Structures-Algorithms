#include<iostream>
using namespace std;
int main()
{
	int a[11] = { 1,2,3,4,5,7,8,9,10,11,12 };
	int n = sizeof(a) / sizeof(int);
	int sum = 0;												//sum initialised with 0
	for (int i = 0; i < n; i++)									//for loop to calculate the sum of elements of the array
		sum = sum + a[i];
	int s = (n + 1) * (n + 2) / 2;								//to find sum of first n natural numbers //here n is 11 but the final element in the array is 12 hence replacing (n+1) in n to get sum of first 12 natural numbers
	cout << "Missing Element is: " << s - sum << endl;			//missing element is found by subtracting sum of first n+1 natural numbers by sum of elements in the array
	return 0;
}
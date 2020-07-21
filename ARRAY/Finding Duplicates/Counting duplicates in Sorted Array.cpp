#include<iostream>
using namespace std;
int main()
{
	int a[11] = { 2,6,8,8,10,15,15,15,15,20,20 };
	for (int i = 0; i < 11; i++)
	{
		if (a[i] == a[i + 1])
		{
			int j = i + 1;
			while (a[j] == a[i])
				j++;
			cout << a[i] << " repeated for " << j - i<<endl;
			i = j - 1;
		}
	}
	cout << endl;
	return 0;
}
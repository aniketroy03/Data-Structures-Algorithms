#include<iostream>
#include<stdlib.h>
using namespace std;
struct Array
{
	int a[10];
	int size;
	int length;
};

void display(struct Array arr)
{
	int i;
	for (i = 0; i < arr.length; i++)
		cout << arr.a[i] << " ";
	cout << endl;
}

struct Array* Union(struct Array* arr1, struct Array* arr2)
{
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
	
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->a[i] < arr2->a[j])							//element of Array 1 is less than Array 2
			arr3->a[k++] = arr1->a[i++];								
		else if (arr2->a[j] < arr1->a[i])						//element of Array 2 is less than Array 1
			arr3->a[k++] = arr2->a[j++];
		else                                                    //element of Array 1 and Array 2 are equal
		{
			arr3->a[k++] = arr1->a[i++];						//copy any one of the element in third array 
			j++;												//increment i and j together
		}
		
	}
	for (; i < arr1->length; i++)								//to copy the remaining elements of array 1
		arr3->a[k++] = arr1->a[i];
	for (; j < arr2->length; j++)								//to copy the remaining elements of array 2
		arr3->a[k++] = arr2->a[j];
	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

struct Array* Intersection(struct Array* arr1, struct Array* arr2)
{
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->a[i] < arr2->a[j])						
			i++;									//just increment i
		else if (arr2->a[j] < arr1->a[i])
			j++;									//just increment j
		else
		{
			arr3->a[k++] = arr1->a[i++];            //a[i] and a[j] both are equal and copy one of them in third Array
			j++;
		}

	}
	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

struct Array* Difference(struct Array* arr1, struct Array* arr2)
{
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->a[i] < arr2->a[j])			//element of array 1 is less than array 2
			arr3->a[k++] = arr1->a[i++];		//copy the element in the third array
		else if (arr2->a[j] < arr1->a[i])		//element of array 2 is less than array 1
			j++;								//just increment j
		else                                    //if a[i] is equal to a[j]
		{	
			i++;								//increment i and j together
			j++;
		}

	}
	for (; i < arr1->length; i++)							//to copy the remaining elements in array 1
		arr3->a[k++] = arr1->a[i];
	arr3->length = k;
	arr3->size = 10;
	return arr3;
}



int main()
{
	struct Array arr1 = { {2,6,10,15,25},10,5 };
	struct Array arr2 = { {3,4,7,15,20},10,5 };
	struct Array* arr3;
	arr3 = Union(&arr1, &arr2);
	display(*arr3);
	return 0;
}

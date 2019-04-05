/*
 * C++ implementation of the quick-sort algorithm
 *
 * Last element of the array is the pivot
 */

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high)
{
	int i=low-1, j, pivot=arr[high];
	for(j=low; j<=high-1; j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[high], &arr[i+1]);
	return i+1;
}

void quickSort(int arr[], int low, int high)
{
	int p;
	if(low<high)
	{
		p = partition(arr, low, high);
		quickSort(arr,low,p-1);
		quickSort(arr,p+1,high);
	}
}

int main ()
{
	int n=10;
	int arr[n], i;

	cout<<"Enter numbers in the array"<<endl;
	for(i=0; i<n; i++)
	{
		cin>>arr[i];
	}

	quickSort(arr,0,n-1);

	cout<<"Sorted array is as follows"<<endl;
	for(i=0; i<n; i++)
	{
		cout<<arr[i]<<"	";
	}

	return 0;
}
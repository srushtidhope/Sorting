/*
 * C++ implementation of the merge-sort algorithm
 *
 */

#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
	// Copying array data to temporary arrays
	int n1 = mid-(low-1);
	int n2 = high-mid;
	int tempLeft[n1], tempRight[n2];
	for(int i=0; i<n1; i++)
	{
		tempLeft[i] = arr[low+i];
	}
	for(int j=0; j<n2; j++)
	{
		tempRight[j] = arr[mid+1+j];
	}

	// Merge both arrays in sorted order
	int i=0, j=0, k=low;
	while(i<n1 && j<n2)
	{
		if(tempLeft[i]<=tempRight[j])
		{
			arr[k] = tempLeft[i];
			i++;
		}
		else
		{
			arr[k] = tempRight[j];
			j++;
		}
		k++;
	}

	// Append remaining elements from left array
	while(i<n1)
	{
		arr[k] = tempLeft[i];
		i++;
		k++;
	}

	// Append remaining elements from right array
	while(j<n2)
	{
		arr[k] = tempRight[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int low, int high)
{
	if(low<high)
	{
		int mid = low + (high-low)/2;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,mid,high);
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

	mergeSort(arr,0,n-1);

	cout<<"Sorted array is as follows"<<endl;
	for(i=0; i<n; i++)
	{
		cout<<arr[i]<<"	";
	}

	return 0;
}
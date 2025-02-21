#include "mergeSort.h"

void merge (int *array, int low, int mid, int high) 
{
	uint16_t iter, jiter, kiter;
	uint16_t temp1 = mid - low + 1;
	uint16_t temp2 = high - mid;
	int L[temp1], R[temp2];

	for (iter = 0; iter < temp1; iter++) 
	{
      		L[iter] = array[low + iter];
	}
	for (jiter = 0; jiter < temp2; jiter++)
      	{
      		R[jiter] = array[mid + jiter + 1];
	}

	iter = 0; 
	jiter = 0;
	kiter = low;

	while (iter < temp1 && jiter < temp2)
	{
		if (L[iter] <= R[jiter])
		{
			array[kiter] = L[iter];
			++iter;
		}
		else
		{
			array[kiter] = R[jiter];
			++jiter;
		}
		++kiter;
	}

	while (iter < temp1) 
	{
		array[kiter] = L[iter];
		++iter;
		++kiter;
	}
	while (jiter < temp2)
	{
		array[kiter] = R[jiter];
		++jiter;
		++kiter;
	}
}

void mergeSort (int *array, int low, int high) 
{
	if (low < high) 
	{
		int mid = low + (high - low) / 2;
	
		mergeSort(array, low, mid);
		mergeSort(array, mid + 1, high);
	
		merge(array, low, mid, high);
	}
}



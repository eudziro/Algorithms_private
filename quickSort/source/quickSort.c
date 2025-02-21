# include "quickSort.h"


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *array, int low, int high)
{
	int *pivot = (array + high);
	int temp = (low - 1);	   // new low
	while ( low < high)
	{	
		// If current element is smaller than the pivot
		if (array[low] < *pivot)
		{
			// increment and swap if current element is less than pivot;
			temp++; 
			swap(&array[temp], &array[low]);
		}++low;
	}
	swap(&array[temp + 1], pivot);
	return (temp + 1);
}

void quickSort(int *array, int low, int high)
{
	if (low < high)
	{
		int pivotPosition = partition(array, low, high);

		quickSort(array, low, pivotPosition - 1);
		quickSort(array, pivotPosition + 1, high);
	}
}


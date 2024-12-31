# include <stdio.h>

void print(int *array, int n) {
	int i = 0;
	while (i < n) {
		printf("%d ", array[i]);
		++i;
	}
printf("\n");
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *array, int low, int high)
{
	int pivot = array[high]; // pivot
	int i = (low - 1);	   // Index of smaller element
	int j = low;
	while (j <= high - 1)
	{	
		// If current element is smaller than the pivot
		if (array[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(&array[i], &array[j]);
		}++j;
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void quickSort(int *array, int low, int high)
{
	if (low < high)
	{
		int pi = partition(array, low, high);

		quickSort(array, low, pi - 1);
		quickSort(array, pi + 1, high);
	}
}


# include <stdio.h>

void print(int *array, int n) {
	int i = 0;
	while(i < n) {
		printf("%d ", *(array + i));
                ++i;
	}
printf("\n");
}

void merge(int *array, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1+ j];

     // Merge the temp arrays back into arr[left..right]

     i = 0; // Initial index of first subarray
     j = 0; // Initial index of second subarray
     k = left; // Initial index of merged subarray

     while (i < n1 && j < n2)
     {
         if (L[i] <= R[j])
         {
             array[k] = L[i];
             i++;
         }
         else
         {
             array[k] = R[j];
             j++;
         }
         k++;
     }

     while (i < n1)
     {
         array[k] = L[i];
         i++;
         k++;
     }

     while (j < n2)
     {
         array[k] = R[j];
         j++;
         k++;
     }
 }


void mergeSort(int *array, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right)/2;

        // Sort first and second halves
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        merge(array, left, mid, right);
     }
 }

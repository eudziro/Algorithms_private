# include "../source/mergeSort.h"
# include <stdio.h>

int main(void) {
	int array[] = {1, 23, 5, 50, 20, 7, 10, 8, 9};
	int n = sizeof array / sizeof (int);

	printf("Before: "); print(array, n);
	mergeSort(array, 0, n - 1);
	printf("After: "); print(array, n);
	return 0;
}



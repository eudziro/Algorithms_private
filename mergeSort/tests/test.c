# include <stdio.h>
# include "../source/mergeSort.h"

int generalTEST (int *array, int n, int *control) {  /* unit testing baby */
	int i = 0;
	while ( i < n ) {
		if ( array[i] != control[i]) 
			return 1;
		++i;
	}
	return 0;
}

void unitTEST (int *array, int n, int *control) {	
	// START TESTING
	if (generalTEST(array, n, control) != 0)
		printf("generalTEST: failed\n");
	//if 
	printf("unitTEST is done");
}

int main (void) {
	int control[] = {0, 1, 2, 3, 5, 5, 7, 8, 9, 10, 20};
	int array[] = {10, 7, 8, 9, 1, 5, 20, 2, 3, 5, 0};
	int n = sizeof array / sizeof (int);
	
	mergeSort(array, 0, n - 1);
	unitTEST(array, n, control);
	return 0;
}


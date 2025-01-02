#include "../source/binarySearch.h"
#include "../../quickSort/source/quickSort.h"
#include <stdio.h>

int generalTEST(int *array, int n, int target) {
	int binSearch = binarySearch(array, n - 1, target);
	static int i = -1;
	for (;;) {
		++i;
		if (*(array + i) == target) 
			return i; 
	}
		if ( i == binSearch) return 0;
	return 1;
}
int unitTEST(void) {
	int array[] = { 10, 350, 50, 60, 20, 2, 112, 3, 4, 100}; // initialize test array;
	int n = sizeof array / sizeof (int);
	int target = 4;
	quickSort(array, 0, n - 1);
	// binary search won't work with unsorted array

	int errorsCount = 0; // simple error counter
	int genTEST = generalTEST(array, n, target);
	if(genTEST == 1) {
		printf("generalTEST: failed\nunit test: exiting...\n");
		errorsCount++;
		return -1;
	}
	printf("unit test: done\nerrors: %i\n", errorsCount);
	return 0;
}

int main (void) {

	unitTEST();
	return 0;
}

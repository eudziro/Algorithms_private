# include "../source/quickSort.h"
# include <stdio.h>

int main (void) {
	
	int control[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int array[] = {6, 3, 9, 8, 1, 2, 4, 7, 5, 10};
	int n = sizeof array / sizeof array[0];
	
	quickSort(array, 0, n - 1);
	return 0;
}

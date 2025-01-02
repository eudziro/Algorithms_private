#include "../source/binarySearch.h"
#include "../../quickSort/source/quickSort.h"
#include <stdio.h>

int main(void)
{
    int array[] = { 10 , 560, 205, 20, 6, 21 };
    int x = 560;
    int n = sizeof array / sizeof (int);

    quickSort(array, 0, n - 1); // binary search won't work in non sorted array
    int result = binarySearch(array, n - 1, x);
    if(result == -1) printf("Element is not present in the array\n");
    else printf("Index of found element is: %i\n", result);
    return 0;
}


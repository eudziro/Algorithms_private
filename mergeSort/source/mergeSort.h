# ifndef MERGESORT_H
# define MERGESORT_H

//
// Simple implementation of mergesort
//

# ifdef __cplusplus
extern "C" {
# endif

#include <stdio.h>
#include <stdint.h>

void mergeSort(int *array, int low, int high);
void print(int *array, int n);

# ifdef __cplusplus
}
# endif

#endif // MERGESORT_H

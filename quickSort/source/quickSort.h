# ifndef QUICK_SORT_H
# define QUICK_SORT_H

//
//  Simple implementation quickSort
//

# ifdef __cplusplus
extern "C" {
# endif 

void quickSort(int *array, int low, int high);
void print(int *array, int n);
void swap (int *a, int *b);
int partition(int *array, int low, int high);

# ifdef __cplusplus
}
# endif

# endif // QUICK_SORT_H

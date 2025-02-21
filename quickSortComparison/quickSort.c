#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int* arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int pi = i + 1;

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    const int SIZE = 1000000;
    int* arr1 = (int*)malloc(SIZE * sizeof(int));
    int* arr2 = (int*)malloc(SIZE * sizeof(int));

    for (int i = 0; i < SIZE; i++) {
        arr1[i] = rand() % 1000000; // Случайные числа от 0 до 999999
        arr2[i] = arr1[i]; // Копируем для сравнения
    }

    clock_t start = clock();
    quicksort(arr1, 0, SIZE - 1);
    clock_t end = clock();
    double quicksort_time = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    qsort(arr2, SIZE, sizeof(int), compare);
    end = clock();
    double qsort_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Время выполнения QuickSort: %f секунд\n", quicksort_time);
    printf("Время выполнения встроенного qsort: %f секунд\n", qsort_time);
    //almost the same time, ~0.01 difference

    free(arr1);
    free(arr2);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 1000 // Максимальное количество элементов

int values[MAX_N];
int n; // Количество элементов
int cache[MAX_N]; // Кэш для хранения результатов
int chosen[MAX_N]; // Массив для хранения выбранных элементов

int knapsack(int index) {
    if (index < 0) return 0; // Базовый случай
    if (cache[index] != -1) return cache[index]; // Проверка кэша

    int notTake = knapsack(index - 1);

    int take = values[index] + knapsack(index - 2);

    cache[index] = (take > notTake) ? take : notTake;

    if (take > notTake) {
        chosen[index] = 1; // Текущий элемент выбран
    } else {
        chosen[index] = 0; // Текущий элемент не выбран
    }

    return cache[index];
}

void reconstruct(int index) {
    if (index < 0) return;
    if (chosen[index] == 1) {
        printf("Элемент %d (стоимость: %d)\n", index, values[index]);
        reconstruct(index - 2); // Переходим к элементу, который не соседний
    } else {
        reconstruct(index - 1); // Переходим к следующему элементу
    }
}

int main() {
    n = 1000; // Количество элементов
    for (int i = 0; i < n; i++) {
        values[i] = rand() % 10 + 1; // Случайные стоимости от 1 до 10
    }

    for (int i = 0; i < n; i++) {
        cache[i] = -1;
        chosen[i] = 0;
    }

    clock_t start = clock();
    int maxValue = knapsack(n - 1);
    clock_t end = clock();

    printf("Максимальная стоимость: %d\n", maxValue);
    printf("Время выполнения: %lf секунд\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

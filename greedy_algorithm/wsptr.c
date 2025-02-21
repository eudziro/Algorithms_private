#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int weight; // вес задачи
    int time;   // время выполнения задачи
} Task;

int compareWSPT(const void* a, const void* b) {
    Task* taskA = (Task*)a;
    Task* taskB = (Task*)b;
    double ratioA = (double)taskA->weight / taskA->time;
    double ratioB = (double)taskB->weight / taskB->time;
    return (ratioB < ratioA) - (ratioB > ratioA); // Сортировка по убыванию
}

int compareWSPTR(const void* a, const void* b) {
    Task* taskA = (Task*)a;
    Task* taskB = (Task*)b;
    
    // Сначала сортируем по времени, затем по весу
    if (taskA->time != taskB->time) {
        return taskA->time - taskB->time; // Сортировка по времени
    }
    return taskB->weight - taskA->weight; // Если время одинаковое, сортируем по весу
}

int calculateWeightedCompletionTime(Task* tasks, int n) {
    int totalCompletionTime = 0;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        currentTime += tasks[i].time;
        totalCompletionTime += currentTime * tasks[i].weight;
    }

    return totalCompletionTime;
}

int main() {
    int n;
    printf("Введите количество задач: ");
    scanf("%d", &n);

    Task* tasks = malloc(n * sizeof(Task));
    Task* tasksCopy = malloc(n * sizeof(Task)); // Копия массива задач

    for (int i = 0; i < n; i++) {
        printf("Введите вес и время выполнения задачи %d: ", i + 1);
        scanf("%d %d", &tasks[i].weight, &tasks[i].time);
    }

    // Жадный алгоритм WSPT
    qsort(tasks, n, sizeof(Task), compareWSPT);
    int totalWSPT = calculateWeightedCompletionTime(tasks, n);
    printf("Сумма взвешенных сроков завершения (WSPT): %d\n", totalWSPT);

    // Копируем оригинальный массив для WSPTR
    memcpy(tasksCopy, tasks, n * sizeof(Task));

    // Жадный алгоритм WSPTR
    qsort(tasksCopy, n, sizeof(Task), compareWSPTR);
    int totalWSPTR = calculateWeightedCompletionTime(tasksCopy, n);
    printf("Сумма взвешенных сроков завершения (WSPTR): %d\n", totalWSPTR);

    free(tasks);
    free(tasksCopy); // Освобождаем память для копии
    return 0;
}

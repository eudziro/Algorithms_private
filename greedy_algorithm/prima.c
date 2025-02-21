#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define V 5 // Количество вершин

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int graph[V][V]) {
    int parent[V]; // Массив для хранения MST
    int key[V];    // Значения ключей
    int mstSet[V]; // Массив для отслеживания вершин в MST

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;    // Начинаем с первой вершины
    parent[0] = -1; // Первая вершина всегда корень MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("Ребра в MST (без кучи):\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d\n", parent[i], i);
    }
}

typedef struct {
    int vertex;
    int key;
} MinHeapNode;

typedef struct {
    int size;
    int capacity;
    int *pos;
    MinHeapNode **array;
} MinHeap;

MinHeapNode* newMinHeapNode(int v, int key) {
    MinHeapNode* minHeapNode = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    minHeapNode->vertex = v;
    minHeapNode->key = key;
    return minHeapNode;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->pos = (int*)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(capacity * sizeof(MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->key < minHeap->array[smallest]->key)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->key < minHeap->array[smallest]->key)
        smallest = right;

    if (smallest != idx) {
        MinHeapNode* smallestNode = minHeap->array[smallest];
        MinHeapNode* idxNode = minHeap->array[idx];

        minHeap->pos[smallestNode->vertex] = idx;
        minHeap->pos[idxNode->vertex] = smallest;

        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isEmpty(MinHeap* minHeap) {
    return minHeap->size == 0;
}

MinHeapNode* extractMin(MinHeap* minHeap) {
    if (isEmpty(minHeap))
        return NULL;

    MinHeapNode* root = minHeap->array[0];
    MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    minHeap->pos[root->vertex] = minHeap->size - 1;
    minHeap->pos[lastNode->vertex] = 0;

    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

void decreaseKey(MinHeap* minHeap, int v, int key) {
    int i = minHeap->pos[v];
    minHeap->array[i]->key = key;

    while (i && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key) {
        minHeap->pos[minHeap->array[i]->vertex] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->vertex] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int isInMinHeap(MinHeap* minHeap, int v) {
    return minHeap->pos[v] < minHeap->size;
}

void primMSTWithHeap(int graph[V][V]) {
    int parent[V];
    int key[V];
    MinHeap* minHeap = createMinHeap(V);

    for (int v = 0; v < V; v++) {
        key[v] = INT_MAX;
        parent[v] = -1;
        minHeap->array[v] = newMinHeapNode(v, key[v]);
        minHeap->pos[v] = v;
    }

    key[0] = 0;
    minHeap->array[0]->key = key[0];
    minHeap->size = V;

    while (!isEmpty(minHeap)) {
        MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->vertex;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && isInMinHeap(minHeap, v) && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
                decreaseKey(minHeap, v, key[v]);
            }
        }
    }

    printf("Ребра в MST (с кучей):\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d\n", parent[i], i);
    }
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    clock_t start, end;

    // Замер времени для алгоритма без кучи
    start = clock();
    printf("Алгоритм Прима без использования кучи:\n");
    primMST(graph);
    end = clock();
    double time_taken_no_heap = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Время выполнения (без кучи): %f секунд\n", time_taken_no_heap);

    // Замер времени для алгоритма с кучей
    start = clock();
    printf("\nАлгоритм Прима с использованием кучи:\n");
    primMSTWithHeap(graph);
    end = clock();
    double time_taken_with_heap = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Время выполнения (с кучей): %f секунд\n", time_taken_with_heap);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF INT_MAX

typedef struct {
    int vertex;
    int distance;
} Node;

typedef struct {
    Node* nodes[MAX_VERTICES];
    int size;
} MinHeap;

MinHeap* createMinHeap() {
    MinHeap* heap = malloc(sizeof(MinHeap));
    heap->size = 0;
    return heap;
}

void swap(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void insertMinHeap(MinHeap* heap, Node* node) {
    heap->nodes[heap->size] = node;
    int i = heap->size;
    heap->size++;

    while (i != 0 && heap->nodes[i]->distance < heap->nodes[(i - 1) / 2]->distance) {
        swap(&heap->nodes[i], &heap->nodes[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Node* extractMin(MinHeap* heap) {
    if (heap->size == 0) return NULL;

    Node* minNode = heap->nodes[0];
    heap->nodes[0] = heap->nodes[heap->size - 1];
    heap->size--;

    int i = 0;
    while (i < heap->size) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap->size && heap->nodes[left]->distance < heap->nodes[smallest]->distance) {
            smallest = left;
        }
        if (right < heap->size && heap->nodes[right]->distance < heap->nodes[smallest]->distance) {
            smallest = right;
        }
        if (smallest == i) break;

        swap(&heap->nodes[i], &heap->nodes[smallest]);
        i = smallest;
    }

    return minNode;
}

bool isEmpty(MinHeap* heap) {
    return heap->size == 0;
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices, int startVertex) {
    int distance[MAX_VERTICES];
    bool visited[MAX_VERTICES];

    for (int i = 0; i < numVertices; i++) {
        distance[i] = INF;
        visited[i] = false;
    }
    distance[startVertex] = 0;

    MinHeap* minHeap = createMinHeap();
    Node* startNode = malloc(sizeof(Node));
    startNode->vertex = startVertex;
    startNode->distance = 0;
    insertMinHeap(minHeap, startNode);

    while (!isEmpty(minHeap)) {
        Node* currentNode = extractMin(minHeap);
        int currentVertex = currentNode->vertex;

        if (visited[currentVertex]) {
            free(currentNode);
            continue;
        }
        visited[currentVertex] = true;
        free(currentNode);

        for (int v = 0; v < numVertices; v++) {
            if (graph[currentVertex][v] && !visited[v]) {
                int newDistance = distance[currentVertex] + graph[currentVertex][v];
                if (newDistance < distance[v]) {
                    distance[v] = newDistance;
                    Node* neighborNode = malloc(sizeof(Node));
                    neighborNode->vertex = v;
                    neighborNode->distance = newDistance;
                    insertMinHeap(minHeap, neighborNode);
                }
            }
        }
    }

    printf("Вершина\t\tРасстояние от начальной вершины\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d\t\t%d\n", i, distance[i]);
    }

    free(minHeap);
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 1, 0, 0, 0},
        {0, 1, 0, 2, 0, 0},
        {0, 0, 2, 0, 3, 0},
        {0, 0, 0, 3, 0, 1},
        {0, 0, 0, 0, 1, 0}
    };
    int numVertices = 6;

    printf("Алгоритм Дейкстры:\n");
    dijkstra(graph, numVertices, 0);

    return 0;
}

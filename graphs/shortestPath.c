#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF INT_MAX

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices, int startVertex) {
    int distance[MAX_VERTICES];
    bool visited[MAX_VERTICES];

    for (int i = 0; i < numVertices; i++) {
        distance[i] = INF;
        visited[i] = false;
    }
    distance[startVertex] = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int minDistance = INF;
        int minIndex;

        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && distance[v] <= minDistance) {
                minDistance = distance[v];
                minIndex = v;
            }
        }

        visited[minIndex] = true;

        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && graph[minIndex][v] && distance[minIndex] != INF &&
                distance[minIndex] + graph[minIndex][v] < distance[v]) {
                distance[v] = distance[minIndex] + graph[minIndex][v];
            }
        }
    }

    printf("Вершина\t\tРасстояние от начальной вершины\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d\t\t%d\n", i, distance[i]);
    }
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

    dijkstra(graph, numVertices, 0);

    return 0;
}

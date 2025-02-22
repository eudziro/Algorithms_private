#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 10000

typedef struct {
    int u, v, weight;
} Edge;

typedef struct {
    Edge edges[MAX_EDGES];
    int edgeCount;
} Graph;

void initializeGraph(Graph* graph, int edgeCount) {
    graph->edgeCount = edgeCount;
}

void addEdge(Graph* graph, int index, int u, int v, int weight) {
    graph->edges[index].u = u;
    graph->edges[index].v = v;
    graph->edges[index].weight = weight;
}

void bellmanFord(Graph* graph, int vertices, int source) {
    int* distance = (int*)malloc(vertices * sizeof(int));
    
    for (int i = 0; i < vertices; i++) {
        distance[i] = INT_MAX;
    }
    distance[source] = 0;

    for (int i = 1; i < vertices; i++) {
        for (int j = 0; j < graph->edgeCount; j++) {
            int u = graph->edges[j].u;
            int v = graph->edges[j].v;
            int weight = graph->edges[j].weight;

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    for (int j = 0; j < graph->edgeCount; j++) {
        int u = graph->edges[j].u;
        int v = graph->edges[j].v;
        int weight = graph->edges[j].weight;

        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            printf("Граф содержит отрицательный цикл\n");
            free(distance);
            return;
        }
    }

    printf("Расстояния от источника %d:\n", source);
    for (int i = 0; i < vertices; i++) {
        if (distance[i] == INT_MAX) {
            printf("До вершины %d: бесконечность\n", i);
        } else {
            printf("До вершины %d: %d\n", i, distance[i]);
        }
    }

    free(distance);
}

int main() {
    int vertices, edges;
    printf("Введите количество вершин и ребер: ");
    scanf("%d %d", &vertices, &edges);

    Graph graph;
    initializeGraph(&graph, edges);

    printf("Введите ребра (u, v, weight):\n");
    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        addEdge(&graph, i, u, v, weight);
    }

    int source;
    printf("Введите источник: ");
    scanf("%d", &source);

    bellmanFord(&graph, vertices, source);

    return 0;
}

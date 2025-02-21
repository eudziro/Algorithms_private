#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjLists[MAX_VERTICES];
    bool visited[MAX_VERTICES];
    int numVertices;
} Graph;

Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void dfsRecursive(Graph* graph, int vertex) {
    graph->visited[vertex] = true;
    printf("%d ", vertex);

    Node* adjList = graph->adjLists[vertex];
    while (adjList) {
        int adjVertex = adjList->vertex;
        if (!graph->visited[adjVertex]) {
            dfsRecursive(graph, adjVertex);
        }
        adjList = adjList->next;
    }
}

void dfsIterative(Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    int stack[MAX_VERTICES];
    int top = -1;

    stack[++top] = startVertex;

    while (top != -1) {
        int vertex = stack[top--];

        if (!visited[vertex]) {
            visited[vertex] = true;
            printf("%d ", vertex);
        }

        Node* adjList = graph->adjLists[vertex];
        while (adjList) {
            int adjVertex = adjList->vertex;
            if (!visited[adjVertex]) {
                stack[++top] = adjVertex;
            }
            adjList = adjList->next;
        }
    }
}

void benchmarkDFS(Graph* graph, int startVertex) {
    clock_t start, end;

    printf("Рекурсивный DFS: ");
    start = clock();
    dfsRecursive(graph, startVertex);
    end = clock();
    printf("\nВремя: %lf секунд\n", (double)(end - start) / CLOCKS_PER_SEC);

    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = false;
    }

    printf("Итеративный DFS: ");
    start = clock();
    dfsIterative(graph, startVertex);
    end = clock();
    printf("\nВремя: %lf секунд\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);

    printf("Бенчмаркинг DFS:\n");
    benchmarkDFS(graph, 0);
    printf("NOdifference");

    return 0;
}

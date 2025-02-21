#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void bfs(Graph* graph, int startVertex) {
    Node* adjList;
    Node* temp;
    int queue[MAX_VERTICES];
    int front = 0;
    int rear = 0;

    graph->visited[startVertex] = true;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("Visited %d\n", currentVertex);

        adjList = graph->adjLists[currentVertex];
        while (adjList) {
            int adjVertex = adjList->vertex;
            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }
            adjList = adjList->next;
        }
    }
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);

    printf("BFS starting from vertex 0:\n");
    bfs(graph, 0);

    return 0;
}

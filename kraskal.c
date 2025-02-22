#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int u, v, weight;
} Edge;

int compare(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int find(int parent[], int i) {
    if (parent[i] == -1) {
        return i;
    }
    return find(parent, parent[i]);
}

void unionSets(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    if (xset != yset) {
        parent[xset] = yset;
    }
}

void kruskalWithoutUnionFind(int n, Edge edges[], int m) {
    qsort(edges, m, sizeof(Edge), compare);
    
    int parent[n];
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }

    printf("Edges in the Minimum Spanning Tree (without Union-Find):\n");
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        int set_u = find(parent, u);
        int set_v = find(parent, v);

        if (set_u != set_v) {
            printf("%d -- %d == %d\n", u, v, edges[i].weight);
            parent[set_u] = set_v;
        }
    }
}

void kruskalWithUnionFind(int n, Edge edges[], int m) {
    qsort(edges, m, sizeof(Edge), compare);
    
    int parent[n];
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }

    printf("Edges in the Minimum Spanning Tree (with Union-Find):\n");
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(parent, u) != find(parent, v)) {
            printf("%d -- %d == %d\n", u, v, edges[i].weight);
            unionSets(parent, u, v);
        }
    }
}

int main() {
    int n = 4; // Количество вершин
    Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    int m = sizeof(edges) / sizeof(edges[0]);

    // Измерение времени для алгоритма без Union-Find
    clock_t start = clock();
    kruskalWithoutUnionFind(n, edges, m);
    clock_t end = clock();
    printf("Time taken without Union-Find: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Измерение времени для алгоритма с Union-Find
    start = clock();
    kruskalWithUnionFind(n, edges, m);
    end = clock();
    printf("Time taken with Union-Find: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

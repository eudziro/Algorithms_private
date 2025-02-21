#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *parent;
    int *rank;
    int size;
} UnionFind;

UnionFind* createUnionFind(int size) {
    UnionFind *uf = (UnionFind *)malloc(sizeof(UnionFind));
    uf->parent = (int *)malloc(size * sizeof(int));
    uf->rank = (int *)malloc(size * sizeof(int));
    uf->size = size;

    for (int i = 0; i < size; i++) {
        uf->parent[i] = i; // Каждый элемент является своим родителем
        uf->rank[i] = 0;    // Начальный ранг равен 0
    }

    return uf;
}

int find(UnionFind *uf, int p) {
    if (uf->parent[p] != p) {
        uf->parent[p] = find(uf, uf->parent[p]); // Сжатие путей
    }
    return uf->parent[p];
}

void unionSets(UnionFind *uf, int p, int q) {
    int rootP = find(uf, p);
    int rootQ = find(uf, q);

    if (rootP != rootQ) {
        // Объединяем деревья по рангу
        if (uf->rank[rootP] > uf->rank[rootQ]) {
            uf->parent[rootQ] = rootP;
        } else if (uf->rank[rootP] < uf->rank[rootQ]) {
            uf->parent[rootP] = rootQ;
        } else {
            uf->parent[rootQ] = rootP;
            uf->rank[rootP]++;
        }
    }
}

int connected(UnionFind *uf, int p, int q) {
    return find(uf, p) == find(uf, q);
}

void freeUnionFind(UnionFind *uf) {
    free(uf->parent);
    free(uf->rank);
    free(uf);
}

int main() {
    int size = 10;
    UnionFind *uf = createUnionFind(size);

    unionSets(uf, 1, 2);
    unionSets(uf, 2, 3);
    unionSets(uf, 4, 5);

    printf("1 и 3 соединены? %s\n", connected(uf, 1, 3) ? "Да" : "Нет");
    printf("1 и 4 соединены? %s\n", connected(uf, 1, 4) ? "Да" : "Нет");

    // Освобождение памяти
    freeUnionFind(uf);
    return 0;
}

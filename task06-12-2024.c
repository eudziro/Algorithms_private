#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

typedef struct {
    int key;
    int freq;
} Item;

int **cost;
int **root;

void optimalBST(Item items[], int n) {
    cost = (int **)malloc((n + 1) * sizeof(int *));
    root = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        cost[i] = (int *)malloc((n + 1) * sizeof(int));
        root[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    for (int i = 0; i <= n; i++) {
        cost[i][i] = 0;
    }

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            cost[i][j] = INT_MAX;

            int sumFreq = 0;
            for (int k = i; k <= j; k++) {
                sumFreq += items[k].freq;
            }

            for (int r = i; r <= j; r++) {
                int c = (r > i ? cost[i][r - 1] : 0) +
                        (r < j ? cost[r + 1][j] : 0) +
                        sumFreq;
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                    root[i][j] = r;
                }
            }
        }
    }
}

void printOptimalBST(int i, int j) {
    if (i > j) return;
    printf("Root of subtree [%d, %d]: %d\n", i, j, root[i][j]);
    printOptimalBST(i, root[i][j] - 1);
    printOptimalBST(root[i][j] + 1, j);
}

int main() {
    int n = 10; // Change this to a larger number for more testing
    Item *items = malloc(n * sizeof(Item));
    
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        items[i].key = rand() % 100; // Random keys between 0 and 99
        items[i].freq = rand() % 100; // Random frequencies between 0 and 99
    }

    optimalBST(items, n);
    printf("Optimal BST structure:\n");
    printOptimalBST(0, n - 1);

    free(items);
    return 0;
}

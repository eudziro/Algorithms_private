#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 1000

int knapsack(int weights[], int values[], int n, int W) {
    int dp[MAX_ITEMS + 1][MAX_WEIGHT + 1] = {0};

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = (values[i - 1] + dp[i - 1][w - weights[i - 1]] > dp[i - 1][w]) ?
                           (values[i - 1] + dp[i - 1][w - weights[i - 1]]) : dp[i - 1][w];
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

void reconstruct(int weights[], int values[], int n, int W) {
    int dp[MAX_ITEMS + 1][MAX_WEIGHT + 1] = {0};

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = (values[i - 1] + dp[i - 1][w - weights[i - 1]] > dp[i - 1][w]) ?
                           (values[i - 1] + dp[i - 1][w - weights[i - 1]]) : dp[i - 1][w];
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int w = W;
    printf("Выбранные предметы:\n");
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("Предмет %d (вес: %d, стоимость: %d)\n", i, weights[i - 1], values[i - 1]);
            w -= weights[i - 1];
        }
    }
}

int main() {
    int n = 100; // Количество предметов
    int weights[n];
    int values[n];
    int W = 500; // Максимальный вес рюкзака

    srand(time(NULL)); // Инициализация генератора случайных чисел

    for (int i = 0; i < n; i++) {
        weights[i] = rand() % 50 + 1; // Случайный вес от 1 до 50
        values[i] = rand() % 100 + 1; // Случайная стоимость от 1 до 100
    }

    int max_value = knapsack(weights, values, n, W);
    printf("Максимальная стоимость: %d\n", max_value);

    reconstruct(weights, values, n, W);

    return 0;
}

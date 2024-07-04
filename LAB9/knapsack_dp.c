#include <stdio.h>

#define N 4
#define W 7

// Structure to represent an object
struct Object {
    int weight;
    int profit;
};

// Function to perform 0/1 Knapsack using Dynamic Programming
void knapsack(struct Object objects[N], int dp[N+1][W+1]) {
    // Initialize dp table
    for (int i = 0; i <= N; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (objects[i-1].weight <= w)
                dp[i][w] = (objects[i-1].profit + dp[i-1][w-objects[i-1].weight] > dp[i-1][w]) ?
                           (objects[i-1].profit + dp[i-1][w-objects[i-1].weight]) :
                           dp[i-1][w];
            else
                dp[i][w] = dp[i-1][w];
        }
    }
}

// Function to print the selected objects
void printSelectedObjects(struct Object objects[N], int dp[N+1][W+1]) {
    int w = W;
    printf("Objects selected in the knapsack:\n");
    for (int i = N; i > 0 && w > 0; --i) {
        if (dp[i][w] != dp[i-1][w]) {
            printf("Object %d (weight = %d, profit = %d)\n", i, objects[i-1].weight, objects[i-1].profit);
            w -= objects[i-1].weight;
        }
    }
}

int main() {
    struct Object objects[N] = {
        {1, 1},
        {2, 6},
        {3, 10},
        {5, 16}
    };

    int dp[N+1][W+1];

    knapsack(objects, dp);

    printf("DP Table (Maximum Profits):\n");
    for (int i = 0; i <= N; ++i) {
        for (int w = 0; w <= W; ++w) {
            printf("%3d ", dp[i][w]);
        }
        printf("\n");
    }

    printf("\n");

    printSelectedObjects(objects, dp);

    return 0;
}

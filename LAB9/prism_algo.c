#include <stdio.h>

#define MAX 9999 // Infinity value for initialization

void prims(int n, int cost[][n]) {
    int s[n]; // To track visited nodes
    int d[n]; // Shortest distance from source to each node
    int p[n]; // Shortest path parent array
    int T[n-1][2]; // Array to store the edges of MST
    int sum = 0; // Total cost of MST
    int source, i, j, k, u, min;

    // Step 1: Find a source vertex with the least edge going out
    min = MAX;
    source = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (cost[i][j] != 0 && cost[i][j] < min) {
                min = cost[i][j];
                source = i;
            }
        }
    }

    // Step 2: Initialization
    for (i = 0; i < n; i++) {
        s[i] = 0; // Not visited
        d[i] = cost[source][i];
        p[i] = source;
    }

    // Step 3: Add source to s (visited set)
    s[source] = 1;

    // Step 4: Find the Minimum Spanning Tree if exists
    sum = 0;
    k = 0;
    for (i = 1; i < n; i++) {
        // Find u such that d[u] is minimum and u is in V - s
        min = MAX;
        u = -1;
        for (j = 0; j < n; j++) {
            if (s[j] == 0 && d[j] <= min) {
                min = d[j];
                u = j;
            }
        }

        // Select an edge with the least cost
        T[k][0] = u;
        T[k][1] = p[u];
        k++;

        // Add the cost associated with the edge to get total cost of MST
        sum = sum + cost[u][p[u]];

        // Add u to s (visited set)
        s[u] = 1;

        // Update d and p for each vertex v in V - s
        for (j = 0; j < n; j++) {
            if (s[j] == 0 && cost[u][j] < d[j]) {
                d[j] = cost[u][j];
                p[j] = u;
            }
        }
    }

    // Step 5: Check for the existence of spanning tree
    if (sum >= MAX) {
        printf("Spanning tree does not exist\n");
    } else {
        printf("Spanning tree exists and MST is:\n");
        for (i = 0; i < n - 1; i++) {
            printf("(%d, %d)\n", T[i][0], T[i][1]);
        }
        printf("The cost of Spanning tree (MST) is %d\n", sum);
    }
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];
    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    prims(n, cost);

    return 0;
}

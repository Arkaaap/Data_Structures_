#include <stdio.h>
#include <stdlib.h>
#define inf 999999

void dijkstra(int n, int s, int cost[10][10], int dist[10]) {
    int i, j, v, min, visited[10], count = 1;

    for (i = 1; i <= n; i++) {
        visited[i] = 0;
        dist[i] = cost[s][i];
    }

    visited[s] = 1;
    dist[s] = 0;

    while (count < n) {
        min = inf;
        for (i = 1; i <= n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                v = i;
            }
        }

        visited[v] = 1;
        count++;

        for (i = 1; i <= n; i++) {
            if (!visited[i] && dist[i] > dist[v] + cost[v][i]) {
                dist[i] = dist[v] + cost[v][i];
            }
        }
    }
}

int main(void) {
    int n, s, cost[10][10], i, j, dist[10];

    printf("Enter the number of nodes in your graph: ");
    scanf("%d", &n);

    printf("\n-- Enter the adjacency matrix --\n");
    printf("(Enter 999999 for no direct connection)\n");

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("Enter cost from node %d to node %d: ", i, j);
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter the source node (1 to %d): ", n);
    scanf("%d", &s);

    if (s < 1 || s > n) {
        printf("Invalid source node. It must be between 1 and %d.\n", n);
        return -1;
    }

    dijkstra(n, s, cost, dist);

    printf("\n--- Shortest paths from node %d ---\n", s);
    for (i = 1; i <= n; i++) {
        if (i != s) {
            printf("%d --> %d = %d\n", s, i, dist[i]);
        }
    }

    return 0;
}

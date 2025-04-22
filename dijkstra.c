#include <stdio.h>
#include <stdlib.h>
#define INF 9999


void dijkstra(int n, int s, int cost[10][10], int dist[10]) {
    int i, j, count = 0, visited[10] = {0}, v, min;

    for (i = 0; i < n; i++) {
        visited[i] = 0;
        dist[i] = cost[s][i];
    }

    visited[s] = 1;
    dist[s] = 0;

    while (count < n - 1) {
        min = INF;
        for (i = 0; i < n; i++) {
            if (visited[i] == 0 && dist[i] < min) {
                min = dist[i];
                v = i;
            }
        }
        visited[v] = 1;
        count++;

        for (i = 0; i < n; i++) {
            if (visited[i] == 0 && dist[v] + cost[v][i] < dist[i]) {
                dist[i] = dist[v] + cost[v][i];
            }
        }
    }
}

int main (void)
{
    int i,j,n,s,cost[10][10],dist[10];
    
    printf ("Enter The no of nodes :");
    scanf ("%d",&n);
    
    printf ("\n--Reading the cost adajceny matrix--\n");
    
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            printf ("Enter The %d-> %d ",i,j);
            scanf ("%d",&cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }
    
    printf ("Enter The source node %d-->%d",(0),(n));
    scanf ("%d",&s);
    
    dijkstra (n,s,cost,dist);
    
    printf ("\nPrinting The distance ...\n");
    
    for (i=1;i<=n;i++)
    {
        printf ("%d-->%d = %d\n",s,i,dist[i]);
    }
    
    return (0);
}





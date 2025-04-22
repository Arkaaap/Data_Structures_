#include <stdio.h>
#include <stdlib.h>
#define inf 999999

void dijkstra(int n,int s,int cost [10][10],int dist[10])
{
    int i,j,v,min , visited [10],count = 1;
    
    
    for (i=1;i<=n;i++)
    {
        visited[i] = 0 ;
        dist[i] = cost[s][i];
    }
    
    visited[s] = 1;
    dist[s] = 0 ;
    
    while (count<=n)
    {
        min = inf;
        for (i=1;i<=n;i++)
        {
            if (!visited[i] && dist[i]<min)
            {
                min = dist[i];
                v =i;
            }
        }
        
        count++;
        for (i=1;i<=n;i++)
        {
            if (dist[i]>dist[v]+cost[v][i])
            {
                dist[i] = (dist[v]+cost[v][i]);
            }
        }
    }
}







int main (void)
{
    int n , s,cost[10][10],i,j,dist[10];
    
    printf ("Enter The nodes in yoour graph :");
    scanf ("%d",&n);
    
    printf ("\n--Reading The Graph from user--\n");
    
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            printf ("Enter The %d'st row , %d'st col\t",i,j);
            
            scanf ("%d",&cost[i][j]);
        }
    }
    
    if (0<=n){
    printf ("Enter The source node %d-->%d\t",(0),(n));
    scanf ("%d",&s);
    }
    else {
        printf ("Source v can only be chosen from %d-->%d",(0),(n));
        return (-1);
    }
    
    dijkstra (n,s,cost,dist);
    printf ("Shortest path from %d ",s);
    
    for (i=1;i<=n;i++)
    {
        if (s!=i)
        {
            printf ("%d-->%d = %d\n",s,i,dist[i]);
        }
    }
    
    return (0);
    
   

    
}

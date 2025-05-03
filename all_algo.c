/*AUTHORRR ARKAAP (WILL TURN IT INTO COOL CLI PROJECT WITH SOME BANNER STUFFS && gotta give a menu driven program */





/*Merge sort , heap sort , selection sort , linear search , binary search , tsp , dijkstra */


#include <stdio.h>
#include <stdlib.h>

#define inf 99999

int n = 4;

int graph [10][10] = {
    {0,5,1,15},
    {4,0,5,6},
    {3,4,0,8},
    {5,6,7,0}
};



void merge (int *a,int mid , int l,int h)
{
    int i,j,k,b[100];
    i = l,j = mid +1,k = l;
    
    while (i<=mid && j<=h)
    {
        if (a[i]<a[j])
        {
            b[k++] = a[i++];
        }
        else {
            b[k++] = a[j++];
        }
    }
    
    
    while (i<=mid)
    {
        b[k++] = a[i++];
    }
    
    while (j<=h)
    {
        b[k++] = a[j++];
    }
    
    
    for (i=l;i<=h;i++)
    {
        a[i] = b[i];
    }
}




void mergesort (int *a,int l,int h)
{
    int mid ;
    if (l<h)
    {
        mid = (l+h)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        merge (a,mid,l,h);
    }
}


void selection (int *a,int n)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if (a[i]>a[j])
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}


void bubble (int *a,int n)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if (a[j]>a[j+1])
            {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}


void heap (int *a,int n,int i)
{
    int current = i,l = 2*i+1, r = 2*i+2;
    
        if (l<n && a[l]>a[current])
        {
            current = l;
        }
        
        if (r<n && a[r]>a[current])
        {
            current = r;
        }
        
        if (current!=i)
        {
            int t = a[i];
            a[i] = a[current];
                a[current] = t;
                heap(a,n,current);
        }
}


void heapify (int *a,int n)
{
    int i;
    for (i=(n/2)-1;i>=0;i--)
    {
        heap(a,n,i);
    }
    
    for (i=(n-1);i>0;i--)
    {
        int t = a[0];
        a[0] = a[i];
        a[i] = t;
        heap(a,i,0);
    }
}


int search (int *a,int n,int x)
{
    int i;
    for (i=0;i<n;i++)
    {
        if (a[i] == x)
        {
            return (i);
        }
    }
    return (-1);
}



int binary (int *a,int n,int i,int j,int x)
{
    int mid ;
    
    if (i<=j)
    {
        mid = (i+j)/2;
        if (a[mid] == x)
        {
            return (mid);
        }
        
        else if (a[mid]>x)
        {
            j = mid -1;
            return binary(a,n,i,j,x);
        }
        else {
            i = mid +1;
            return (binary(a,n,i,j,x));
        }
    }
    
    
    return (-1);
}
void print (int *a,int n)
{
    for (int i=0;i<n;i++){
    printf ("%d\t",a[i]);
}
}


int min (int a,int b)
{
    return (a<b ? a:b);
}


int tsp (int *visited,int count , int cupos,int cost)
{
    if (n == count)
    {
        return (cost+graph[cupos][0]);
    }
    
    else {
        int ans = inf ;
        
            for (int city = 0 ;city<n ; city++)
            {
                if (!visited[city])
                {
                    visited[city] = 1;
                    int newcost = cost+graph[cupos][city];
                    int temp = tsp (visited,count +1,city,newcost);
                    ans = min (ans,temp);
                    visited[city]  = 0;
                }
            }
            return (ans);
    }
}


void dijkstra (int cost [10][10],int *dist,int n,int s)
{
    int i,j,min,v,count = 1,visited [10];
    
    for (i=0;i<n;i++)
    {
        visited[i] = 0 ;
        dist[i] = cost[s][i];
    }
    
    visited[s] = 1;
    dist[s] = 0;
    
    while (count < n)
    {
        min = inf ;
        for (i=0;i<n;i++)
        {
            if (visited[i] ==0 && dist[i]<min)
            {
                min = dist[i];
                v = i;
            }
        }
        
        visited[v] = 1;
        count ++;
        
            for (i=0;i<n;i++)
            {
                if (!visited[i] && dist [v]+cost[v][i]<dist[i])
                {
                    dist[i] = dist[v]+cost[v][i];
                }
            }
    }
}


int main (void)
{
    
    
    int i,j,k,cost [10][10],dist [10],s,n;
    
    printf ("Enter The No Of Nodes :");
    scanf ("%d",&n);
    printf ("--Reading The cost Matrix--");
    
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                printf ("Enter The %d'th row and %d'th col",i+1,j+1);
                scanf ("%d",&cost[i][j]);
                if (cost[i][j] ==0 )
                {
                    cost[i][j] = inf;
                    
                }
            }
        }
        
        printf ("Enter The source vertex (%d)--> (%d) ",0,n);
        scanf ("%d",&s);
        dijkstra(cost,dist , n,s);
        
        for (i=0;i<n;i++)
        {
            printf ("The shortest path from %d-->%d = %d\n",s,i,dist[i]);
        }
        
        
        return (0);
    
    /*int visited_nodes [10] = {0};
    visited_nodes[0] = 1;
    printf ("%d\t",tsp(visited_nodes,1,0,0));
    return (0);
    int a[] = {5,4,3,2,1};
    int s = sizeof(a)/sizeof(a[0]);
    heapify(a,s);
    print (a,s);
    printf ("\n");
    int x,i,j;
    printf ("Enter The target :");
    scanf ("%d",&x);
    i = 0 , j = sizeof(a)/sizeof(a[0])-1;
    
    int t = binary(a,s,i,j,x);
    
    if (t == -1)
    {
        printf ("Not Found !!");
    }
    else {
        printf ("%d\t",t);
    }
    
    
    return (0);
    */
}

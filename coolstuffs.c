/*MERGE SORT , HEAP SORT , SELECTION SORT , BUBBLE SORT , LINEAR SEARCH , BINARY SEARCH , TSP , DIJKSTRA*/


#include <stdio.h>
#include<stdlib.h>
#define inf 999999

int n = 4;

int graph [10][10] = {
    {0,5,10,15},
    {9,0,7,5},
    {6,8,0,9},
    {12,10,8,0}
};

int min (int a,int b)
{
    return (a<b ? a:b);
}

void heap (int *a,int n,int i)
{
    int lar = i,l = 2*i+1,r = 2*i+2;
    if (l<n && a[l]>a[lar])
    {
        lar = l;
    }
    
    if (r<n && a[r]>a[lar])
    {
        lar = r;
    }
    
    if (i!=lar)
    {
        int t = a[i];
        a[i] = a[lar];
        a[lar] = t;
        heap(a,n,lar);
    }
}



void heapify (int *a,int n)
{
    for (int i=(n/2)-1;i>=0;i--)
    {
        heap(a,n,i);
    }
    
    
    for (int i=(n-1);i>0;i--)
    {
        int t = a[0];
        a[0] = a[i];
        a[i] = t;
        heap(a,i,0);
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

int linear (int *a,int n,int x)
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


int bin_search (int *a,int n,int i,int j,int x)
{
    int mid ;
    if (i<=j){
    mid = (i+j)/2;
    if (a[mid] == x)
    {
        return (mid);
    }
    
    if (a[mid]>x)
    {
        j = mid-1;
        return (bin_search(a,n,i,j,x));
    }
    i= mid+1;
    return (bin_search(a,n,i,j,x));
    
}

return (-1);
}

void merge (int *a,int mid,int l,int h)
{
    int i,k,j,b[100];
    i = l,k = l,j = mid+1;
    
    while (i<=mid && j<=h)
    {
        if (a[i]<a[j])
        {
            b[k] = a[i];
            i++,k++;
        }
        b[k] = a[j];
        j++,k++;
    }
    
    while (i<=mid)
    {
        b[k] = a[i];
        i++,k++;
    }
    
    while (j<=h)
    {
        b[k] = a[j];
        j++,k++;
    }
    
    for (i=l;i<=h;i++)
    {
        a[i] = b[i];
    }
}


void merge_sort (int *a,int l,int h)
{
    int mid;
    
    if (l<h)
    {
        mid = (l+h)/2;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,h);
        merge(a,mid,l,h);
    }
}



int tsp (int *visited , int count ,int cost , int cupos)
{
    if (n == count)
    {
        return (cost+graph[cupos][0]);
    }
    
    int ans  = inf;
    
    for (int city = 0 ;city<n;city++)
    {
        if (visited[city] == 0)
        {
            visited[city] = 1;
            int newcost = cost+graph[cupos][city];
            int temp = tsp(visited,count+1,newcost,city);
            ans = min (ans,temp);
            visited[city] = 0;
        }
    }
    
    return (ans);
}



void print (int *a,int n)
{
    for (int i=0;i<n;i++){
        printf ("%d\t",a[i]);
    }
    
}






void dijkstra(int n,int s,int cost [10][10],int dist[10])
{
    int i,j,v,min , visited [10],count = 1;
    
    
    for (i=1;i<=n;i++)
    {
        visited[i] = 0 ;
        dist[i] = cost[s][i];//initialzation
    }
    
    visited[s] = 1;    //start visiting 
    dist[s] = 0 ;
    
    while (count<=n)
    {
        min = inf;
        for (i=1;i<=n;i++)
        {
            if (!visited[i] && dist[i]<min)    //checking if the vertex is valid or not by checking the cuurent vertex is visited and the dist vector's current vertex is = , > inf if if'ts not then valid ..
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
                dist[i] = (dist[v]+cost[v][i]);///relaxation 
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



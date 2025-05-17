#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define inf INT_MAX

 int n = 4;


int graph [5][5]= {
    {0,5,1,10},
    {2,0,3,4},
    {3,4,0,7},
    {5,6,7,0}
    
};


void merge (int *a,int mid,int l,int h)
{
    int i,j,k,b[100];
    i = l, j = mid+1,k = l;
    
    while (i<=mid && j<=h)
    {
        if (a[i]<a[j]){
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



void merge_sort (int *a,int l,int h)
{
    int mid;
    if (l<h)
    {
        mid = (l+h)/2;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,h);
        merge (a,mid,l,h);
    }
}



void heap (int *a,int n,int i)
{
    int current = i, l = i*2+1,r = i*2+2;
    
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
    for (i=(n/2)-1;i>=0 ; i--)
    {
        heap(a,n,i);
    }
    
    for (i=(n-1);i>0 ;i--)
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
        int minidx  = i ;
        for (j=i+1;j<n;j++)
        {
            if (a[j]<a[minidx])
            {
                int t = a[j];
                a[j] = a[minidx];
                a[minidx] = t;
            }
        }
    }
}



void bubble (int *a,int n)
{
    int i,j;
    bool swapped ;
    for (i=0;i<n-1;i++)
    {
        swapped = 0;
        for (j=0;j<n-i-1;j++)
        {
            if (a[j]>a[j+1])
            {
                int t = a[j];
                a[j]= a[j+1];
                a[j+1] = t;
            }
            swapped= 1;
        }
        
         if(!swapped && swapped != 1)
    {
        break;
    }
    
   
    }
}



void insertion (int *a,int n)
{
    int i,j,key ;
    
    for (i=0;i<n;i++)
    {
        key = a[i];
        j = i-1;
        
        while (j>=0 && a[j]>key)
        {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;
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


int binary_search (int *a,int n,int i,int j,int x)
{
    
    
    int mid;
    if (i<=j)
    {
        mid = (i+j)/2;
        if (a[mid] == x)
        {
            return (mid);
        }
        
        else if (a[mid]>x)
        {
            j = mid-1;
            return (binary_search(a,n,i,j,x));
        }
        else {
            i = mid+1;
            return (binary_search(a,n,i,j,x));
        }
    }
    
    return (-1);
    
}



int Min(int *a, int l, int h)
{
    
    if (l>h)
    {
        return (-1);
    }
    
    if ((h-l)==1)
    {
        if (a[l]<a[h])
        {
            return (a[l]);
        }
        else {
            return (a[h]);
        }
    }
    
    
    if (l == h)
        return a[l];

    int mid = (l + h) / 2;
    int leftMin = Min(a, l, mid);
    int rightMin = Min(a, mid + 1, h);
    
    return (leftMin < rightMin) ? leftMin : rightMin;
}




int Max(int *a, int l, int h)
{
    
    if (l>h)
    {
        return (-1);
    }
    
    
    if (l == h)
        return a[l];
        

    if ((h-l)==1)
    {
        if (a[l]>a[h])
        {
            return (a[l]);
        }
        else {
            return (a[h]);
        }
    }
    
        

    int mid = (l + h) / 2;
    int leftMax = Max(a, l, mid);
    int rightMax = Max(a, mid + 1, h);

    return (leftMax > rightMax) ? leftMax : rightMax;
}










int min (int a,int b)
{
    return (a<b ? a:b);
}




int tsp (int *visited , int count ,int cupos,int cost)
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
                visited[city] = 0 ;
            }
        }
        
        return (ans);
    }
}





void dijkstra (int *dist , int cost [10][10],int n,int s)
{
    int i,j,k,min, v, count = 1,visited [10];
    
    for (i=0;i<n;i++)
    {
        visited[i] = 0 ;
        dist[i] = cost[s][i];
    }
    
    visited[s] = 1;
    dist[s] = 0 ;
    
        while (count < n)
        {
            min = inf ;
            for (i=0;i<n;i++)
            {
                if (!visited[i] && dist[i]<min)
                {
                    min = dist[i];
                    v = i ;
                }
            }
            
            visited[v] = 1;
            count ++;
                for (i=0;i<n;i++)
                {
                    if (!visited[i] && dist[v] + cost[v][i] < dist[i])
                    {
                        dist[i] = dist[v]+cost[v][i];
                    }
                }
        }
}







void print (int *a,int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf ("%d\t",a[i]);
    }
}





int main (void)
{
    int visited_nodes[10] = {0};
    visited_nodes[0] = 1;
    printf ("%d\t",tsp(visited_nodes,1,0,0));
    return (0);
    int a[] = {5,4,3,2,1,-9,8,7,90,88,782,8};
    int n = sizeof(a)/sizeof(a[0]);
    printf ("%d\t",Max (a,(0),(n)));
    insertion(a,(n));
    //print (a,(n));
    return (0);
    
    
}

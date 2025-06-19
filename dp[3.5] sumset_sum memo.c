#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int t[100][1001];



bool subset_sum (int *arr,int sum ,int n)
{
    if (n == 0 )
    {
        return false;
    }
    
    if (sum == 0 )
    {
        return true;
    }
    
    if (t[n][sum]!=-1)
    {
        return (t[n][sum]);
    }
    if (arr[n-1]<=sum)
    {
        t[n][sum] = subset_sum(arr,sum-arr[n-1],n-1) || subset_sum(arr,sum,n-1);
    }
    
    else {
        t[n][sum] = subset_sum(arr,sum,n-1);
    }
    
    return (t[n][sum]);
}

int main (void)
{
    int arr[] = {2,3,7,8,10};
    int sum = 11;
    int n = sizeof(arr)/sizeof(arr[0]);
    int i,j;
    memset (t,-1,sizeof(t));
    
    
    printf ("%d\t",subset_sum(arr,sum,n));
    return (0);
}

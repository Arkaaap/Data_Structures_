#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <limits.h>
using namespace std;
int t[100][1001];




int min(int a,int b)
{
    return (a<b ? a:b);
}


bool min_subset_sum (int a[],int n)
{
    int i,j;
    int sum = 0 ;
    for (i=0;i<n;i++)
    {
        sum = sum+a[i]; // sigma (arr[i])
    }
    
    
    for (i=0;i<n+1;i++)
    {
        for (j=0;j<sum+1;j++)
        {
            if (i==0)
            {
                t[i][j] =  0;
            }
            if (j==0)               //Initialize the dp table 
            {
                t[i][j] = 1;
            }
        }
    }
    
    
    
    for (i=0;i<n+1;i++)
    {
        for (j=0;j<sum+1;j++)
        {
            if (a[i-1]<=j)
            {
                t[i][j] = t[i-1] [j-a[i-1]] || t[i-1] [j];  // Logic 
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    
    int mini = INT_MAX;
    
    for (j=0;j<sum/2;j++)
    {
        if (t[i][j] ==1) // last row of the dp table 
        {
            mini  = min(mini,abs(sum-2*j));  // |s1- s2| = 2*min_subset_sum / 2s sum 
        }
        
    }
    
    return (mini);
    
    
}



int main (void)
{
    int a[] = {1,6,11,8};
    int n = sizeof(a)/sizeof(a[0]);
    
    if (min_subset_sum){ printf ("%d\t",min_subset_sum(a,n));}
    return (0);
}

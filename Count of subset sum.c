/*Same shit as subset sum but it's sending the count of subset which are equals to target sum*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int t [100][1001];

int count_subset_sum(int *arr,int sum,int n){


int i,j;
for (i=0;i<n+1;i++)
{
    for (j=0;j<sum+1;j++)
    {
        if (j==0)
        {
            t[i][j] = 1;
        }
        else if (i==0)
        {
            t[i][j] = 0;
        }
        
        else if (arr[i-1]<=j)
        {
            t[i][j] = (t[i-1][j] + t[i-1] [j-arr[i-1]]);
        }
        
        else {
            t[i][j] = t[i-1] [j];
        }
    }
}

return (t[n][sum]);


}




int main (void)
{
    int arr [] = {1, 2, 3, 3};
    int sum = 6;
    int n = sizeof(arr)/sizeof(arr[0]);
    //memset (t,-1,sizeof(t));
    
    for (int i=0;i<=n;i++)
    {
        for (int j=0;j<=sum;j++)
        {
            t[i][j] = -1;
        }
    }
    
    printf ("%d",count_subset_sum(arr,sum,n));
    return (0);
}

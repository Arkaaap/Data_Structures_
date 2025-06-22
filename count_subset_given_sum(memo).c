/*Same shit as subset sum but it's sending the count of subset which are equals to target sum*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int t [100][1001];

int count_subset_sum(int *arr,int sum,int n){



if (sum==0)
{
    return (1);
}


else if  (n==0)
{
    return (0);
}



if (t[n][sum] != -1)
{
    return (t[n][sum]);
}
else if (arr[n-1]<=sum)
{
    t[n][sum] = count_subset_sum(arr,sum,n-1) + count_subset_sum(arr,sum-arr[n-1],n-1); 
}

else {
    t[n][sum] = count_subset_sum(arr,sum,n-1);
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

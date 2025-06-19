#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int t[100][1001];

int main (void)
{
    int arr[] = {2,3,7,8,10};
    int sum = 11;
    int n = sizeof(arr)/sizeof(arr[0]);
    int i,j;
    for (i=0;i<n+1;i++)
    {
        for (j=0;j<sum+1;j++)
        {
            if (i==0)
            {
                t[i][j]= false;
                
            }
            
            if (j == 0)
            {
                t[i][j] = true;
            }
            
            if (arr[i-1]<=j)
            {
                t[i][j] = t[i][j-arr[i-1]] || t[i-1][j];
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    
    printf ("%d\t",t[n][sum]);
    return (0);
}

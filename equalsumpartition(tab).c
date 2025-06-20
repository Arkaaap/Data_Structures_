#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int t[100][1001];

//subset function for finding the equal sum partition if sum is even 
bool subset_sum (int *arr,int sum,int n )
{
    int i,j;
    
    for (i=0;i<n+1;i++)
    {
        for (j=0;j<sum+1;j++)
        {
            if (i==0)
            {
                t[i][j] = false;
            }
            if (j==0)
            {
                t[i][j] = true;
            }
            
            else if (arr[i-1]<=j)
            {
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    return (t[n][sum]);
}



int main (void)
{
    int arr[] = {7,5,11,5};//array elements 
    int n = sizeof(arr)/sizeof(arr[0]); // size 
    int sum = 0 ;//sum 
    for (int i=0;i<n;i++)
    {
        sum = sum+arr[i]; // summing up the elements into the array let's assume 22
    }
    
    
    if (sum %2 !=0)
    {
        printf ("false"); //22 is even so this condition will not hit hich means we can find two equal partition 
    }
    
    else { // for finding two equal partition 
        bool result = subset_sum(arr,sum/2,n);//we are finding one subset sum and hoping another will be solved by itselt auomatically lets say 
                                              // 22/2 = 11 so if 11 is found another subest eventually ill be 11 and that'd be found too 
        printf (result ? "true":"false"); // is the function retus true then true elese false 
    }

    
}

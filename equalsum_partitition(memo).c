#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int t[100][1001];

//subset function for finding the equal sum partition if sum is even 
bool subset_sum (int *arr,int sum,int n )
{
    if (n==0)
    {
        return (false);
    }
    if (sum==0){
        return (true);
    }
    
    if (t[n][sum] !=-1)
    {
        return (t[n][sum]);//if any of the cell is having value which is not -1 it means it have a valid value so we are returning that 
    }
    
    else if (arr[n-1]<=sum)
    {
        t[n][sum] = subset_sum(arr,sum-arr[n-1],n-1) ||subset_sum(arr,sum,n-1);
    }
    else {
        t[n][sum] = subset_sum(arr,sum,n-1);
    }
    
    return (t[n][sum]);
}



int main (void)
{
    int arr[] = {1,5,11,5};//array elements 
    int n = sizeof(arr)/sizeof(arr[0]); // size 
    int sum = 0 ;//sum 
    
    memset (t,-1,sizeof(t));//initializing whole table with -1 assuming (the values are unknown) 
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

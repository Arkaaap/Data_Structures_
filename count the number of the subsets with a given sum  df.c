#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>

int t[100][1001];


int Sum(int *arr,int n)
{
    int i;
    int sum = 0 ;
    for (i=0;i<n;i++)
    {
        sum = sum+arr[i];
    }
    
    return (sum);
}

//Function to find and count the number of the subsets with a given sum  d/f (memo) 
int subset_sum(int *arr,int n,int sum)
{
    if (sum == 0 )
    {
         return (1); 
    }
    if (n == 0 )
    {
        return (0);//empty set or null set 
    }
    
    if (t[n][sum] != 0)
    {
        return (t[n][sum]); // if there are any valid value so we are returning that value 
    }
    
    else if (arr[n-1]<=sum)
    {
        t[n][sum] = subset_sum(arr,n-1,sum-arr[n-1])+ subset_sum(arr,n-1,sum);//Include that set or exclude 
    }
    else {
        t[n][sum] = subset_sum(arr,n-1,sum);//Exclude that set 
    }
    
    return (t[n][sum]);  // returning the table 
}




int main (void){
int arr[] = {1,1,2,3};
int diff = 1;
int n = sizeof(arr)/sizeof(arr[0]);
int sum = diff + Sum(arr,n)/2;// reducted problem (s1-s2) to { diff+ sigma(arry[i]) /2 };
if (sum < 0 || Sum(arr,n)%2!=0)
{
    printf ("0\n");    //if sum is negative or not an integer 
}


memset (t,(0),sizeof(t)); // Initilize the dp table with 0 
printf ("%d\t",subset_sum(arr,n,sum));
return (0);
}

/* *Author* Arkaaap *Date* 19/06/2003 *problem description* Array is given and a sum is given let's say 11 we have to sum the subsets of the array such that subsets's sum should be equal to the sum 
The problem is very much lookalike 0/1 knapsack where we are given two array's val , weight and we have to put the element in abag or knapsack such that the 
    the m is not execceded of the bag and the profit will be maximized */


/*Identification of 0/1 knapsack is similar to this subset problem .
    1.choices are given either we pick an element or do'nt pick an elemnt 
    2.sum and m is given 
    3.optimized answer is required 
    4. we have choices either we take an element or do not take an element in this case we either take a number or do not take a number 
    5. there were two arrays value , weight array but the size is n similarly we have one array which is array itself which contains element of numbers 
same shit n size even though array was taken two in knapsack we always take an n size array similarly in this case it is happening 
    6. these were some of points indentifying problems how it's similar to knappsack 
    
    */








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

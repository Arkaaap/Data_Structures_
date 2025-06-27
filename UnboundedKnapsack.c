#include <stdio.h>
#include <stdlib.h>
int t[100][1001];//table 


int max (int a,int b)
{
    return (a>b ? a:b);//returns max 
}

int main (void)
{
    
    int wt[] = {1, 3, 4, 5};//weight array 
    int val [] = {10, 40, 50, 70};//value array 
    int m = 8;//capacity of knapsack 
    int n = sizeof(val)/sizeof(val[0]);//size 
    int i,j;
    
    
    
    for (i=0;i<n+1;i++)
    {
        for (j=0;j<m+1;j++)
        {
            t[i][j] = -1;//set all cellls in table with -1 (memset(t,(-1),sizeof(t)))
        }
    }
    
    
    
    for (i=0;i<n+1;i++)
    {
        for (j=0;j<m+1;j++)
        {
            if (i==0 || j==0)
            {
                t[i][j] = 0 ;//initilizing the table row and col with 0 bc if array is null then 0 (i) if capacity is 0 then also 0 (j)
            }
        }
    }
    for (i=1;i<n+1;i++)
    {
        for (j=0;j<m+1;j++)
        {
            if (wt[i-1]<=j)
            {
                t[i][j] = max(val[i-1]+ t[i][j-wt[i-1]],t[i-1][j]);//we are either taking an element or not taking it if we are not taking it it's 
                                                                   // processed and if e are taking it e might take another occurence of the same item .main difference of unbounded and 0-1 knapsack
            }
            else {
                t[i][j] = t[i-1][j];// we are not taking maybe the iteam is 10 kg and we got 8kg knapsack :) 
            }
        }
        
    }
    
    
    
    printf ("%d\t",t[n][m]);//returning the last cell 
    return (0);
}

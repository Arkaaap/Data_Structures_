/*Author Arkaaap date 5/19/25 time 10:32 am program : knapsack(0/1) using dp */

#include <stdio.h>
#include <stdlib.h>

int dp [100][1000];


int max (int a,int b)
{
    return (a>b ? a:b);
}


int knapsack (int *weight , int *profit , int m,int n)
{
    if (n == 0 || m == 0 )
    {
        return (0);//if no of elemnts 0 and bag's capacity is 0 then returns (0);
    }
    
    
    if (dp[n][m]!=-1)
    {
        return (dp[n][m]);// if particular any cell of table doesn't contain -1 then it's a valid value return that sucker 
    }
    
if (weight[n-1]<=m) // [n-1]'th elemnt is capable to getting into the bag and it doesn't exceed the bag's capacity 
{
dp[n][m] = max (profit[n-1] + knapsack(weight,profit,m-weight [n-1],n-1),
        knapsack(weight,profit,m,n-1)); //finds out the maximum one and store them into dp table .(memoization)
}
    
    else if (weight[n-1]> m)
    {
        dp[n][m] = knapsack(weight,profit,m,n-1);//if the current elemnt is greater than bag's capacity we are not taking that shit so just recursive call
    }
    
    return (dp[n][m]);
    
    
}





int main (void)
{
    int weight [] = {4,8,6};
    int profit [] = {10,60,100};
    int m = 6;//capacity of the bag 
    int n = sizeof(profit)/sizeof(profit[0]);// size of the weight array or profit array 
    
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            dp[n][m]= -1;// initilize them with -1 for the tabular generation 
        }
    }
    
    printf ("%d\t",knapsack(weight,profit,m,n));
    return (0);
}

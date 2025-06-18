#include <stdio.h>
#include <stdlib.h>
int t[100][1001];


int max (int a,int b)
{
    return (a>b ? a:b);
}


int main (void)
{
    int n,m = 7 ;
    
    int wt [] = {1,2,3,4,5};
    int val[] = {6,10,100,10,50};
    
    n = sizeof(wt)/sizeof(wt[0]);
    
    
    int i,j;
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            t[i][j] = -1;
        }
    }
    
    
    
    for (i=1;i<n+1;i++)
    {
        for (j=1;j<m+1;j++)
        {
            if (i==0 || j == 0)
            {
                t[i][j] = 0;
            }
            if (wt[i-1]<=j)
            {
                t[i][j] = max(val[i-1]+ t[i-1][j-wt[i-1]], t[i-1][j]);
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    
    printf ("%d\t",t[n][m]);
    return (0);
}

/*AUTHOR ARKAAAP DATE 4/4/25
TRAVELLING SALESPERSON PROBLEM USING ALL POSSIBLE COMBINATIONS (BRUTE FORCE) TIME COMPLEXITY O(2^n)*/




#include <stdio.h>
#include <stdlib.h>

#define INF 99999// DEFINING A CONSTANT AS INF 
int min (int a,int b)
{
    return (a<b?a:b);   // MINIMUM FUNCTION AS THE PROBLEM SEEKS MINIMUS COST 
    
}


int n = 4;


int dist[10][10] = {
    {0,10,15,20},
    {5,0,9,10},  //DECLARING A 4X4 SQUARE MATRIX 
    {6,13,0,12},
    {8,8,9,0}
};


int tsp(int *visited,int curr_pos ,int count ,int cost) // ARRAY , CURRENT POSITION , COUNT , COST 
{
    if (n == count)
    {
        return cost+dist[curr_pos][0];// IF THE COUNT AND THE NO OF NODES ARE SAME IT MEANS ALL THE VERTICES HAVE BEEN VISITED ONCE (BASE CASE)
    }
    int ans = INF;
    for (int city = 0 ;city<n ; city++)//LOOPING 
    {
        if (!visited[city])//CHECKING IF THE I'TH VERTEX IS VISITED I
        {
            visited[city] = 1;  // IF NOT VISIT 
            int newcost = cost+dist[curr_pos][city];// ADD THE NEXT COST 
            int temp = tsp(visited,city,count+1,newcost);// RECURSIVELY VISITING THE CITIES 
            ans = min(ans,temp);// FINDING THE MIN COST 
            visited[city] = 0;// BACKTRACK 
        }
    }
    return (ans);
    
}


int main (int *argc , char **argv)
{
    int visited_Node [10] = {0};
    visited_Node[0] = 1;
    int total_cost = tsp(visited_Node,0,1,0);
    printf ("%d\t",total_cost);
    return (0x00);
}

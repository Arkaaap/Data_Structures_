/*Author Arkaaap date 4/6/2025 Prims */

//MST 

#include <stdio.h>
#include <stdlib.h>
#define INF 99999999 //ACT AS AN INFINITY IF THERE'S NO DIRECT EDGE ONE ONE V TO V 

int nodes = 4;// NO OF Nodes in a graph 
int graph [10][10]=
{
    {0,2,4,3},
    {1,0,INF,2},// GRAPH REPERSNTATION USING ADJ MATRIX 
    {4,INF,0,5},
    {3,2,5,0}
};

int prims (int *visited , int count , int curr_pos,int cost)
{
    if (count == nodes)
    {
        return cost;// IF THE COUNT IS QUIVALENT TO NO OF NODES IT MEANS ALL THE VERTICES HAS BEEN VISITED LET'S SPIT THE COST OUT !!
    }
//AND IF IT'S NOT 
    int min = INF;
    for (int v = 0 ;v<nodes;v++)// ITERATING IN GRAPHS THROUGH VERTICES 
    {
        if (!visited[v] && graph[curr_pos][v]!=INF)// IF THE CURRENT NODE ISNT VISTED YET AND IF THERS'S AN EDGE BW THAT NODE TO SOME OTHER NODES 
        {
            visited[v] = 1;// VISIT THAT SUCKER FIRST AND MARK IT VISITED 
            int newcost = cost+graph[curr_pos][v];// CALCULATING COST 
            int temp = prims(visited,count+1,v,newcost);//RECURSIVE CALL AND ADD 1 TO COUNT TO KEEP THE TRACK OF 
            if (temp<min)
            {
                min = temp;// FINDING THE MOST LEAST COST MST RESULT OUT OF EVERY RESULTS 
            }
            visited[v]= 0 ;// BACKTRACK
        }
    }
    return (min);//RETURN THE MIN COST TO THE MAIN FUNCTION 
}


int main (void)
{
    int visited_nodes [10] = {0};// MAKE ALL THE VERTICES AS UNVISITED 
    visited_nodes[0] = 1;// EXCEPT THE 1ST ARBITARY ONE 
    printf ("%d\t",prims(visited_nodes,1,0,0));
    return (0x0);
}

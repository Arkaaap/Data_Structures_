//HEAP SORT AUTHOR @Arkaaap TIME COMPLEXITY IS O(nlogn) N TIME COMPARISONS AND LOGN TIME OR THE HEIGHT OF THE TREE TIME . SPACE IS O(n).

#include <stdio.h>
#include <stdlib.h>

void HeapiFy (int *a,int n,int i);
void Heap_Sort (int *a,int n);
void Print_Array (int *a,int n);


//ADJUSTING THE ELEMENTS AS A HEAP USING HEAPIFY 
void HeapiFy (int *a,int n,int i)
{
    int lar= i ;//CURRENT NODE 
    int l = 2*i+1;//LEFT NODE OF THE CURRENT NODE 
    int r = 2*i+2;//RIGHT NODE OF THE CURRENT NODE 
    
    if (l<n && a[l]>a[lar])//CHECKING IF THE LEFT NODE IS STILL IN TREE AND LEFT NODE IS LARGER THAN THE CURENT ONE 
    {
        lar= l;//THEN ASSIGN THE LEFT NODE WITH CURRENT ONE AS IT'S LARGER THAN IT'S ROOT 
    }
    if (r<n && a[r]>a[lar])//CHECKING IF THE RIGHT NODE IS STILL IN TREE AND RIGHT NODE IS LARGER THAN THE CURENT ONE 
    {
        lar = r ;//THEN ASSIGN THE RIGHT NODE WITH CURRENT ONE AS IT'S LARGER THAN THE ROOT NODE 
    }
    if (lar != i)//CHECK IF THE CURRENT NODE WHICH WAS INITIALIZED IS NOT LARGER ANYMORE 
    {
        int t = a[i];
        a[i] = a[lar];//THEN SIMPLE SWAP THE CURRENT ONE WITH THE LARGER ONE 
        a[lar] = t;
        HeapiFy(a,n,lar);// AND CALL THE FUNCTION RECURSIVELY OF THE HEIGHT OF TREE WHICH IS O (LOGN) IN COMPLETE BINARY TREE OR FULL BINARY TREE .
    }
}


//HEAP SORT FUNCTION 
void Heap_Sort (int *a,int n)
{
    for (int i = n/2-1;i>=0 ;i--)//LEAF TOWARDS ROOT BOTTOM TO TOP APPROACH 
    {
        HeapiFy(a,n,i);//CALLING ADJUSTING FUNCTION FOR MAKING IT MAX HEAP .
    }
    for (int i = n-1;i>0;i--)
    {
        int t = a[0];
        a[0] = a[i];
        a[i] = t ;
        HeapiFy(a,i,0);
    }
}

//PRINTING ARRAY .....
void Print_Array (int *a,int n)
{
    for (int i =0 ;i<n;i++)
    {
        fprintf (stdout,"%d\t",a[i]);
    }
    printf ("\n");
}

//MAIN FUNCTION 
int main (int argc ,char **argv)
{
    int a[] = {5,8,3,50,-1};
    int n = sizeof(a)/sizeof(a[0]);
    Heap_Sort(a,n);
    printf ("\n");
    Print_Array(a,n);
    return (0x00);
}

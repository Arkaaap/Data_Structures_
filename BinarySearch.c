#include <stdio.h>
#include<stdlib.h>

int Bin_Search (int *a, int x,int n)
{
    int mei, low = 0  , high = (n-1) ;
    mei = (low+high) /2;
    while (low<=high)
    {
        if (a[mei] == x)
        {
            return mei;
        }
        else if (a[mei]>x)
        {
            high =  mei -1 ;
        }
        else{
            low = mei +1 ;
        }
    }
    return -1 ;
    
}


int main (int argc , char **argv)
{
    int *a , n , x;
    printf ("Enter The Size Of The Array :");
    scanf ("%d",&n);
    a = (int *) malloc(n*sizeof(int));
    for (int i = 0 ;i<n;i++)
    {
        printf ("Enter The %dth Number ",i+1);
        scanf ("%d",&a[i]);
    }
    
    for (int i = 0 ;i<n;i++)
    {
        printf ("%d\t",a[i]);
    }
    printf ("Enter The target :");
    scanf ("%d",&x);
    int t = Bin_Search(a,x,n);
    if (t==-1)
    {
        printf ("Not Found !!");
        
    }
    else{
        printf ("Found : %d\t",t);
    }
    free (a);
}

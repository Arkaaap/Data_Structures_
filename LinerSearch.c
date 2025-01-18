#include <stdio.h>
#include <stdlib.h>

int search (int *a , int size , int x)


{
    for (int i = 0 ;i<size;i++)
    {
        if(a[i] == x)
        {
            return i ;
        }
        
        
    }
    return -1;
    
    
}
int main (int argc , char **argv)
{
    
    //int size = sizeof(a)/sizeof(a);
    int x,n;
    int *a= (int*)malloc(n* sizeof(int ));
    printf ("Enter the size of array");
    scanf ("%d",&n);
    for (int i = 0 ;i<n;i++)
    {
        printf ("Enter the %dst Number ",i+1);
        scanf ("%d",&a[i]);
    }
    
    for (int i = 0 ;i<n;i++)
    {
        printf ("%d\t",a[i]);
    }
    printf ("Enter the Target :");
    scanf ("%d",&x);
    
    int tot = search(a,n,x);
    if (tot!=-1)
    {
        printf ("%d\t",tot);
    }
    else{
        printf ("Not Found !");
    }
    free (a);
    
    
    return (0);
}

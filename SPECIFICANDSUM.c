//FIND THE SPECIFIC ELEMENT AND ITS INDEX AND SUM THE WHOLE ARRAY AND PRINT IT 

#include <stdio.h>
int search (int *a,int size,int x)
{
    int i;
    for (i=0;i<size;i++)
    {
        if (a[i]==x)
        {
            return i;
        }
    }
    return -1;
}

int main ()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int size  = sizeof (a)/sizeof (a[0]);

   
    for (int i=0;i<size;i++)
    {
        printf ("%d\t",a[i]);
    }
    printf ("\n");

     int x;

     printf ("Enter the x : ");

     scanf ("%d",&x);

    int tot = search (a,size,x);

    if (tot!=-1)
    {
        printf ("The element's index at [%d] ",tot);
    }
    else printf ("Not found !");

    int sum =0;

    for (int i=0;i<size;i++)
    {
        sum+=a[i];
    }
    printf ("\n The sum of the entire array is %d ",sum);

    return 0 ;
}
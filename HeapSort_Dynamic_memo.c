/* AUTHOR ARKAAAP HeapSort Using Dynamic Memory Allocation and Made a Swap Function Rest Of The code and Logic are sameeeeeee date 2/22/2025*/



#include <stdio.h>
#include <stdlib.h>

void HeapiFy (int *a,int n,int i)
{
    int larr = i ;
    int l = 2*i+1;
    int r = 2*i+2;
    
    if (l<n && a[l]>a[larr])
    {
        larr = l ;
    }
    
    if (r<n && a[r]>a[larr])
    {
        larr = r ;
    }
    
    if (larr!=i)
    {
        int t = a[i];
        a[i] = a[larr];
        a[larr] = t ;
        HeapiFy(a,n,larr);
    }
}



void HeapSort(int *a,int n)
{
    for (int i = (n/2)-1;i>=0;i--)
    {
        HeapiFy(a,n,i);
    }
    
    for (int i = (n-1);i>0;i--)
    {
        int t = a[0];
        a[0] = a[i];
        a[i] = t ;
        HeapiFy(a,i,0);
    }
}



void Print(int *a,int n)
{
    for (int i =0 ;i<n;i++)
    {
        printf ("%d\t",a[i]);
    }
    printf ("\n");
}


void main ()
{
    int *a,s;
    printf ("Enter The array size :");
    scanf ("%d",&s);
    a = (int *)malloc(s*sizeof(int));

  
    for (int i = 0 ;i<s;i++)
    {
        printf ("Enter The %dst Number :",i+1);
        scanf ("%d",&a[i]);
    }
    fprintf (stdout,"The array is getting Printed :\n");
    for (int i = 0 ;i<s;i++)
    {
        printf ("%d\t",a[i]);
    }
    HeapSort(a,s);
    printf ("\n");
    Print(a,s);
    getch ();
    
}










/////////////////////////////////////////////////******************************/////////////////////////////////////////////////////////////////////////////////////////////////////////////////**********************************













#include <stdio.h>
#include <stdlib.h>


    
void Swap(int *a,int *b)
{
    int t = *a;
    *a = *b ;
    *b = t ;
}


void HeapiFy (int *a,int n,int i)
{
    int larr = i ;
    int l = 2*i+1;
    int r = 2*i+2;
    
    if (l<n && a[l]>a[larr])
    {
        larr = l ;
    }
    
    if (r<n && a[r]>a[larr])
    {
        larr = r ;
    }
    
    if (larr!=i)
    {
        Swap(&a[i],&a[larr]);//Fucntion called (swap);By sending refence to the variable 
        HeapiFy(a,n,larr);
    }
}



void HeapSort(int *a,int n)
{
    for (int i = (n/2)-1;i>=0;i--)
    {
        HeapiFy(a,n,i);
    }
    
    for (int i = (n-1);i>0;i--)
    {
        Swap(&a[0],&a[i]);//Function Called (Swap);By sending The Refernce Of the Variable 
        HeapiFy(a,i,0);
    }
}



void Print(int *a,int n)
{
    for (int i =0 ;i<n;i++)
    {
        printf ("%d\t",a[i]);
    }
    printf ("\n");
}


void main ()
{
    int *a,s;
    printf ("Enter The array size :");
    scanf ("%d",&s);
    a = (int *)malloc(s*sizeof(int));
    for (int i = 0 ;i<s;i++)
    {
        printf ("Enter The %dst Number :",i+1);
        scanf ("%d",&a[i]);
    }
    fprintf (stdout,"The array is getting Printed :\n");
    for (int i = 0 ;i<s;i++)
    {
        printf ("%d\t",a[i]);
    }
    HeapSort(a,s);
    printf ("\n");
    Print(a,s);
    getch ();
    
}

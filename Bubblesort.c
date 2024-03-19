#include <stdio.h>
#include <stdbool.h>
void swap (int *a,int *b)
{
    int t = *a;
    *a=*b;
    *b=t;
}
void print (int *a,int size)
{
    int i;
    for (i=0;i<size;i++){
        printf ("%d\t",a[i]);
    }
    
}

void bubble_sort (int *a,int size)
{
    print (a,size);
    int i,j;
    bool swapped;
    
    for (i=0;i<size;i++){
        swapped=false;
        printf ("The subarray's  After the every pass: ");
        printf ("\n");
        for (j=0;j<size-i-1;j++){
            if (a[j]>a[j+1]){
                swap (&a[j],&a[j+1]);
                swapped=true;
                printf ("\n");
                print(a,size);
            }
        }
        if (swapped==false){
            break;
        }
    }
}



int main ()
{
    int a[]={90,64,34,25,12,22,11};
    int size=sizeof (a)/sizeof (a[0]);
    bubble_sort(a,size);
    print(a,size);
    return 0 ;
}
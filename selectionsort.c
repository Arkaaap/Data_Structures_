//{8,7,-1,19,3} SORT THE ARRAY IN NON DECREASING ORDER 
//1.i=0, j=(n-1) THIS IS THE BASIC REPRESENTATION OF AN ARRAY'S I'TH AND J'TH ELEMNT 
//NOW WE MADE J TO MOVE (i+1) AND i=0;
//AND SET A CONDITION BETWEEN THEM IF (A[I]>=A[J]) SWAP ELSE CONTINUE;
//LETS RUN THE CODE 

#include <stdio.h>
int swap (int *a,int *b){
    int t = *a;
    *a = *b;                            //* means pointer which will swap the variables value (call by reference)
    *b = t;
}
void sort (int a[],int size){
    int i=0;
    int j=(i+1);                
    for (i=0;i<size;i++){
        for (j=i+1;j<size;j++){
            if (a[i]>=a[j]){
                swap(&a[i],&a[j]);
            }
             else continue;
        }
       
    }

    }

void print (int a[],int size){
    int i=0;
   for (i=0;i<size;i++){
    printf ("%d\t",a[i]);
   }
    
}

int main ()
{
    int a[5]={8,7,-1,19,3};
    int size  = sizeof (a)/sizeof (a[0]);
    for (int i=0;i<size;i++){
        printf ("%d\t",a[i]);
    }
    printf ("\n");
    sort(a,size);
    print (a,size);
    return 0;
}


 

#include <stdio.h>
int swap (int *a,int *b){
    int t = *a;
    *a = *b;                            //* means pointer which will swap the variables value (call by reference)
    *b = t;
}
void sort (int a[],int size){
    int i;
    int j=i;              
    for (i=1;i<size;i++){
        for (j=i;j>1 && a[j-1]>a[j];j--){
            
                int t =a[j];
                a[j]=a[j-1];
                a[j-1] = t;
            
             
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


#include <stdio.h>
void swap (int *a,int size ){
        for (int i=0;i<size ;i=i+2){
            if (a[i+1]<size){
                int t = a[i];
                a[i]=a[i+1];
                a[i+1]=t;
            }
        }
}
void sort (int *a,int size ){
    for (int i=0;i<size;i++){
        for (int j=i+1;j<size;j++){
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
}
void print (int *a,int size ){
    for (int i=0;i<size;i++){
        printf ("%d ",a[i]);
    }
}

int main ()
{
    int a[6]={6,5,4,3,2,-1};
    int size =sizeof (a)/sizeof (a[0]);
    sort (a,size);
    print (a,size);
    printf ("\n");
    swap (a,size);
    print (a,size);
    return 0 ;
}
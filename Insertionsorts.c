#include<stdio.h>
void print (int *a,int size){
    for (int i=0;i<size;i++){
        printf ("%d\t",a[i]);
    }
}
void insert (int *a,int size){
    int i,j,key;
    for (i=0;i<size;i++){
        key=a[i];
        j=i-1;
        while (j>=0&&a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main ()
{
    int a[10]={10,9,8,7,6,5,4,3,2,1};

     int size  = sizeof (a)/sizeof (a[0]);


    for (int i=0;i<size;i++){

        printf ("%d\t",a[i]);
    }
    printf ("\n");
   
    insert(a,size);

    print (a,size);
    
    return 0 ;
}
#include <stdio.h>
// void scan (int a[],int n){
//     for (int i=0;i<n;i++){
//         scanf ("%d",a[i]);
//     }
// }

void print(int a[],int n){
    for (int i=0;i<n;i++){
        printf ("%d ",a[i]);
    }
}

void reverse (int a[],int n){
   for (int i=0;i<n;i++){
    for (int j=i+1;j<n;j++){
        if (a[i]<a[j]){
            int t = a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
   }
}
int main ()
{
    int n;
    printf ("Enter the n : ");
    scanf ("%d",&n);
    int a [n];
    int i,j;
    for (i=0;i<n;i++){
        scanf ("%d",&a[i]);
    }
    reverse(a,n);
    print(a,n);
   
    return 0 ;
}
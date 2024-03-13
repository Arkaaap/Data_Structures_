//FIND A SPECIFIC ELEMENT OF AN UNSORTED ARRAY 
//SO AT THE THE BEGIN WE GOTTA SORT THE GIVEN (N) SIZE ARRAY 
//AND THEN SEARCH USING RECURSION 
//CALL THE FUNCTIONS IN THE MAIN FUN
#include <stdio.h>
// void sort (int* a, int size){
//     int i,j;
//     for (i=0;i<size;i++){
//         for (j=i+1;j<size;j++){
//             int t = a[i];
//             a[i] = a[j];
//             a[j] =t;
//         }
//     }
// }

int bin_search (int a[],int i,int j,int x){
    int mei = (i+j)/2;
    int me;
    if (a[mei]==x){
        
        printf("Early found ");
        return mei;
    }
    if (i==j){
        return -1;
    }
    else if (a[mei]>x){
        j=mei;
        bin_search(a,i,j,x);
    }
    else {
        i=mei+1;
        bin_search(a,i,j,x);
    }
}
int main ()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int x;
    printf ("Enter the x : ");
    scanf ("%d",&x);
    int i,j=sizeof (a)/sizeof (a[0]);
    int size = sizeof (a)/sizeof (a[0]);
    // sort (a,size);
    int t =-1;
     t = bin_search(a,i,j,x);
    if (t==-1){
        printf ("Not found !");
    }
    else printf ("[%d]\t",t);
    return 0 ;

}














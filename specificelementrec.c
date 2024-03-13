//FINDING SPECIFIC ELEMENT BY RECURSION IN BINARY SEARCH 
#include <stdio.h>
int bin_search (int* a,int i,int j,int x){
    
    int mei = (i+j)/2;  //MIDDLE ELEMENTT INDEX
    int me;
    if ( a[mei] == x ) {
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


int main (){
    int a[10]={1,2,3,4,5,6,7,8,9,10},x;

    int i,j;

    int size = sizeof (a)/sizeof (a[0]);

    for (i=0;i<size;i++){
        printf ("%d\t",a[i]);
    }

    printf ("\n");

    printf ("Enter the number : ");

    scanf ("%d",&x);

     i=0,j=(sizeof(a)/sizeof(a[0]))-1;

    int y =-1;

     y  = bin_search(a,i,j,x);

    if (y==-1){
        printf ("Not found !");
    }

    else printf ("At index no [%d]\t",y);

    return 0 ;
}

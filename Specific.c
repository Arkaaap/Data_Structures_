// #include <stdio.h>
// int  specific (int a[],int size,int key){
//     for (int i=0;i<=size-1;i++){
//         if (a[i]==key){
//             return i;
//         }
//     }
//     return -1;
// }
// int main ()
// {
//     int a[5]={1,2,3,4,5};
//     int res=specific(a,5,4);
//     if (res!=-1){
//         printf ("Key found index at %d ",res);
//     }
//     else printf ("Not");
//     return 0;
// }






//A BETTER APPROACH (2);



#include <stdio.h>

int Specific (int* a ,int size,int key){
    for (int i=0;i<size;i++){
        if (a[i]==key){
            return i;
        }
    }
    return -1 ;
}


int main(){
    int a[10]={1,2,3,44,5,6,7,8,9,100},n;

     int size = sizeof (a)/sizeof(a[0]);

    printf ("The original array : ");

    for (int i=0;i<=size-1;i++){
        printf ("%d ",a[i]);
    }

    printf ("\n");

    printf ("Input an element : ");
    scanf ("%d",&n);
   
    int total = Specific(a,size,n);
    
    if (total==-1){
        printf ("Not found");
    }
    
    else printf ("Element found at position [%d] ",Specific);
    return 0 ;
}
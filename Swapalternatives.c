// #include <stdio.h>
// void print (int a[],int size ){
//     for (int i = 0 ;i < size; i ++ ){
//     printf ("%d ",a[i]);
//   }                                     

// }
// void swap (int a[],int size ){
//       for (int i =0 ;i <size; i +=2 ){
//         for (int j=i+1;j<size;j++){
//             if (a[i+1] <size){                      //LINEAR SEARCH WHERE WE SWAP ARRAY ELEMENTS TO ITS NEXT ELEMENT 
//                 int t = a[i];
//                 a[i] = a[i+1];
//                 a[i+1] = t;
//             }
//         }
//     }
// }
// int main ()
// {
//     int a[8]={1,2,3,4,5,6,7,8};
//     int i,j;
//     swap(a,8);
//     print(a,8);

  
//     return 0 ;
// }



















//BEST ALTERNATIVE WAY TO swap CO-RESPONDING ELEMENETS WHERE YOU DONT HAVE TO SWAP ALL THE ELEMNETS IF THEY ARE ALREADY = CO THEIR CO RESPONDINGS 







#include <stdio.h>
void sort (int *a,int size)
{
    int i;
    for (i=0;i<size;i+=2)
    {




        for (int j=i+1;j<size;j++)
        {
            if (a[i]==a[i+1]){                                  //THIS IS WEHERE I CHANGED THE CONDITION 
                continue;                                
            }
            else {int t = a[i];
                a[i] = a[i+1];
                a[i+1] = t; 
        }
    }
    }
   



}


void print (int *a,int size)
{
    int  i;
    for (i=0;i<size;i++)
    {
        printf ("%d\t",a[i]);
    }
}
int main ()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int size  = sizeof (a)/sizeof (a[0]);
    int i;
    for (i=0;i<size;i++)
    {
        printf ("%d\t",a[i]);
    }
    printf ("\n");
    sort (a,size);
    print (a,size);
}
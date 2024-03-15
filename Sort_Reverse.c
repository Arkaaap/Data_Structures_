//WE FIRST PICKED AN UNSORTED ARRAY AND THEN MMAKE IT SORT AND THEN WE SIMPLE  PUT THE ARRAY IN REVERSE ORDER INORDER TO REVERSE AN UNSORTED ARRAY WE FIRST NEED TO SORT THE WHILE ARRAY AND THEN REVERSE IT ITHER THIS WILL NOT GONNA HAPPEN
#include <stdio.h>
void sort (int *a,int size)
{
    int i,j;
    for (i=0;i<size;i++){
        for (j=i+1;j<size;j++)
        {
            if (a[i]>=a[j]){
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}
void print (int *a,int size)
{
    int i;
    for (i=0;i<size;i++){
        printf ("%d\t",a[i]);
    }
}
int main ()
{
    int a[10]={1,1,34,54,12,8,9,9,0,-1};
    int size = sizeof (a)/sizeof(a[0]);
    int i,j,c=0,x=1;  
    sort(a,size);
    print (a,size);//
    for (i=0;i<size;i++)
    {
        for (j=i+1;j<size;j++){
            if (a[i]<a[j]){
               int t = a[i];
               a[i]=a[j];
               a[j]=t;
            }
        }
    }
    
    printf ("\n");
    for (i=0;i<size;i++)
    {
        printf ("%d\t",a[i]);
    }
   
    return 0 ;
}
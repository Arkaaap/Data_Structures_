#include <stdio.h>

int main ()
{
    int a[5]={1,3,3,1,5};
     int c=0;
     int n;
      for (int i=0;i<5;i++){
        for (int j=i+1;j<5;j++){
            if (a[i]==a[j]){
                c++;
            }
        }
    }
    
   
   printf ("The duplicate elements in the floowing array is %d ",c);
    return 0 ;
}
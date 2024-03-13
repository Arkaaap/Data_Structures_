// FIND THE PAIR ELEMENTS IN AN ARRAY RESPECTIVE TO GIVEN NUMBER X 

//1 2 3 4 5 

//X=9;

//PAIR 1

#include <stdio.h>
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int size = sizeof (a)/sizeof (a[0]);
    int x;
    int c=0;

    for (int i=0;i<size;i++){
        printf ("%d\t",a[i]);

    }
    printf ("\n");

    printf ("Enter the element ypu ant a pair of : ");
    scanf("%d",&x);

     for (int i=0;i<size;i++){
        for (int j=i+1;j<size;j++)
        {
            if (a[i]+a[j]==x){
                c++;
            }
        }
    }

    printf ("THE DUPLIACTE ARE %d ",c);
    
    return 0 ;
}
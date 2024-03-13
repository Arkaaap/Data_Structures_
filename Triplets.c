//THIS ISS WHERE WE'D TRY TO FETCH TRIPLETS (ADD 3 ELEMENS AND SUM THEM ,IF AN ELEMENT FROM THIS FOLLOWING ARRAY MEETS THE THE VALE AFTER SUMMATION WE WILL FETCH IT)
 #include<stdio.h>
int main ()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int size = sizeof (a)/sizeof (a[0]);
    int i,j,k,x;
    for (i=0;i<size;i++)
    {
        printf ("%d\t",a[i]);
    }
    printf ("\n");
    printf ("Enter the x for getting triplets : ");
    scanf ("%d",&x);
    int c=0;
    for (i=0;i<size;i++)
    {
        for (j=i+1;j<size;j++)
        {
            for (k=j+1;k<size;k++)
            {
                if (a[i]+a[j]+a[k]==x){
                    c++;
                }
            }
        }
    }
    printf ("The triplets are %d ",c);
    return 0 ;
}
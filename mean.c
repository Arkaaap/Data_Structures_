#include <stdio.h>
int main (){
    int n,a[]={5,4,3,2,1},sum=0,maxc,maxv,i,j,c;
    float mi,m;
    printf ("Enter the size of array \n");
    scanf ("%d",&n);
    for (i=0;i<n;i++){
        sum+=a[i];
    }
    m=sum/n;
    printf ("The mean is %f ",m);

    for (i=0;i<n;i++){
        for (j=i+1;j<n;j++){
            if (a[i]>a[j]){
                int t = a[i];
                a[i] = a[j];;
                a[j] = t;
            }
        }
    }

    printf ("The sorted array is ");
    for (i=0;i<n;i++){
        printf ("%d ",a[i]);
        
    }

    if (n%2==0){
    mi = a[n/2] +a [(n/2)-1];
    mi/=2;
    }
    else 
    mi = a[n/2];
    printf ("Themedian is %0.2f ",mi);
    for (i=0;i<n;i++){
        c = 0;
        for (j=0;j<n;j++){
            if (a[j]==a[i]){
               c++;
            }
            if (c>maxc){
                maxc  =c;
                maxv = a[i];
            }
        }
    }
    printf ("The mode is %d",maxv);
    return 0 ;
    
}
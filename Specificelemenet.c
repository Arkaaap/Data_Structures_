//FIND A SPECIFIC ELEMENT FROM THE GIVEN ARRAY USING BINARY SEARCH 

#include<stdio.h>
int sort (int* a,int size,int key){
    int i=0;
    int j=size-1;
    while (i<=j){
        int MEI = i+j/2;
        if (a[MEI]==key){
            return MEI;
        }
        else if (a[MEI]<key){
            i=MEI+1;
        }
        else j=MEI-1;

    }
    return -1;

}
int main ()
{
    int i,n,a[9]={1,2,3,4,5,6,7,8,9};
    int size = sizeof (a)/sizeof(a[0]);
    for (i=0;i<size;i++){
        printf ("%d\t",a[i]);
    }
    printf ("\n");
    printf ("Enter the desired element : ");
    scanf ("%d",&n);
    int result = sort(a,size,n);
    if (result == -1){
        printf ("Not found ");
    }
    else 
    printf ("%d ",sort(a,size,n));

    return 0 ;
}














// #include <stdio.h>

// int search(int *a, int size, int key) {
//     int i = 0;
//     int j = size - 1;
//     int ele;

//     while (i <= j) {
//         ele = (i + j) / 2;

//         if (a[ele] == key) {
//             return ele; // Element found at index 'ele'
//         } else if (a[ele] < key) {
//             i = ele + 1;
//         } else {
//             j = ele - 1;
//         }
//     }

//     return -1; // Element not found
// }

// int main() {
//     int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     int n, i;

//     int size = sizeof(a) / sizeof(a[0]);
//     for (i = 0; i < size; i++) {
//         printf("%d\t", a[i]);
//     }
//     printf("\n");

//     printf("Enter the element you want to search: ");
//     scanf("%d", &n);

//     int result = search(a, size, n);

//     if (result != -1) {
//         printf("Element %d found at index %d\n", n, result);
//     } else {
//         printf("Element %d not found in the array\n", n);
//     }

//     return 0;
// }
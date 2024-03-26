#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int d;
    struct node* next;
};


struct node* createlist (int d)
{
    struct node* ptr = (struct node* )malloc(sizeof (struct node));
    printf ("Enter the elements : ");
    scanf ("%d",&d);
    ptr->d = d;
    ptr->next = NULL;
    return ptr;
}




void printlist (struct node* head)
{
    if (head==NULL){
        return ;
    }

    printf ("%d\t",head->d);
    printlist(head->next);
}

int main ()
{
    int d;
    struct node* ptr = createlist(d);
    ptr->next = createlist(d);
    ptr->next->next = createlist(d);
    ptr->next->next->next = createlist(d);
    printlist(ptr);
    free  (ptr);
    return 0 ;
}



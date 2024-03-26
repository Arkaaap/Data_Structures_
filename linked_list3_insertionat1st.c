#include <stdio.h>
#include <stdlib.h>

struct node {
    int d;
    struct node* next ;
};

struct node* create_list (int d)
{
    struct node* p = (struct node*)malloc(sizeof (struct node));
    p->d =d;
    p->next = NULL;
    return p;
}

struct node* insert_at_the_begin(struct node* head,int d)
{
    struct node* ptr = (struct node* )malloc(sizeof (struct node));
    ptr->next = head;
    ptr->d = d;
    return ptr;
}

void print (struct node* head)
{
    if (head==NULL){
        return ;
    }
    printf ("%d\t",head->d);
    print(head->next);
}

int main ()
{
    struct node* head = create_list(1);
    head->next = create_list(2);
    head->next->next = create_list(3);
    head->next->next->next = create_list(4);
    head = insert_at_the_begin(head,56);
    head = insert_at_the_begin(head,55);
    print (head);
    free (head);
    return 0 ;

}
#include <stdio.h>
#include<stdlib.h>

struct node{
    int d;
    struct node* next;
};

struct node* createlist (int d)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node*));
    newnode->d = d;
    newnode->next = NULL;
    return newnode;
}

struct node* end (struct node* head,int d)
{
    struct node* newnode,*temp;
    newnode = (struct node*)malloc(sizeof(struct node*));
    temp = (struct node*)malloc(sizeof(struct node*));
    newnode ->d = d;
    newnode->next = NULL;
    temp = head;
    while (temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

void print (struct node* head)
{
    struct node* p = head;
    while (p!=NULL){
        printf ("%d\t",p->d);
        p=p->next;
    }
}

int main ()
{
    struct node* p = createlist(1);
    p->next = createlist(2);
    p->next->next = createlist(3);
    p->next->next->next = createlist(4);
    end(p,5);
    print(p);
    free (p);
    return 0 ;
}
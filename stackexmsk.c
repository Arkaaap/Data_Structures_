//queue 
#include <stdio.h>
#include <stdlib.h>

struct node {
    int d;
    struct node *next ;
};

struct node *top,*p;

void push (int d)
{
    struct node *newnwode = (struct node *)malloc(sizeof(struct node*));
    newnwode->d = d;
    newnwode->next = top;
    if (top == NULL)
    {
        top = newnwode;
    }
    else {
        p =top;
        while (p->next!=NULL)
        {
            p =p->next;
        }
        newnwode->next = p->next;
        p->next = newnwode;
    }
}


void pop ()
{
    p = top;
    while (p->next->next!=NULL)
    {
        p = p->next;
    }
    p->next = NULL;
}

void display ()
{
    p =top;
    while (p!=NULL)
    {
        printf ("%d\t",p->d);
        p = p->next;
    }
}

int main ()
{
    push(1);
    push(90);
    push(34);
    pop();
    pop();
    display();
}
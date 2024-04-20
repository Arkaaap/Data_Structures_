#include <stdio.h>
#include <stdlib.h>

struct node {
    int d;
    struct node *next ;
    struct node*prev;
};

struct node *head,*p;

void insert_beg (int d)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node*));
    newnode->d = d;
    if (head == NULL)
    {
        head = newnode;
        newnode->prev = NULL;
        newnode->next = head;
    }
    else {
        p = head;
        while (p->next!=head)
        {
            p = p->next;
        }
        newnode->next = head;
        p->next = newnode;
        newnode->prev = NULL;
        head = newnode;
    }
}

void insert_end (int d)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node*));
    newnode->d = d;
    if (head == NULL)
    {
        head = newnode;
        newnode->prev = NULL;
        newnode->next = head;
    }
    else {
        p = head;
        while (p->next!=head)
        {
            p = p->next;
        }
        newnode->next = head;
        p->next = newnode;
        newnode->prev = NULL;
        // head = newnode;
    }
}


void insert_point (int pos,int d)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node*));
    newnode->d = d;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
        newnode->prev = NULL;
    }
    else {
        p = head;
        int c = 0;
        while (p->next!=head)
        {
            c++;
            if (c ==pos-1)
            break;
            p = p->next;
        }
        newnode->next = p->next;
        p->next = newnode;
        newnode->prev = p;
    }
}



void del_beg ()
{
    p = head;
    head = head->next;
    p->next = head;
    p->prev = NULL;
    
}


void del_end ()
{
    p = head;
    struct node *s;
    while (p->next!=head)
    {
        s = p;
        p = p->next;
    }
    s->next = p->next;
    s->prev = NULL;
}


void del_pos (int pos)
{
    p = head;
    int c = 0;
    while (p->next!=head)
    {
        c++;
        if(c == pos-1)
        break;
        p = p->next;
    }
    p->next = p->next->next;
    p->prev = p;
}


void display ()
{
    p = head;
    while (p->next!=head)
    {
        printf ("%d\t",p->d);
        p = p->next;
    }
    printf ("%d\t",p->d);
}



int main ()
{
    insert_beg(1);
    insert_beg(7);
    insert_beg(8);
    insert_beg(80);
    insert_end(9000);
    insert_end(90000);
    insert_point(3,5);
    insert_point(4,3);
    // del_beg();
    // del_beg();
    // del_beg();
    // del_end();
    del_end();
    del_end();
    del_pos(3);
    del_pos(3);
    display();
}
#include <stdio.h>
#include <stdlib.h>

struct node {
    int d;
    struct node *next ;
};
struct node *head,*p;
void insert_beg(int d)
{
struct node *newnode = (struct node*)malloc(sizeof(struct node*));
newnode ->d  = d;
if (head == NULL)
{
    head = newnode;
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
    }
}

void insert_pos (int pos,int d)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node*));
    newnode->d = d;
    if (head == NULL)
    {
        head = newnode;
    }
    else {
        p = head;
        int c  = 0;
        while (p->next!=head)
        {
            c++;
            if (c == pos-1)
            break;
            p = p->next;
        }
        newnode->next = p->next;
        p->next = newnode;
    }
}

void del_beg ()
{
   p = head;
   while (p->next!=head)
   {
       p = p->next;
   }
   p->next = head->next;
  head=  head->next;
   
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
}

void del_pos(int pos)
{
    p = head;
    int c  = 0;
    while (p->next!=head)
    {
        c++;
        if (c == pos-1)
        break;
        p=p->next;
    }
    p->next = p->next->next;
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


void destroy ()
{
    free (head);
    free (p);
}


int main ()
{
    insert_beg(1);
    insert_beg(34);
    insert_end(78651);
    insert_pos(2,1);
    del_pos(2);
    del_end ();
    del_beg();
    // destroy();
    display();
}
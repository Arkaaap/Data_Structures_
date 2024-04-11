#include <stdio.h>
#include <stdlib.h>

struct node
{
 int d;
 struct node *next;
};

struct node *head,*temp;

void insert_beg (int d)
{
    struct node *newnode ;
    newnode  = (struct node*)malloc(sizeof(struct node*));
    newnode->d = d;
    newnode->next = head;
    head = newnode;

}

void insert_pos (int pos,int d)
{
    struct node *newnode  =(struct node *)malloc(sizeof(struct node *));
    newnode ->d = d;
    newnode->next = NULL;
    if (head == NULL){
        head = newnode;
    }
    else {
        temp = head;
        int c= 0;
        while (temp->next!=NULL)
        {
            c++;
            if (c == pos-1)
            {
                break;
            }
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->d = d;

        
    }
}
void insert_end (int d)
{
    struct node *newnode ;
    newnode = (struct node*)malloc(sizeof(struct node*));
    newnode->d = d;
    newnode->next = NULL;
    if (head==NULL){
        head = newnode;
    }

    else {
        
        temp=head;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newnode;
    }
}


void print ()
{
    temp=head;
    while (temp!=NULL){
        printf ("%d\t",temp->d);
        temp = temp->next;
    }
}

void lin_search (int element)
{
    temp = head;
    while (temp->next!=NULL){
        if (temp->d == element){
            printf ("Found ");
            break;
        }
        temp=temp->next;
    }
   
}

void delete ()
{
    if (head==NULL){
        return ;
    }
    head = head->next;
    free (temp);
}



void delete_end ()
{
   if (head == NULL)
   {
    return ;
   }

   else {
    temp = head;

    while (temp->next->next!=NULL)
    {

        temp = temp->next;

    }

    temp->next = NULL;

   }

}




void delete_at_any_point (int  pos)
{
    
   if (head == NULL)
   {
    return ;
   }

   else {

    temp = head;

    int c = 0;

    while (temp->next!=NULL)
    {
        c++;

        if (c == pos-1)
        {
            break;
        }

        temp = temp->next;
    }

    temp->next = temp->next->next;

   }

}



int main ()
{
    int choice ,  data,pos;
    do {
    printf ("\n");
    printf ("1: Insert at the begining : \n");
    printf ("2: Insert end :\n");
    printf ("3: Insert at the position : \n");
    printf ("4: search a particular element : \n");
    printf ("5: print \n");
    printf ("6: Delete an element :\n");
    printf ("7: Delete an element end  :\n");
     printf ("8: Delete an element given position  :\n");
    printf ("9: Exit :\n");
    printf ("Enter the choice : ");
    scanf ("%d",&choice);
    switch (choice){
        case 1: printf ("Enter the data you want to insert : ");
        scanf ("%d",&data);
        insert_beg(data);
        break;

        case 2:  printf ("Enter the data you want to insert at the end  :");
        scanf ("%d",&data);
        insert_end(data);

        case 3: printf ("Enter the position you want to insert the data  :");
        scanf ("%d",&data);
        insert_pos(pos,4);
        break;


        case 4: printf ("Enter the particular element you want to search for :");
        scanf ("%d",&data);
        lin_search(data);
        break;

        case 5: print ();
        break;
        case 6: delete();
        break;

        case 7: delete_end();
                break;
        case 8: printf ("Enter the position you want to delete :");
        scanf ("%d",&data);
        delete_at_any_point(data);
        break;
        case 9: exit (1);
        break;

        default : printf ("OOOPPPssss!");
                break;
                exit;
    }
    }while(choice !=100);

   
    return 0 ;
}

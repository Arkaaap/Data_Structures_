#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
struct node {
    int d;
    struct node *left ;
    struct node *right ;
};
struct node *root =NULL;

struct node *createnode (int d)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node *));
    newnode->d = d;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}


struct queue {
    struct node *arr;
    int front , rear , size;
};
struct queue *createqueue ()
{
    struct queue *newqueue  = (struct queue *)malloc(sizeof(struct queue *));
    newqueue->arr = (struct node *)malloc(100*sizeof(struct node *));
    newqueue->front =-1;
    newqueue->rear = 0;
    newqueue->size = 0;
    return newqueue ;
}

void enqueue (struct node *temp,struct queue *queue)
{
    queue->arr [queue->rear ++];
    queue->size++;
}


void dequeue (struct queue *queue)
{
    queue->size--;
    queue->arr[++queue->front];
}


void insert_node (int d)
{
    struct node *newnode = createnode(d);
    if (root == NULL)
    {
        root = newnode;
        return ;
    }
    else {
        struct queue *queue = createqueue();
        enqueue(root,queue);
        while (true)
        {
            dequeue(queue);
            if (root->left!=NULL && root->right!=NULL)
            {
                enqueue(root->left,queue);
                enqueue(root->right,queue);
                
            }
            else {
                if (root->left == NULL)
                {
                    root->left = newnode;
                    enqueue(root->left,queue);
                }
                else {
                    root->right = newnode;
                    enqueue(root->right,queue);
                }
                break;
            }
        }
    }
}



void inorder (struct node *root)
{
    if (root == NULL)
    {
        // printf ("----empty-----\n");
        return ;
    }
    inorder(root->left);
    printf ("%d\t",root->d);
    inorder(root->right);
}



void preorder (struct node *root)
{
    if (root == NULL)
    {
        // printf ("----empty-----\n");
        return ;
    }
    printf ("%d\t",root->d);
    preorder(root->left);
    preorder(root->right);
}


struct node *bst (struct node *root,int x)
{
    if (root == NULL)
    {
        return NULL;
    }
     if (root->d == x)
    {
        printf ("Found : %d",x);
    }
    else if (root->d>x)
    {
        bst(root->left,x);
    }
    else {
        bst(root->right,x);
    }
}



int height (struct node *root)
{
    if (root== NULL)
    {
        return 0 ;
    }
    
    else {
        int lheight = height(root->left);
        int rheight = height(root->right);
        if (lheight>rheight)
        {
            return lheight+1;
        }
        else {
            return rheight+1;
        }
    }
}


int main (void)
{
    struct node *s = createnode(40);
    s->left = createnode(30);
    s->right = createnode(50);
    s->left->left = createnode(15);
    s->left->right = createnode(35);
    s->right->left = createnode(45);
    s->right->right = createnode(60);
    preorder(s);
    inorder (s);
    int x;
    printf ("Enter the x:");
    scanf ("%d",&x);
    s = bst(s,x);
    printf ("%d\t",height(s));
}

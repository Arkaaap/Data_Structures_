#include <stdio.h>
#include <stdlib.h>
#define max 5

int arr_stack [max];
int front  = -1;
int rear  = -1;
void push (int d)
{
    if (rear == max-1)
    {
        printf ("Stack overflow !");
        return;
    }
    else {
        front++;
        arr_stack[front] = d;
        
    }
}


void pop ()
{
    if (front == -1)
    {
        printf ("Stack undefflow !");
        return ;
    }
    else {
        int val = arr_stack[rear];
        front --;
    }
}


// int peek ()
// {
//     if (top == -1)
//     {
//         printf ("Stack udeffloww!");
//         return -1;
//     }
//     else {
//         return arr_stack[top];
//     }
// }



void display ()
{
    if (front == -1)
    {
        return;
    }
    for (int i=0;i<=front;i++)
    {
            printf ("%d\t",arr_stack[i]);
    }
}


int main ()
{
    push (1);
    push (10);
    // push (10);
    pop ();
    // pop();
    display();
    return 0 ;
}
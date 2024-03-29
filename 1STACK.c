// WAP IN C TOO PERFORM  PUSH POP OPERATIONS IN STACK 


#include<stdio.h>
#include <stdlib.h>
#define MAX 5  //PREPROCESSOR DIRECTIVES 

int stack_arr[MAX];
int top=-1;          // GLOBAL VARIABLES 

void push (int d)
{
    if (top==MAX-1){
        printf ("The stack is overflowed for this element :%d",d);
        return ;
    }

    top++;
    stack_arr[top]=d;
}

int pop ()
{
    int d;
    if (top==-1)
    {
        printf ("STACK UNDERFLOW!");
         exit (1);
    }
   stack_arr[top]=d;
    top--;
    return d;
}

void print ()
{
    if (top==-1)
    {
        printf ("The stack is underflow !");
        return ;
    }

    for (int i=0;i<top;i++){
        printf ("%d\t",stack_arr[i]);
    }
}

int main ()
{
    int d;
    push(1);
    push(2);
    push(3);
    push(4);
    push (5);
    // push (6);
    printf ("\n");
    print ();
}
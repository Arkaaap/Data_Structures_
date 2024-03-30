#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int top=-1;


int stack_ar[MAX];


int isEmpty ()
{
    if (top==-1){
        return 1;
    }
    return 0;
}


int isFull ()
{
    if (top==MAX-1){
        return 1;
    }
    return 0;
}

void push (int data)
{
    if (isFull()){
        printf ("Stack Overflow!");
        return ;
    }
    top++;
    stack_ar[top]=data;
}


int pop ()
{
    int data;
    if (isEmpty()){
        printf ("Stack Underflow !");
        exit (1);
    }
    
    data  = stack_ar[top];
    top--;
    return data;
}

int peek ()
{
    if (isEmpty()){

        printf ("Stack Underflow!");
        exit(1);

    }

    return stack_ar[top];
    
}

void print ()
{
    if (isEmpty()){
        printf ("Stack Underflow!");
    }
    
    for (int i=0;i<=top;i++){
        printf ("%d\t",stack_ar[i]);
        printf ("\n");
    }
    
}



int main ()
{
    int choice, data;
    printf ("\n");
    
    printf ("1: PUSH\n");
    printf ("2: POP\n");
    printf ("3: PRINT THE TOP ELEMENT\n");
    printf ("4: PRINT ALL THE ELEMENTS OF THE STACK \n");
    printf ("5: QUIT\n");
    printf ("Please enter your choice : ");
    scanf ("%d",&choice);
    switch(choice)
    {
        case 1: printf ("Enter the element you want to push : ");
        scanf ("%d",&data);
        push(data);
        break;
        
        case 2: data = pop();
                printf ("Element has been deleted successfully : %d",data);
                break;
                
        case 3: printf ("The top most element is : %d ",peek());
                break;
        
        case 4: print ();
                break;
                
        case 5: exit (1);   
        
        default : printf ("Please Enter the valid choice : ");
                exit (1);
    }
    
    main ();
    
    return 0 ;

   
    
}



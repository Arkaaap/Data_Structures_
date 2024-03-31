#include <stdio.h>
#include <stdlib.h>



struct node {
    int data;
    struct node* next;
};



struct node* top = NULL;



int isEmpty(struct node* top) {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return 1;
    }
    return 0;
}




int isFull(struct node* top) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Stack Overflow!\n");
        return 1;
    }
    free(ptr);
    return 0;
}



struct node* push(struct node* top, int data) {
    if (isFull(top)) {
        printf("Stack Overflow!\n");
    } else {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = top;
        top = newNode;
        return top;
    }
}




int pop(struct node** top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        struct node* temp = *top;
        *top = (*top)->next;
        int x = temp->data;
        free(temp);
        return x;
    }
}



void print(struct node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        while (top != NULL) {
            printf("%d ", top->data);
            top = top->next;
        }
        printf("\n");
    }
}



int peek(struct node* top) {
    if (isEmpty(top)) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        return top->data;
    }
}



int main() {
    int choice, data;
        printf("\n1: Push\n");
        printf("2: Pop\n");
        printf("3: Peek\n");
        printf("4: Print\n");
        printf("5: Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &data);
                top = push(top, data);
                break;
            case 2:
                printf("Popped element: %d\n", pop(&top));
                break;
            case 3:
                printf("Top element: %d\n", peek(top));
                break;
            case 4:
                print(top);
                break;
            case 5:
                exit(1);
            default:
                printf("Invalid choice!\n");
        }


    main ();


    return 0;

}

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *top) {
    if (top == NULL) {
        return 1;  
    } else {
        return 0;  
    }
}

int isFull(struct Node *top) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        return 1;  
    } else {
        free(ptr);
        return 0;  
    }
}

struct Node* push(struct Node *top, int val) {
    if (isFull(top)) {
        printf("Stack Overflow\n");
        return top;  
    }
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->next = top;
    top = ptr;
    return top;
}

struct Node* pop(struct Node *top) {
    if (isEmpty(top)) {
        printf("Stack Underflow\n");
        return top;  
    }
    struct Node *temp = top;
    printf("%d popped from stack\n", top->data);
    top = top->next;
    free(temp);
    return top;
}

struct Node* peek(struct Node *top) {
    if (isEmpty(top)) {
        printf("Stack is Empty\n");
        return NULL;  
    }
    return top;
}

void traverse(struct Node *top) {
    if (isEmpty(top)) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack: ");
    for (struct Node *ptr = top; ptr != NULL; ptr = ptr->next) {
        printf("%d ", ptr->data);
    }
    printf("\n");
}

int main(){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *top = NULL;
    int choice, val;
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("4. Traverse\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                top = push(top, val);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                exit(0);
            case 4:
                traverse(top);
            default:
                printf("Invalid choice\n");
        }
    }
}


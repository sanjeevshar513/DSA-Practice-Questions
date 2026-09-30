#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

int isEmpty(struct Node *top){
    return top == NULL ? 1: 0;
}

int isFull(struct Node *top){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if(ptr==NULL)
       return 1;
    free(ptr); //to avoid memory leak
    return 0;
}

void linkedListTraversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("Element is %d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct Node *push(int val){
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    if(isFull(top)){
        printf("Stack Overflow\n");
        return top;
    }
    else{
        p->data = val;
        p->next = top;
        top = p;
        return top;
    }
}

int pop(){
    struct Node *temp = top;
    if(isEmpty(top)){
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        top = top->next;
        int x  = temp->data;
        free(temp);
        return x;
        
    }
}

int peek(int pos){
    struct Node *ptr = top;
    for(int i=0;(i<pos-1 && ptr!=NULL);i++){
        ptr = ptr ->next;
    }
    if(ptr!=NULL)
        return ptr->data;
    else
       return -1;
}

int main(){
    push(10);
    push(20);
    push(30);
    int element = pop();
    printf("Popped element is %d\n",element);
    linkedListTraversal(top);
}


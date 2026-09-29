# include <stdio.h>
# include <stdlib.h>
#define MAX 100
struct Stack {
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *ptr){
    if(ptr->top ==-1)
        return 1;
    else
        return 0;      
}

int isFull(struct Stack *ptr){
    if(ptr->top == MAX - 1)
        return 1;
    else
        return 0;      
}


void push(struct Stack *s,int val){
    if(isFull(s)){
        printf("Stack Overflow");
    }
    else{
        s->top++;
        s->arr[s->top] = val;
    }
}


void pop(struct Stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow");
    }
    else{
        s->top--;
    }
}

int peek(struct Stack *s,int i){
    int arrayInd = s->top - i + 1;
    if(arrayInd< 0){
        printf("Invalid input");
        return -1;
    }
    else
        return s->arr[s->top-i+1]; 
}
int main(){
    int val = 8,i = 20;
    struct Stack *s = (struct Stack*) malloc(sizeof(struct Stack));
    s->size = MAX;
    s->top = -1;
    s->arr = (int*) malloc(s->size * sizeof(int));
    push(s,val);
    push(s,10);
    push(s,20);
    push(s,30);
    peek(s,i);
    
}
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Stack{
    int arr[MAX];
    int top;  
};


void push(struct Stack *s,int val){
    if(s->top == MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = val;
}

void pop(struct Stack *s){
    if(s->top == -1){
        printf("Stack Underflow\n");
        return;
    }
    printf("%d popped from stack\n",s->arr[s->top]);
    s->top--;
}

void isEmpty(struct Stack *s){
    if(s->top == -1){
        printf("Stack is Empty\n");
    }
    else{
        printf("Stack is not Empty\n");
    }
}

struct queue {
    struct Stack s1;
    struct Stack s2;
};

void enqueue(struct queue *q,int val){
    push(&q->s1,val);
}

void dequeue(struct queue *q){
    if(q->s1.top == -1 && q->s2.top == -1){
        printf("Queue is Empty\n");
        return;
    }
    if(q->s2.top == -1){
        while(q->s1.top != -1){
            int val = q->s1.arr[q->s1.top];
            pop(&q->s1);
            push(&q->s2,val);
        }
    }
    pop(&q->s2);
}

void traverse(struct queue *q){
    if(q->s1.top == -1 && q->s2.top == -1){
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue: ");
    for(int i = q->s2.top; i >= 0; i--){
        printf("%d ",q->s2.arr[i]);
    }
    for(int i = 0; i <= q->s1.top; i++){
        printf("%d ",q->s1.arr[i]);
    }
    printf("\n");
}


int main(){
    struct queue q;
    q.s1.top = -1;
    q.s2.top = -1;
    int choice,val;
    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d",&val);
                enqueue(&q,val);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                traverse(&q);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }


    
}
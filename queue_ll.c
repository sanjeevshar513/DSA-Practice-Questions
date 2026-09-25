#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;

int isEmpty() {
    if (front == NULL) {
        return 1;  
    } else {
        return 0;  
    }
}


void enqueue(int val){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr ->data =val;
    ptr ->next = NULL;
    if(front == NULL){
        front = ptr;
        rear = ptr;
    }
    else{
        rear->next =ptr;
        rear = ptr;
    }
}

void dequeue(){
    struct Node *temp = front;
    if(isEmpty()){
        printf("Queue is Empty:");
        return;
    }
    printf("%d deleted from queue\n",front->data);
    front = front ->next;

    if(front ==NULL){
        rear = NULL;
    }
    free(temp);
}

void traverse(){
    if(isEmpty()){
        printf("Queue is Empty:");
        return;
    }
    printf("Queue:");
    for(struct Node *ptr = front; ptr != NULL;ptr = ptr->next){
        printf("%d\n",ptr->data);
    }
}

int main(){
    int val,choice;
    while(1){
        printf("\nMain Menu\n1.Enqueue\n2.Dequeue\n3.isEmpty\n4.Traverse\n5.Exit\nEnter option:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
              printf("Enter value to be added");
              scanf("%d",&val);
              enqueue(val);
              break;
            
            case 2:
              dequeue();
              break;
            
            case 3:
              if(isEmpty()){
                  printf("Queue is Empty");
              }
              else{
                  printf("Queue is not Empty");
              }
              break;

            case 4:
              traverse();
              break;
            
            case 5:
              printf("Exiting program successfully");
              exit(0);
            
            default:
              printf("Invalid input");
              break;
        }
    }
}
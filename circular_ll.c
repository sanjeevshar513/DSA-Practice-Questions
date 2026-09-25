#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void CircularLinkedListTraversal(struct Node *head){
    struct Node *ptr = head;
    do{
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);

}

struct Node * InsertAtFirst(struct Node *head,int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *temp = head->next;

    while(temp->next!= head){
        temp = temp->next;
    }
    temp->next = ptr;
    ptr ->next = head;
    head = ptr;
    return head;
}

struct Node * InsertAtIndex(struct Node *head,int data, int index){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    if(index == 0){
        struct Node *temp = head;
        while(temp->next != head){   
            temp = temp->next;
        }
        temp->next = ptr;   
        ptr->next = head;   
        head = ptr;         
        return head;
    }
    struct Node *temp = head;
    for(int i=0;i<index-1;i++){
        temp = temp->next;
    }
    ptr->next = temp->next;
    temp->next = ptr;
    return head;
}

struct Node * InsertAtEnd(struct Node *head,int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *temp = head;

    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next =ptr;
    ptr->next = head;
    return head;
}

struct Node * InsertAfterNode(struct Node *head,int data)

int main(){
    struct Node *head,*second,*third;
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head ->data = 10;
    head ->next = second;

    second ->data = 20;
    second ->next = third;

    third ->data = 30;
    third ->next = head;

    printf("Before Linked List\n");
    CircularLinkedListTraversal(head);
    //head = InsertAtFirst(head,50);
    //head = InsertAtIndex(head,50,2);
    head = InsertAtEnd(head,50); 
    printf("\nAfter Linked List\n");
    CircularLinkedListTraversal(head);
}
#include <stdio.h>
#include <stdlib.h>

struct queue {
    int front;
    int rear;
    int Q[10];
};
int max = 10;

int isEmpty(struct queue q) {
    return (q.front == -1 && q.rear == -1);
    
}

int isFull(struct queue q) {
    return (q.rear == max - 1);
}

void Enqueue(struct queue *q, int val) {
    if (isFull(*q)) {
        printf("Overflow\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->Q[q->rear] = val;
    }
}

void Traverse(struct queue *q) {
    if (isEmpty(*q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("Queue[%d] = %d\n", i, q->Q[i]);
    }
}

void Dequeue(struct queue *q) {
    if (isEmpty(*q)) {
        printf("Underflow\n");
    } else if (q->front == q->rear) {  
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
}

int main() {
    struct queue q;
    q.front = q.rear = -1;
    int choice;

    printf("-------Queue Operations------\n");
    printf("-----MENU-----\n");
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Traverse\n");
    printf("4.IsEmpty\n");
    printf("5.IsFull\n");
    printf("6.Exit\n");

    printf("Enter Choice: ");
    scanf("%d", &choice);

    while (choice != 6) {
        switch (choice) {
        case 1:
            {
                int val;
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                Enqueue(&q, val);
            }
            break;

        case 2:
            Dequeue(&q);
            break;

        case 3:
            Traverse(&q);
            break;

        case 4:
            isEmpty(q);
            break;

        case 5:
            isFull(q);
            break;

        case 6:
            printf("Program Ended\n");
            break;

        default:
            printf("Invalid Choice\n");
            break;
        }
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
    }

    return 0;
}

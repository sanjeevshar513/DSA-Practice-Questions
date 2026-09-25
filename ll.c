#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node* next;
};

// Helper function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 1. Search
void search(struct Node* head, int value) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == value) {
            printf("Element %d found at position %d.\n", value, pos);
            return;
        }
        head = head->next;
        pos++;
    }
    printf("Element %d not found in the list.\n", value);
}

// 2. Display
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// 3. Count
int count(struct Node* head) {
    int cnt = 0;
    while (head != NULL) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

// 4. Count by recursion
int countRecursive(struct Node* head) {
    if (head == NULL) return 0;
    return 1 + countRecursive(head->next);
}

// 5. Find the sum of all nodes
int findSum(struct Node* head) {
    int sum = 0;
    while (head != NULL) {
        sum += head->data;
        head = head->next;
    }
    return sum;
}

// 6. Find the largest element
void findLargest(struct Node* head) {
    if (head == NULL) { printf("List is empty.\n"); return; }
    int maxVal = head->data;
    while (head != NULL) {
        if (head->data > maxVal) maxVal = head->data;
        head = head->next;
    }
    printf("Largest element: %d\n", maxVal);
}

// 7. Find the smallest element
void findSmallest(struct Node* head) {
    if (head == NULL) { printf("List is empty.\n"); return; }
    int minVal = head->data;
    while (head != NULL) {
        if (head->data < minVal) minVal = head->data;
        head = head->next;
    }
    printf("Smallest element: %d\n", minVal);
}

// 8. Insert a node at the beginning
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning.\n", value);
}

// 9. Insert a node at the end
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d at the end.\n", value);
}

// 10. Insert a node at a given position (1-based index)
void insertAtPosition(struct Node** head, int value, int pos) {
    if (pos < 1) { printf("Invalid position!\n"); return; }
    if (pos == 1) { insertAtBeginning(head, value); return; }
    
    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) temp = temp->next;

    if (temp == NULL) {
        printf("Position out of bounds!\n");
    } else {
        struct Node* newNode = createNode(value);
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Inserted %d at position %d.\n", value, pos);
    }
}

// 11. Insert before a given value
void insertBeforeValue(struct Node** head, int value, int target) {
    if (*head == NULL) { printf("List is empty.\n"); return; }
    if ((*head)->data == target) { insertAtBeginning(head, value); return; }

    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->data != target) temp = temp->next;

    if (temp->next == NULL) {
        printf("Value %d not found.\n", target);
    } else {
        struct Node* newNode = createNode(value);
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Inserted %d before %d.\n", value, target);
    }
}

// 12. Insert after a given value
void insertAfterValue(struct Node* head, int value, int target) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != target) temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found.\n", target);
    } else {
        struct Node* newNode = createNode(value);
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Inserted %d after %d.\n", value, target);
    }
}

// 13. Insert into a sorted linked list
void insertSorted(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL && temp->next->data < value) temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d in sorted order.\n", value);
}

// 14. Delete the first node
void deleteFirst(struct Node** head) {
    if (*head == NULL) { printf("List is empty.\n"); return; }
    struct Node* temp = *head;
    *head = (*head)->next;
    printf("Deleted first node (%d).\n", temp->data);
    free(temp);
}

// 15. Delete the last node
void deleteLast(struct Node** head) {
    if (*head == NULL) { printf("List is empty.\n"); return; }
    if ((*head)->next == NULL) {
        printf("Deleted last node (%d).\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) temp = temp->next;
    printf("Deleted last node (%d).\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

// 16. Delete a node at a given position
void deleteAtPosition(struct Node** head, int pos) {
    if (*head == NULL || pos < 1) { printf("Invalid request.\n"); return; }
    if (pos == 1) { deleteFirst(head); return; }

    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds!\n");
    } else {
        struct Node* del = temp->next;
        temp->next = del->next;
        printf("Deleted node at position %d (%d).\n", pos, del->data);
        free(del);
    }
}

// 17. Delete a node containing a given value (First occurrence)
void deleteByValue(struct Node** head, int target) {
    if (*head == NULL) { printf("List is empty.\n"); return; }
    if ((*head)->data == target) { deleteFirst(head); return; }

    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->data != target) temp = temp->next;

    if (temp->next == NULL) {
        printf("Value %d not found.\n", target);
    } else {
        struct Node* del = temp->next;
        temp->next = del->next;
        printf("Deleted node with value %d.\n", target);
        free(del);
    }
}

// 18. Delete all occurrences of a value
void deleteAllOccurrences(struct Node** head, int target) {
    while (*head != NULL && (*head)->data == target) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    struct Node* temp = *head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == target) {
            struct Node* del = temp->next;
            temp->next = del->next;
            free(del);
        } else {
            temp = temp->next;
        }
    }
    printf("Deleted all occurrences of %d.\n", target);
}

// 19. Delete the entire linked list
void deleteEntireList(struct Node** head) {
    struct Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    printf("Entire list deleted successfully.\n");
}

// 20. Reverse a singly linked list
void reverseList(struct Node** head) {
    struct Node *prev = NULL, *curr = *head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
    printf("List reversed successfully.\n");
}

// 21. Find the middle node
void findMiddle(struct Node* head) {
    if (head == NULL) { printf("List is empty.\n"); return; }
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element is: %d\n", slow->data);
}

// 22. Find the nth node from the end
void findNthFromEnd(struct Node* head, int n) {
    if (head == NULL || n <= 0) { printf("Invalid request.\n"); return; }
    struct Node *mainPtr = head, *refPtr = head;
    for (int i = 0; i < n; i++) {
        if (refPtr == NULL) {
            printf("Position exceeds list size.\n");
            return;
        }
        refPtr = refPtr->next;
    }
    while (refPtr != NULL) {
        mainPtr = mainPtr->next;
        refPtr = refPtr->next;
    }
    printf("%d-th node from end is: %d\n", n, mainPtr->data);
}

// 23. Find whether a linked list is sorted
void isSorted(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        printf("List is sorted.\n");
        return;
    }
    int inc = 1, dec = 1;
    struct Node* temp = head;
    while (temp->next != NULL) {
        if (temp->data > temp->next->data) inc = 0;
        if (temp->data < temp->next->data) dec = 0;
        temp = temp->next;
    }
    if (inc || dec) printf("List is sorted.\n");
    else printf("List is NOT sorted.\n");
}

// 24. Remove duplicate elements
void removeDuplicates(struct Node* head) {
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = head;
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (ptr1->data == ptr2->next->data) {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            } else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
    printf("Duplicates removed.\n");
}

// 25. Count occurrences of a particular value
void countOccurrences(struct Node* head, int target) {
    int cnt = 0;
    while (head != NULL) {
        if (head->data == target) cnt++;
        head = head->next;
    }
    printf("Value %d occurs %d times.\n", target, cnt);
}

// 26. Find the second largest element
void findSecondLargest(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        printf("At least two nodes required.\n");
        return;
    }
    int first = INT_MIN, second = INT_MIN;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data > first) {
            second = first;
            first = temp->data;
        } else if (temp->data > second && temp->data != first) {
            second = temp->data;
        }
        temp = temp->next;
    }
    if (second == INT_MIN) printf("No distinct second largest element found.\n");
    else printf("Second largest element: %d\n", second);
}

// 27. Find the second smallest element
void findSecondSmallest(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        printf("At least two nodes required.\n");
        return;
    }
    int first = INT_MAX, second = INT_MAX;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data < first) {
            second = first;
            first = temp->data;
        } else if (temp->data < second && temp->data != first) {
            second = temp->data;
        }
        temp = temp->next;
    }
    if (second == INT_MAX) printf("No distinct second smallest element found.\n");
    else printf("Second smallest element: %d\n", second);
}

// 28. Detect a loop/cycle in a linked list (Floyd's Cycle Algorithm)
void detectLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            printf("Loop/Cycle detected in the list.\n");
            return;
        }
    }
    printf("No loop detected in the list.\n");
}

// 29. Move the last node to the beginning
void moveLastToBeginning(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) return;
    struct Node *secLast = NULL, *last = *head;
    while (last->next != NULL) {
        secLast = last;
        last = last->next;
    }
    secLast->next = NULL;
    last->next = *head;
    *head = last;
    printf("Moved last node to beginning.\n");
}

// 30. Sort a linked list (Bubble Sort by Data Swapping)
void sortList(struct Node* head) {
    if (head == NULL) return;
    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    printf("Linked list sorted.\n");
}

int main() {
    struct Node* head = NULL;
    int choice, val, target, pos;

    while (1) {
        printf("\n================ LINKED LIST MENU ================\n");
        printf(" 1. Search                          2. Display\n");
        printf(" 3. Count                           4. Count by recursion\n");
        printf(" 5. Find sum of nodes              6. Find largest element\n");
        printf(" 7. Find smallest element          8. Insert at beginning\n");
        printf(" 9. Insert at end                  10. Insert at position\n");
        printf("11. Insert before value            12. Insert after value\n");
        printf("13. Insert into sorted list        14. Delete first node\n");
        printf("15. Delete last node               16. Delete at position\n");
        printf("17. Delete node with value         18. Delete all occurrences\n");
        printf("19. Delete entire list             20. Reverse linked list\n");
        printf("21. Find middle node               22. Find N-th from end\n");
        printf("23. Check if sorted                24. Remove duplicates\n");
        printf("25. Count occurrences of value     26. Find 2nd largest\n");
        printf("27. Find 2nd smallest              28. Detect loop/cycle\n");
        printf("29. Move last node to beginning    30. Sort linked list\n");
        printf(" 0. Exit\n");
        printf("==================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  printf("Enter search value: "); scanf("%d", &val); search(head, val); break;
            case 2:  display(head); break;
            case 3:  printf("Count: %d\n", count(head)); break;
            case 4:  printf("Count (recursive): %d\n", countRecursive(head)); break;
            case 5:  printf("Sum of nodes: %d\n", findSum(head)); break;
            case 6:  findLargest(head); break;
            case 7:  findSmallest(head); break;
            case 8:  printf("Enter value: "); scanf("%d", &val); insertAtBeginning(&head, val); break;
            case 9:  printf("Enter value: "); scanf("%d", &val); insertAtEnd(&head, val); break;
            case 10: printf("Enter value and position: "); scanf("%d %d", &val, &pos); insertAtPosition(&head, val, pos); break;
            case 11: printf("Enter value and target value: "); scanf("%d %d", &val, &target); insertBeforeValue(&head, val, target); break;
            case 12: printf("Enter value and target value: "); scanf("%d %d", &val, &target); insertAfterValue(head, val, target); break;
            case 13: printf("Enter value: "); scanf("%d", &val); insertSorted(&head, val); break;
            case 14: deleteFirst(&head); break;
            case 15: deleteLast(&head); break;
            case 16: printf("Enter position: "); scanf("%d", &pos); deleteAtPosition(&head, pos); break;
            case 17: printf("Enter target value: "); scanf("%d", &target); deleteByValue(&head, target); break;
            case 18: printf("Enter target value: "); scanf("%d", &target); deleteAllOccurrences(&head, target); break;
            case 19: deleteEntireList(&head); break;
            case 20: reverseList(&head); break;
            case 21: findMiddle(head); break;
            case 22: printf("Enter N: "); scanf("%d", &pos); findNthFromEnd(head, pos); break;
            case 23: isSorted(head); break;
            case 24: removeDuplicates(head); break;
            case 25: printf("Enter target value: "); scanf("%d", &target); countOccurrences(head, target); break;
            case 26: findSecondLargest(head); break;
            case 27: findSecondSmallest(head); break;
            case 28: detectLoop(head); break;
            case 29: moveLastToBeginning(&head); break;
            case 30: sortList(head); break;
            case 0:  printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
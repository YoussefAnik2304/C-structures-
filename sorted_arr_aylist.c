#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure of a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to perform the bubble sort on the linked list
void bubbleSort(struct Node* head) {
    int swapped, temp;
    struct Node* current;
    struct Node* tail = NULL;

    // If the list is empty or has only one node, it's already sorted
    if (head == NULL || head->next == NULL)
        return;

    do {
        swapped = 0;
        current = head;

        while (current->next != tail) {
            if (current->data > current->next->data) {
                // Swap the data of current and next nodes
                temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        tail = current;
    } while (swapped);
}

// Function to print the linked list elements in rows of 5
void printList(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        printf("%5d ", head->data);
        head = head->next;
        count++;
        if (count % 5 == 0) {
            printf("\n");
        }
    }
}

int main() {
    struct Node* head = NULL;
    srand(time(NULL)); // Seed the random number generator

    // Generate and insert 100 random integers into the linked list
    for (int i = 0; i < 100; i++) {
        int randomValue = rand() % 1000; // Random value between 0 and 999
        insertEnd(&head, randomValue);
    }

    printf("Original list:\n");
    printList(head);

    // Perform bubble sort to rearrange the list in sorted order
    bubbleSort(head);

    printf("\n\nSorted list:\n");
    printList(head);

    return 0;
}

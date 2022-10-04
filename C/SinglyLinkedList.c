#include <stdio.h>    
#include <stdlib.h>

    struct Node {
        int data;
        struct Node* next;
    };

    struct Node* head;
    // struct Node* tail;

    void addNode(int value) {
        struct Node *newNode, *temp;
        newNode = (struct Node *) malloc(sizeof(struct Node *));
        newNode->data = value;

        if(newNode == NULL) {
            printf("Invalid");
        } else {
            if(head == NULL) {
                newNode->next = NULL;
                head = newNode;
            } else {
                temp = head;
                while (temp->next != NULL) {
                    temp = temp-> next;
                }
                temp->next = newNode;
                newNode->next = NULL;
            }
        }
    }

    void display() {
        struct Node *current;
        current = head;
        if(current == NULL){
            printf("list is empty\n");
        }else {
            printf("Nodes of singly linked list: ");
            while(current != NULL) {
                printf("%d", current->data);
                current = current->next;
            }
        }
    }
    

int main() {
    
    // struct SinglyLinkedList sList;

    addNode(1);
    addNode(2);
    addNode(3);
    addNode(4);
    display();
    return 0;
}
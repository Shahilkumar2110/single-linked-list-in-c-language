#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};


void display(struct node *head) {
    struct node *temp = head;
    printf("The linked list: ");
    while (temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL, *newnode, *temp, *insertnode;
    int size, position, i;

    
    printf("Enter the size of linked list: ");
    scanf("%d", &size);
    
    printf("Enter the elements in the linked list:\n");
    for (i = 1; i <= size; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        scanf("%d", &newnode->data);
        newnode->link = NULL;

        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->link = newnode;
            temp = newnode;
        }
    }

    display(head);

    
    printf("Enter the position where you want to insert the element: ");
    scanf("%d", &position);

    if (position < 1 || position > size + 1) {
        printf("Invalid position!\n");
    } else {
        insertnode = (struct node*)malloc(sizeof(struct node));
        if (insertnode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        printf("Enter the data you want to insert: ");
        scanf("%d", &insertnode->data);

        if (position == 1) {
            insertnode->link = head;
            head = insertnode;
        } else {
            temp = head;
            for (i = 1; i < position - 1 && temp != NULL; i++) {
                temp = temp->link;
            }
            if (temp != NULL) {
                insertnode->link = temp->link;
                temp->link = insertnode;
            }
        }
        size++;
    }

    display(head);

    
    int del;
    printf("Enter the position to delete: ");
    scanf("%d", &del);

    if (del < 1 || del > size) {
        printf("Invalid position!\n");
    } else {
        temp = head;
        if (del == 1) {
            head = head->link;
            free(temp);
        } else {
            struct node *prev = NULL;
            for (i = 1; i < del; i++) {
                prev = temp;
                temp = temp->link;
            }
            if (temp->link == NULL) { 
                prev->link = NULL;
            } else {
                prev->link = temp->link;
            }
            free(temp);
        }
        size--; 
    }

    display(head);

    temp = head;
    while (temp != NULL) {
        struct node *nextnode = temp->link;
        free(temp);
        temp = nextnode;
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *link;
};

int main()
{
    int a;
    printf("enter the total node"); 
    scanf("%d", &a);
    struct node *newnode, *head, *tail;
    head = 0;
    tail = 0;
    printf("enter the value of node");
    for (int i = 0; i < a; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->link = 0;
        newnode->prev = 0;
        if (head == 0)
        {
            newnode->link = newnode;
            newnode->prev = newnode;
            tail = newnode;
            head = newnode;
        }
        else
        {
            newnode->link = head;
            newnode->prev = tail;
            tail->link = newnode;
            head->prev = newnode;
            tail = newnode;
        }
    }

    tail = head;
    printf("to show\n ");
    do
    {
        printf(" %d ", tail->data);
        tail = tail->link;

    } while (tail != head);
    printf("\n");

    tail = head;
    int position;
    printf("enter the position for insertion");
    scanf("%d", &position);
    struct node *insertion;
    insertion = (struct node *)malloc(sizeof(struct node));

    printf("enter the data for insertion");
    scanf("%d", &insertion->data);
    if (position == 1)
    {
       insertion->link=tail;
       insertion->prev=tail->prev;
       tail->prev->link=insertion;
       tail->prev=insertion;
       head=insertion;  

    }
    else
    {

        for (int i = 1; i < position - 1; i++)
        {
            tail = tail->link;
        }
        insertion->link = tail->link;
        tail->link->prev = insertion;
        tail->link = insertion;
        insertion->prev = tail;
    }

    tail = head;
    printf("insertion list are\n");
    do
    {
        printf(" %d ", tail->data);
        tail = tail->link;
    } while (tail != head);
    printf("\n");

    int space;
    printf("enter the position for deletion");
    scanf("%d", &space);
    tail = head;
    if (space == 1)
    {
        struct node *s = head;
        tail->prev->link = tail->link;
        tail->link->prev = tail->prev;
        head = tail->link;
        free(s);
    }
    else
    {
        for (int i = 1; i < space; i++)
        {
            tail = tail->link;
        }
        struct node *s = tail;
        tail->prev->link = tail->link;
        tail->link->prev = tail->prev;
        free(s);
    }

    printf("to show deletion list\n");
    tail = head;
    do
    {
        printf(" %d ", tail->data);
        tail = tail->link;
    } while (tail != head);

    printf("\n");



    struct node *clear;
    tail = head;
    do
    {
        clear = tail;
        tail = tail->link;
        free(clear);
    } while (tail != head);
    head = NULL;  



    return 0;
}

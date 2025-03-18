#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
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
    printf("enter the value of list");

    for (int i = 0; i < a; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->link = 0;
        if (head == 0)
        {
            head = newnode;
            newnode->link = head;
            tail = newnode;
        }
        else
        {
            tail->link = newnode;
            tail = newnode;
            tail->link = head;
        }
    }

    printf("show list\n");
    tail = head;
    do
    {
        printf(" %d ", tail->data);
        tail = tail->link;
    } while (tail != head);
    tail = head;
    printf("\n");
    int position;
    printf("enter the position for insertion");
    scanf("%d", &position);
    struct node *insertion;
    insertion = (struct node *)malloc(sizeof(struct node));
    printf("enter the data for insertion");
    scanf("%d", &insertion->data);
    if (position == 1)
    {
        insertion->link = head;
        while (tail->link != head)
        {
            tail = tail->link;
        }
        tail->link = insertion;
        head=insertion;

    }
    else
    {
        tail = head;
        for (int i = 1; i < position - 1; i++)
        {
            tail = tail->link;
        }
        insertion->link = tail->link;
        tail->link = insertion;
    }

    tail = head;
    printf("insertion list\n");
    do
    {
        printf(" %d ", tail->data);
        tail = tail->link;

    } while (tail != head);
    printf("\n");

    tail=head;
    int space;
    printf("enter the position for deletion");
    scanf("%d",&space);
    
    if (space==1)
    {
        struct node *s=tail;
        tail=tail->link;
        head=tail;
        while (tail->link!=s)
        {
            tail=tail->link;
        }
        tail->link=head;
        free(s);
    }else{
        tail=head;
        struct node *prev =0;
        for (int i = 1; i < space; i++)
        {
            prev = tail;
            tail=tail->link;
        }
        prev->link=tail->link;
        free(tail);
    }

    tail=head;
    do
    {
        printf(" %d ", tail->data);
        tail=tail->link;
    } while (tail!=head);
    
    tail=head;
    struct node* delete=0;
    do
    {
        delete=tail;
        tail=tail->link;
        free(delete);
    } while (tail!=head);
    
    

    return 0;
}

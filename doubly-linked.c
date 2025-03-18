#include <stdio.h>
#include <stdlib.h>

struct node  {
    int data;
    struct node *link;
    struct node *prev;

};
int main()
{
    struct node *newnode,*head,*temp;
    head=0;
    int a ;
    printf("enter the total node you want..");
    scanf("%d",&a);
    printf("enter the list value");
    for (int i = 0; i < a; i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->link=0;
        newnode->prev=0;

        if (head==0)
        {
            temp=newnode;
            head=newnode;
        }else{
            newnode->prev=temp;
            temp->link=newnode;
            temp=newnode;
        }
    }

    temp=head;
    printf("display the double linked list\n");
    while (temp!=0)
    {
        printf("%d  ",temp->data);
        if (temp->link==0)
        {
            break;
        }
        
        temp=temp->link;
    }
    printf("\n");
    
    printf("display by reverse linked \n");
    while (temp!=0)
    {
        printf("%d  ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
    
    temp=head;
    int position;
    struct node *insertion;
    printf("enter the position for insertion");
    scanf("%d",&position);
    insertion=(struct node*)malloc(sizeof(struct node));
    printf("enter the data for insertion");
    scanf("%d",&insertion->data);

    if (position ==1)
    {
        insertion->prev=0;
        insertion->link=head;
        temp->prev=insertion;
        head=insertion;
    }else {
       for (int i = 1; i <position-1; i++)
       {
        
        temp=temp->link;
       }
       if (temp->link!=0)
       {
       insertion->prev=temp;
       insertion->link=temp->link;
       temp->link->prev = insertion;
       temp->link=insertion;
       }else{
            insertion->link=0;
            insertion->prev=temp;
            temp->link=insertion;
    }
    }

    temp=head;
    printf("the list are\n");
    while (temp!=0)
    {
        printf("%d  ",temp->data);
        temp=temp->link;
    }
    printf("\n");
    
    printf("for deletion\n");
    int space;
    printf("enter the position for deletion");
    scanf("%d",&space);
    temp=head;
    if (space==1)
    {  struct node* clean=temp;
        temp=temp->link;
        head=temp;
        temp->prev=0;
        free(clean);
    }else{
        struct node *back;
        for (int i = 1; i < space && temp!=0; i++)
        {
            back=temp;
            temp=temp->link;
        }
        if (temp->link==0)
        {
            back->link= 0;
            free(temp);
        }else{
            back->link=temp->link;
            temp->link->prev=back;
            free(temp);
        }
        
    }

    temp=head;
    printf("your final list is \n");
    while (temp!=0)
    {
        printf("%d  ",temp->data);
        
        temp=temp->link;
        
    }
     
     temp=head;
     struct node *all;
     while (temp!=0)
     {
        all=temp;
        temp=temp->link;
        free(all);
     }
     
    


    return 0;
}

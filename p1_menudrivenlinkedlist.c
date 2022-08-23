#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};


struct node *head;
void traverse()
{
    struct node *temp=head;
    if(head==NULL)
    printf("Empty list.\n");
    else
    {
        printf("The elements of the linked list are:\n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}

void insert_at_start()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data of the node you want to insert:\n");
    scanf("%d",&temp->data);
    temp->next==NULL;

    if(head==NULL)
    printf("The list is empty.\n");
    else
    {
        temp->next=head;    //the first node i.e head attaches to the link (*next) of given node temp
        head=temp;  //hence, now the new first node becomes the given node
    }
}

void insert_at_end()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data of the node you want to insert:\n");
    scanf("%d",&temp->data);
    temp->next==NULL;

    if(head==NULL)
    head=temp;
    else
    {
        struct node *p;
        p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
}

void count_nodes()
{
    int count=0;
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("The length of the list is %d.\n", count);
}
int main()
{
    int ch;
    printf("1. Traversal of the linked list.\n2. Insert a node at the beginning.\n3. Insert a node at the end.\n4. Count the total no. of nodes.\n\nEnter your choice:\n");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1:
        traverse();
        break;
        case 2:
        insert_at_start();
        break;
        case 3:
        insert_at_end();
        break;
        case 4:
        count_nodes();
        break;
        default:
        printf("Invalid Input.\n");

    }
    return 0;
    
}

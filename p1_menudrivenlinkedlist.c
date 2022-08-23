#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *traverse(struct node *head)
{
    struct node *temp=head;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }

    return head;
    
}

void check(struct node *lin)
{
    
    if(lin==NULL)
    {
        printf("The list is empty.\n");
    }
    else
    printf("The list is not empty.\n");
}

struct node *insert_at_start(struct node *head)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data of the node you want to insert:\n");
    scanf("%d",&temp->data);
    

    if(head==NULL)
    printf("The list is empty.\n");
    else
    {
        temp->next=head;    //the first node i.e head attaches to the link (*next) of given node temp
        head=temp;  //hence, now the new first node becomes the given node
    }
    return head;
}
struct node *insert_at_middle(struct node *head)
{
    int index;
    struct node *temp= (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of the node you want to insert:\n");
    scanf("%d",&temp->data);
    printf("Enter index:\n");
    scanf("%d",&index);
    struct node *p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    temp->next=p->next;  //as soon as it reaches position preceding key node, node temp links to the key node at index (i.E node succeeding p)
    p->next=temp;       //new position of node temp is next to position p   

    return head;
}

struct node *insert_at_end(struct node *head)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data of the node you want to insert:\n");
    scanf("%d",&temp->data);
    temp->next==NULL;   //as we're inserting it at the end

    if(head==NULL)  //i.e if the list is empty
    head=temp;  
    else
    {
        struct node *p; //we create node p
        p=head;     
        while(p->next!=NULL)
        {
            p=p->next;      //we traverse till we find the last node whose link is NULL
        }
        p->next=temp;       //once we find last node, p links to the last node. then we make sure that the link of last node points to the given node
    }
    return head;
}

struct node *delete_at_position(struct node *head)
{
    int i,index;
    struct node *p, *q;
    p=head;
    q=head->next;
    printf("Enter index at which the corresponding node will be deleted.\n");
    scanf("%d",&index);

    for(i=0;i<index;i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;    //p is at index, and now the node p at index becomes the succeeding node q, and node q is deleted as q = p->next basically)
    free(q);
    return head;
}

struct node *delete_by_key(struct node *head)
{
    int key;
    printf("Enter key:\n");
    scanf("%d", &key);
    struct node *p=head;
    struct node *q=head->next;
    while(q->data!=key && q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    } //either we have reached the end of list, or we have found the key at q->data


if(q->data==key)
{
    p->next=q->next;
    free(q);
}
else
printf("Key not found.\n");
return head;
}

void count_nodes(struct node *head)
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
void print(struct node *list)
{

    if(list->next!=NULL)
    {
        printf("%d-->",list->data);

        if(list->next->next ==NULL)
        printf("%d",list->next->data);

        print(list->next);
    }

}

void create(struct node *list, int num)
{
    static int c=0;
    //int i;


    scanf("%d", &list->data);



    c++;
    if(c==num-1)
    list->next=NULL;
    else
    {
        list->next=(struct node *)malloc(sizeof(struct node));
        create(list->next,num);
    }

    



}

int main()
{
    int i,ch,n;
    struct node *ptr= (struct node*)malloc(sizeof(struct node));
    struct node *nd= (struct node*)malloc(sizeof(struct node));;
    printf("Enter no. of nodes:\n");
    scanf("%d", &n);

    printf("Enter data of the linked list:\n");
    create(ptr,n);
    //for(i=0;i<n;i++)
    {
        
        scanf("%d", &ptr->data);

        if(i!=n-1)
        {
        ptr->next= (struct node*)malloc(sizeof(struct node));
        ptr=ptr->next;
        }
        else
        ptr->next=NULL;
    }
    
    printf("\n1. Traversal of the linked list.\n2. Check if list is empty.\n3. Insert a node at the beginning.\n4. Insert a node in the middle.\n5. Insert a node at the end.\n6. Delete a node at a certain position.\n7. Delete a node by key.\n8. Count the total no. of nodes.\n\nEnter your choice:\n");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1:
        nd= traverse(ptr);
        print(nd);
        break;
        case 2:
        check(ptr);
        break;
        case 3:
        nd= insert_at_start(ptr);
        print(nd);
        break;
        case 4:
        nd =insert_at_middle(ptr);
        print(nd);
        break;
        case 5:
        nd =insert_at_end(ptr);
        print(nd);
        break;
        case 6:
        nd=delete_at_position(ptr);
        print(nd);
        break;
        case 7:
        nd= delete_by_key(ptr);
        print(nd);
        break;
        case 8:
        count_nodes(ptr);
        break;
        default:
        printf("Invalid Input.\n");
        break;

    }
    return 0;
    
}

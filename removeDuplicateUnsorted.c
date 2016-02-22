#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *root = NULL;

void Listinit()
{
    return;
}

void insertRoot()
{
    int n;
    struct node *Node;
    printf("Enter a data to save : ");
    scanf(" %d", &n);
    Node = (struct node *)malloc(sizeof(struct node));
    Node->data = n;
    if (root == NULL) {
        Node->next = NULL;
        root = Node;
    } else {
        Node->next = root;
        root = Node;
    }
}

void display()
{
    struct node *Node;
    printf("\nList is ROOT--->");
    Node = root;
    while(Node) {
        printf("%d--->", Node->data);
        Node = Node->next;
    }
    printf("TAIL\n");
}

void deleteDuplicate()
{
    struct node *ptr1, *ptr2, *dup;
    ptr1 = root;
    while(ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        while(ptr2->next) {
            if(ptr1->data == ptr2->next->data) {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            } else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
    return;
}

void main()
{
    int choice = 7;
    Listinit();
    while(1) 
    {
        printf("LinkedList Operations:\n");
        printf("1. Insert Head\n2. Display\n3. DeleteDuplicate\n7. Exit\n");
        printf("Enter your choice : ");
        scanf(" %d", &choice);
        switch (choice)
        {
            case 1  :   insertRoot();
            break;
            case 2  :   display();
            break;
            case 3  :   deleteDuplicate();
            break;
            default :
            exit(0);
        }
    } 
}
#include <stdlib.h>
#include <stdio.h>

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
    struct node *current, *dup;
    current = root;
    if (root == NULL) {
        return;
    }
    while(current->next != NULL) {
        if(current->data == current->next->data) {
            dup = current->next;
            current->next = current->next->next;
            free(dup);
        } else {
            current = current->next;
        }
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
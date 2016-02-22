#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    struct node *next;
    int data;
} *root = NULL, *tail = NULL;

int Listinit()
{
    tail = root;
    return 0;
}

void insertRoot()
{
    int n;
    struct node *Node;
    printf("\nEnter data to store : ");
    scanf(" %d", &n);
    Node = (struct node *)malloc(sizeof(struct node));
    Node->data = n;
    Node->prev = NULL;
    if(root == NULL) {
        Node->next = NULL;
        tail = Node;
    } else {
        Node->next = root;
        root->prev = Node;
    }
    root = Node;
}

void insertTail()
{
    struct node *Node;
    int n;
    Node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data to save : ");
    scanf(" %d", &n);
    Node->data = n;
    Node->next = NULL;
    
    if(tail == NULL) {
        Node->prev = NULL;
        root = Node;
    } else {
        Node->prev = tail;
        tail->next = Node;
    }
    tail = Node;
}

void display()
{
    struct node *Node;
    printf("The Linked List is ROOT--->");
    Node = root;
    while(Node)
    {
        printf("%d--->", Node->data);
        Node = Node->next;
    }
    printf("TAIL\n");
}

void displayReverse()
{
    struct node *Node;
    printf("The Linked list is TAIL<---");
    Node = tail;
    while(Node) {
        printf("%d<---", Node->data);
        Node = Node->prev;
    }
    printf("ROOT\n");
}

searchNode()
{
    int n;
    struct node * Node;
    printf("Enter the value to search : ");
    scanf(" %d", &n);
    Node = root;
    while(Node) {
        if(Node->data == n) {
            printf("Found %d \n", n);
            return;
        }
        Node = Node->next;
    }
    printf("%d is not present in Linked List\n", n);
}

void deleteNode()
{
    struct node *Node;
    int n;
    printf("Enter the value to delete : ");
    scanf(" %d", &n);
    printf("11");
    Node = root;
    if (Node == NULL) {
        printf("\nThe list is empty. \n");
        return;
    } else if (Node->data == n) {
        if(root == tail) {
            root = NULL;
            tail = NULL;
        } else {
            root = Node->next;
            Node->next->prev = NULL;
        }
        free(Node);
        return;
    }
    Node = Node->next;
    while(Node != NULL && Node->data != n ) {
        Node = Node->next;
    }
    
    if(Node == tail) {
        tail = tail->prev;
        tail->next = NULL;
        free(Node);
        return;
    } else if (Node != NULL) {
        Node->prev->next = Node->next;
        Node->next->prev = Node->prev;
        free(Node);
        return;
    }
    printf("%d not found in the list\n", n);
}

int main()
{
    int choice = 7;
    Listinit();
    while(1) 
    {
        printf("LinkedList Operations:\n");
        printf("1. Insert Head\n2. Insert Tail\n3. Display\n4. Display Reverse\n5. Search\n6. Delete\n7. Exit\n");
        printf("Enter your choice : ");
        scanf(" %d", &choice);
        switch (choice)
        {
            case 1  :   insertRoot();
            break;
            case 2  :   insertTail();
            break;
            case 3  :   display();
            break;
            case 4  :   displayReverse();
            break;
            case 5  :   searchNode();
            break;
            case 6  :   deleteNode();
            break;
            default :
            exit(0);
        }
    }   
}

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

void MiddleList()
{
    struct node *Slow, *Fast;
    Slow = root;
    Fast = root;
    if(root == NULL) {
        printf("List is empty\n");
    }
    while(Fast != NULL && Fast->next != NULL) {
        Fast = Fast->next->next;
        Slow = Slow->next;
    }
    printf("Middle element is %d \n", Slow->data);
}

void ReverseList()
{
    struct node *previous, *current, *next;
    previous = NULL;
    current = root;
    next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    root = previous;
}

void ReverseRecursiveList(struct node ** head)
{
    struct node *first, *rest;
    if(*head == NULL) {
        return;
    }
    first = *head;
    rest = first->next;
    
    if(rest == NULL) {
        return;
    }
    
    ReverseRecursiveList(&rest);
    
    first->next->next = first;
    first->next = NULL;
    
    *head = rest;
}

void main()
{
    int choice = 7;
    Listinit();
    while(1) 
    {
        printf("LinkedList Operations:\n");
        printf("1. Insert Head\n2. Display\n3. Middle\n4. Reverse List\n5. ReverseRecursiveList\n7. Exit\n");
        printf("Enter your choice : ");
        scanf(" %d", &choice);
        switch (choice)
        {
            case 1  :   insertRoot();
            break;
            case 2  :   display();
            break;
            case 3  :   MiddleList();
            break;
            case 4  :   ReverseList();
            break;
            case 5  :   ReverseRecursiveList(&root);
            break;
            default :
            exit(0);
        }
    }
}
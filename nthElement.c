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

void nthLast()
{
    int n, i = 1; 
    struct node *Node;
    Node = root;
    printf("Enter n to find nth to Last element: ");
    scanf(" %d", &n);
    if(n<=0)
        return;

    while(Node != NULL) {
        if(i == n) {
            printf("%d th element is %d \n", n, Node->data);
            return;
        }
        Node = Node->next;
        ++i;
    }
    printf("\n%d is larger than no of elements %d \n", n, i-1);
}

void main()
{
    int choice = 7;
    Listinit();
    while(1) 
    {
        printf("LinkedList Operations:\n");
        printf("1. Insert Head\n2. Display\n3. nth Element\n7. Exit\n");
        printf("Enter your choice : ");
        scanf(" %d", &choice);
        switch (choice)
        {
            case 1  :   insertRoot();
            break;
            case 2  :   display();
            break;
            case 3  :   nthLast();
            break;
            default :
            exit(0);
        }
    }
}
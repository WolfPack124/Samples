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
    int n, i;
    struct node *Node, *nthNode;
    Node = root;
    nthNode = root;
    printf("Enter n to find nth to Last element: ");
    scanf(" %d", &n);
    if(n<=0)
        return;
    for(i = 0 && Node != NULL; i < n-1; i++) {
        Node = Node->next;
    }
    while(Node->next != NULL) {
        Node = Node->next;
        nthNode = nthNode->next;
    }
    printf("\n%d th Last element is %d \n", n, nthNode->data);
}

void main()
{
    int choice = 7;
    Listinit();
    while(1) 
    {
        printf("LinkedList Operations:\n");
        printf("1. Insert Head\n2. Display\n3. nth To Last\n7. Exit\n");
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
#include <stdlib.h>
#include <stdio.h>

struct node {
  int data;
  struct node *next;
} *root = NULL, *tail = NULL;

int ListInit()
{
    tail = root;
    return 0;
}

int insertTail()
{
    int n;
    struct node * newNode;
    newNode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the value to save : ");
    scanf("%d", &n);
    
    newNode->data = n;
    newNode->next = NULL;

    if (root == NULL)
    {
        root = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
   return 0;
}

int insertRoot()
{
    int n;
    struct node * NewNode = NULL;
    NewNode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the value to save : ");
    scanf("%d", &n);

    NewNode->data = n;

    if (root == NULL)
    {
        tail = NewNode;
        root = NewNode; 
    } else {
        NewNode->next = root;
        root = NewNode;
    }
    

    return 0;
}


void display()
{
    printf("The linked list : ");
    struct node *Node;
    Node = root;
    printf("HEAD--->");
    while(Node) 
    {
        printf("%d --->", Node->data);
        Node = Node->next;
    }
    printf("TAIL\n");
}

void displayReverse()
{
    printf("\nLinked List Reverse order : ");
    struct node * current = NULL, *previous = NULL;
    current = tail;
    printf("Head--->");
    if(tail != NULL) {
        while(current != root) {
            previous = root;
            while(previous->next != current) {
                previous = previous->next;
            }
            printf("%d--->", current->data);
            current = previous;
        }
        printf("%d--->", current->data);
    }
    printf("TAIL\n");
}

void searchNode()
{
    int n;
    struct node * Node;
    printf("\nEnter a value to search : ");
    scanf(" %d", &n);
    Node = root;
    while (Node)
    {
        if (Node->data == n) {
            printf("You got it in the list! \n");
            return;
        }
        Node = Node->next;
    }
    printf("Sorry bro value not found! \n");
    return;
}

void deleteNode()
{
    int n;
    struct node *Node;
    printf("\nEnter the value to delete: ");
    scanf(" %d", &n);
    Node = root;
    
    if(root == NULL) {
        printf("List is Empty!\n");
        return;
    }
    
    if ( Node->data == n) {
        if(root == tail) {
            root = NULL;
            tail = NULL;
        } else{
            root = Node->next;
        }
        free(Node);
        return;
    }
    
    while(Node->next != NULL && Node->next->data != n) {
        Node = Node->next;
    }
    if(Node->next != NULL ) {
        if(Node->next == tail) {
            free(Node->next);
            Node->next = NULL;
            tail = Node;
        } else {
            Node->next = Node->next->next;
        }
        return;
    }
    printf("Value is not present to delete \n");
}

int main()
{
    int choice;
    ListInit();      

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

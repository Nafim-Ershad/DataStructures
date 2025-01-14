#include <stdio.h>
#include <stdlib.h>

// LinkedList
struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int data)
{
    // Create a new node like a constructor
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data)
{
    struct Node* newNode = createNode(data); // Creates a new Node
    if(*head == NULL)
    {
        // If address of head is NULL
        // put newNode as head
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next != NULL)
    {
        // Iterate through all the nodes until end
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtHead(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

int dataExists(struct Node* head, int value)
{
    struct Node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == value)
        {
            printf("Data Exists\n");
            return 1;
        }

        temp = temp->next;
    }
    printf("Data does not exist\n");
    return 0;
}


void printList(struct Node* head)
{
    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    insertAtHead(&head, 4);

    dataExists(head, 5);

    printList(head);

    return 0;
}
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

int listLength(struct Node* head)
{
    int length = 0;
    struct Node* temp = head;
    while(temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    return length;
}

void deleteFromFirst(struct Node** head)
{
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

void deleteFromEnd(struct Node** head)
{
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;
    if(temp->next == NULL)
    {
        free(temp);
        *head = NULL;
        return;
    }

    while(temp->next->next != NULL)
    {
        // Check for the next node of the next node
        temp = temp->next;
    }
    free(temp->next); // This points to the next node which is to be deleted
    temp->next = NULL;
}

void deleteAtPosition(struct Node** head, int position)
{
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if(position == 0)
    {
        deleteFromFirst(head);
        return;
    }

    struct Node* temp = *head;
    for(int i=0; temp != NULL && i<position-1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
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

    deleteAtPosition(&head, 2);

    dataExists(head, 2);

    printList(head);

    return 0;
}
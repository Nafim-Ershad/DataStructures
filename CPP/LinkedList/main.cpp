// Linked List
// video-source: https://www.youtube.com/watch?v=Crqgl10aIGQ

#include <iostream>

class Node // Node class
{
    public:
        int data;   // Data
        Node* next; // Pointer to next node. Holds the address of the next node

    Node(int data) // Constructor
    { 
        this->data = data;  // Set data
        this->next = nullptr;   // Set next to nullptr
    }
};

void insertAtHead(Node* &head, int data) // Insert at head
{
    Node* n = new Node(data);   // Create new node
    n->next = head; // Set n next to head
    head = n;   // Set head to n
}

void insertAtTail(Node* &head, int data) // Insert data at tail
{
    Node* n = new Node(data);   // Create new node
    if(head == nullptr) // If head is nullptr
    {
        head = n;   // Set head to n
        return; // Return
    }
    Node* temp = head;  // Create temp node
    while(temp->next != nullptr)    // While temp next is not nullptr
    {
        temp = temp->next;  // Set temp to temp next
    }
    temp->next = n; // Set temp next to n
} 

void search(Node* head, int key) // Search
{
    Node* temp = head;  // Create temp node
    while(temp != nullptr)  // While temp is not nullptr
    {
        if(temp->data == key)   // If temp data is equal to key
        {
            std::cout << "Found " << key << std::endl;    // Output found
            return; // Return
        }
        temp = temp->next;  // Set temp to temp next
    }
    std::cout << key << " is not found" << std::endl;    // Output not found
}

void display(Node* head) // Display
{
    Node* temp = head;  // Create temp node
    while(temp != nullptr)  // While temp is not nullptr
    {
        std::cout << temp->data << " -> ";  // Output data
        temp = temp->next;  // Set temp to temp next
    }
    std::cout << "NULL" << std::endl;    // Output NULL
}

int main(){

    Node* head = nullptr;   // Create head node
    insertAtTail(head, 1);  // Insert at tail
    insertAtTail(head, 2);  // Insert at tail
    insertAtTail(head, 3);  // Insert at tail

    insertAtHead(head, 4);  // Insert at head

    display(head);

    search(head, 5);   // Search

    return 0;
}
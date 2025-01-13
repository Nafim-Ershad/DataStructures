#include <iostream>

class Node
{
    public:
        int data;
        Node* next;

        Node(int data)
        {
            this->data = data;
            this->next = nullptr;
        } 
};

void insertAtTail(Node* &head, int data)
{
    Node* newNode = new Node(data);

    if(head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insterAtHead(Node* &head, int data)
{
    Node* newNode = new Node(data);
    if(head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    newNode->next = temp;
    head = newNode;

    return;    
}

void display(Node* head)
{
    Node* temp = head;
    while(temp != nullptr)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}

class Stack
{
    int* arr;
    int top;
    int capacity;

    private:
        void resize()
        {
            int* newArray = new int[2 * capacity];
            for(int i = 0; i < capacity; i++)
            {
                newArray[i] = arr[i];
            }
            delete[] arr;
            arr = newArray;
            capacity *= 2;
        }

    public:
        Stack()
        {
            capacity = 1;
            arr = new int[capacity];
            top = -1;
        }

        void push(int x)
        {
            if(top == capacity - 1)
            {
                resize();
            }
            arr[++top] = x;
            return;
        }

        void view()
        {
            for(int i = 0; i <= top; i++)
            {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
};

int main()
{
    Node* head = nullptr;
    Stack stack = Stack();
    Stack stack2 = Stack();

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);

    insterAtHead(head, 4);

    display(head);

    stack.push(1);
    stack.push(1);
    stack.push(2);

    stack.view();

    stack2.push(1);
    stack2.push(2);
    stack2.push(3);

    stack2.view();

    return 0;
}
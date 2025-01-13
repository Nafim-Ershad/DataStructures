#include <iostream>

#define MAX_LENGTH 100

class Queue
{
    int front;
    int rear;
    int* arr;

private:
    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    bool isFull()
    {
        return (rear + 1) % MAX_LENGTH == front;
    }

public:
    /* A first in first out approach FIFO */
    Queue()
    {
        front = -1;
        rear = -1;
        arr = new int[MAX_LENGTH];
    }

    int deque()
    {
        if(isEmpty())
        {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        else if(front == rear)
        {
            int x = arr[front];
            front = rear = -1;
            return x;
        }
        else
        {
            int x = arr[front];
            front = (front + 1) % MAX_LENGTH;
            return x;
        }
    }

    void enque(int x)
    {
        if(isFull())
        {
            std::cout << "Queue is full" << std::endl;
            return;
        }
        else if(isEmpty())
        {
            front = rear = 0;
            arr[rear] = x;
        }
        else
        {
            rear = (rear + 1) % MAX_LENGTH;
            arr[rear] = x;
        }
    }

    void display()
    {
        if(isEmpty())
        {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        else
        {
            int i = front;
            while(i != rear)
            {
                std::cout << arr[i] << " -> ";
                i = (i + 1) % MAX_LENGTH;
            }
            std::cout << arr[rear] << std::endl;
        }
    }

    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{
    Queue q;
    q.enque(1);
    q.enque(2);
    q.enque(3);

    q.display();

    q.deque();
    q.display();   

    return 0;
}
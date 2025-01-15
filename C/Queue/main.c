#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

struct Queue
{
    int front;
    int rear;
    int* arr;
};

struct Queue createQueue()
{
    // Acts as a constructor
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    q->arr = (int*)malloc(MAX_LENGTH * sizeof(int));

    return *q;
}

int isEmpty(struct Queue* q)
{
    if(q->front == -1 && q->rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};

int isFull(struct Queue* q)
{
    if(q->rear == MAX_LENGTH - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enque(struct Queue* q, int x)
{
    // Pushesh data at the end
    if(isFull(q))
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        if(isEmpty(q))
        {
            // Indicate if the queue is empty
            q->front = q->rear = 0;
            q->arr[q->rear] = x;
            return;
        }
        else
        {
            q->rear++;
            q->arr[q->rear] = x;
            return;
        }
    }
}

void deque(struct Queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    else if(q->front == q->rear)
    {
        int x = q->arr[q->front];
        q->front = q->rear = -1;
        printf("%d\n", x);
    }
    else
    {
        int x = q->arr[q->front];
        q->front++;
        printf("%d\n", x);
    }
}

void display(struct Queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        int i = q->front;
        while(i != q->rear)
        {
            printf("%d -> ", q->arr[i]);
            i++;
        }
        printf("%d\n", q->arr[q->rear]);
    }
}

int main()
{
    struct Queue q = createQueue();

    enque(&q, 1);
    enque(&q, 2);

    enque(&q, 3);
    enque(&q, 4);

    display(&q);

    deque(&q);

    display(&q);

    return 0;
}
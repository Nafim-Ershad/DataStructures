#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

struct Stack
{
    int top;
    int* arr;
};

struct Stack createStack()
{
    // ACts as a constructor
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));

    s->top = -1; // Indicates empty
    s->arr = (int*)malloc(MAX_LENGTH * sizeof(int));

    return *s;
}

void push(struct Stack* s, int x)
{
    if(s->top == MAX_LENGTH - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    s->arr[++s->top] = x;
}

int pop(struct Stack* s)
{
    if(s->top == -1)
    {
        printf("Stack Empty\n");
        return -1;
    }

    int x = s->arr[s->top];

    free(&s->arr[s->top]); // Frees up the space occupied by the element
    s->arr[s->top--]; // operation is done after the subtraction of top

    return x;
}

void display(struct Stack* s)
{
    if(s->top == -1)
    {
        printf("Stack Empty\n");
        return;
    }

    for(int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}


int main()
{
    struct Stack s = createStack();

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    display(&s);

    printf("Popped: %d\n", pop(&s));

    display(&s);
    push(&s, 40);
    push(&s, 50);

    display(&s);

    return 0;
}
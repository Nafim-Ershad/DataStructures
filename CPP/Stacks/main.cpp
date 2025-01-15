#include <iostream>

#define N 100

class Stack
{
    int* arr;
    int top_el;
    public:
        Stack() // Constructor
        {
            arr = new int[N];
            top_el = -1;
        }

        void push(int x)
        {
            if(top_el == N-1)
            {
                std::cout << "Stack Overflow" << std::endl;
                return;
            }
            top_el++;
            arr[top_el] = x;
        }

        void pop()
        {
            if(top_el == -1)
            {
                std::cout << "No element to pop" << std::endl;
                return;
            }
            top_el--;
        }

        int top()
        {
            if(top_el == -1)
            {
                std::cout << "No element in stack" << std::endl;
                return -1;
            }
            return arr[top_el];
        }

        void empty()
        {
            if(top_el == -1)
            {
                std::cout << "Stack is empty" << std::endl;
            }
            else
            {
                std::cout << "Stack is not empty" << std::endl;
            }
        }

        void display()
        {
            for(int i = 0; i <= top_el; i++)
            {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
        
};

int main()
{
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);


    stack.display();

    std::cout << stack.top() << std::endl;
    stack.pop();

    stack.display();

    std::cout << stack.top() << std::endl;

    stack.empty();

    stack.display();
}
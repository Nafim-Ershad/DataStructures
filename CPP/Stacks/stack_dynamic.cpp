#include <iostream>

class Stack
{
    int* arr;
    int top_el;
    int capacity;

    private:
        void resize()
        {
            int* new_arr = new int[2*capacity];
            for(int i = 0; i < capacity; i++)
            {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
            capacity *= 2;
        }

    public:
        Stack()
        {   
            capacity = 1;
            arr = new int[capacity];
            top_el = -1;
        }

        void push(int x)
        {
            if(top_el == capacity - 1)
            {
                resize();
            }

            top_el++;
            arr[top_el] = x;
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
    stack.push(4);

    stack.display();

    return 0;
}
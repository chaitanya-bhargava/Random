#include <iostream>

using namespace std;

class Stack
{
private:
    int arr[5];
    int top;

public:
    bool isempty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isfull()
    {
        if (top == 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int x)
    {
        if (isfull())
        {
            cout << "stack overflow\n";
        }
        else
        {
            top = top + 1;
            arr[top] = x;
        }
    }

    int pop()
    {
        if (isempty())
        {
            cout << "stack underflow\n";
            return 0;
        }
        else
        {

            int temp = arr[top];
            top = top - 1;
            return temp;
        }
    }

    void peek()
    {
        if (isempty())
        {
            cout << "stack underflow\n";
        }
        else
        {
            cout << arr[top] << endl;
        }
    }

    Stack()
    {
        top = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }
};

int main()
{
    Stack S1;
    S1.push(5);
    S1.push(6);
    S1.push(7);
    S1.push(69);
    S1.push(9);
    S1.push(8);
    S1.push(8);
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.peek();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    return 0;
}
#include <iostream>
using namespace std;

#define MAX_SIZE 1000

class Stack
{
    int arr[MAX_SIZE];
    int top;

public:
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    int size();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if (top >= (MAX_SIZE - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        arr[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = arr[top--];
        return x;
    }
}

int Stack::peek()
{
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = arr[top];
        return x;
    }
}

int Stack::size()
{
    return top + 1;
}

bool Stack::isEmpty()
{
    return (top < 0);
}

/* int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";

    return 0;
} */
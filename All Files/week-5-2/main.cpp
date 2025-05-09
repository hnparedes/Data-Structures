#include <iostream>
using namespace std;

#define MAX 100

class Stack
{
    
    // Index of the top element in the stack.
    int top;
    public:
    
        // Array to store the stack elements.
        int a[MAX];
        Stack()
        {
            
            top = -1;
            
        }
        
        // Function to push an element onto the stack.
        bool push(int item);
        
        // Function to pop an element from the stack.
        int pop();
        
        // Function to view the top element of the stack without removing it.
        int peek();
        
        // Function to check if the stack is empty.
        bool isEmpty();
    
};

bool Stack::push(int item)
{
    
    // Check for stack overflow (stack is full).
    if(top >= (MAX-1))
    {
        
        cout << "Stack Overflow";
        return false;
        
    }
    else
    {
        
        // Increment the top index.
        top++;
        
        // Store the item at the new top position.
        a[top] = item;
        cout << item << " is successfully pushed.\n";
        return true;
        
    }
    
}

int Stack::pop()
{
    
    // Check for stack underflow (stack is empty).
    if(top < 0)
    {
        
        cout << "Stack Underflow";
        return 0;
        
    }
    else
    {
        
        // Retrieve the value at the top of the stack.
        int x = a[top];
        
        // Decrement the top index.
        top--;
        
        // Return the popped value.
        return x;
        
    }
    
}

int Stack::peek()
{
    
    // Check if the stack is empty.
    if(top < 0)
    {
        
        cout << "Stack is Empty";
        return 0;
        
    }
    else
    {
        
        // Return the value at the top of the stack without removing it.
        return a[top];
        
    }
    
}

// Return true if the stack is empty
bool Stack::isEmpty()
{
    
    return (top < 0);
    
}

int main()
{
    
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " is successfully popped the item\n";
    cout << "The elements in the STACK: ";
    while(!s.isEmpty())
    {
        
        cout << s.pop() << " ";
        
    }
    
    return 0;
    
}
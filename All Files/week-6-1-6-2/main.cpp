#include <stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;
#define MAX 100

//A stack node
class Stack
{
    
    public:
    
        // Index of the top element in the stack.
        int top;
        
        // Array to store characters, representing an expression (or other character sequence).
        char exp[MAX];
        
        // Constructor: Initializes the stack as empty (top = -1).
        Stack() {top = -1;}
        
        // functions prototypes
        bool push(char item);
        char pop();
    
};

bool Stack::push(char item)
{
    
    // Check for stack overflow (stack is full).
    if(top >= (MAX-1))
    {
        
        cout << "Stack Overflow";
        
        // Return false to indicate push failure.
        return false;
        
    }
    else
    {
        
        // Increment top index.
        top++;
        
        // Store the character at the new top position.
        exp[top] = item;
        
        // Return true to indicate push success.
        return true;
        
    }
    
}

char Stack::pop()
{
    
    // Check for stack underflow (stack is empty).
    if(top == -1)
    {
        
        cout << "Stack Underflow";
        return 0;
        
    }
    else
    {
        
        // Retrieve the character at the top.
        char x = exp[top];
        
        // Decrement top index.
        top--;
        
        // Return the popped character.
        return x;
        
    }
    
}

// Returns 1 if character1 and character2 are matching left
// and right brackets
int isMatchingPair(char character1, char character2)
{
    
    if(character1 == '(' && character2 == ')')
    {
        
        return 1;
        
    }
    else if(character1 == '{' && character2 == '}')
    {
        
        return 1;
        
    }
    else if(character1 == '[' && character2 == ']')
    {
        
        return 1;
        
    }
    else
    {
        
        return 0;
        
    }
    
}

// Return 1 if expression has balanced brackets
int areParenthesisBalanced(char exp[])
{
    
    int i = 0;
    
    // Declare an empty character Stack
    Stack* s = new Stack();
    
    // Traverse the given expression to check matching
    // brackets
    while(exp[i])
    {
        
        if(exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
        {
            
            s->push(exp[i]);
            
        }
        if(exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
        {
            
            if(s->top == -1)
            {
                
                return 0;
                
            }
            else if(!isMatchingPair(s->pop(), exp[i]))
            {
                
                return 0;
                
            }
            
        }
        
        i++;
        
    }
    
    if(s->top == -1)
    {
        
        return 1;
        
    }
    else
    {
        
        return 1;
        
    }
    
}

int main()
{
    
    char exp[100];
    cout << "enter the expression:\n";
    cin >> exp;
    
        // Function call
        if(areParenthesisBalanced(exp))
        {
            
            cout << "Balanced";
            
        }
        else
        {
            
            cout << "Not Balanced";
            
        }
    
    return 0;
    
}
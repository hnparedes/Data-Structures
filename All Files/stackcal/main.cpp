#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <cstring>

// Defines the maximum size of the stack
#define MAX_SIZE 100

using namespace std;

// Stack class for handling operators and parentheses
class Stack 
{
    // Array to store characters
    char arr[MAX_SIZE];
    // Top index of the stack
    int top;
    
    public:
        // Constructor initializes stack as empty
        Stack() { top = -1; }
        // Checks if stack is empty
        bool isEmpty() { return top == -1; }
        // Checks if stack is full
        bool isFull() { return top == MAX_SIZE - 1; }
        // Pushes a character onto the stack
        void push(char c) 
        { 
            if(!isFull())
            {
                arr[++top] = c;
            }
        }
        
        // Pops a character from the stack
        char pop() { return isEmpty() ? ' ' : arr[top--]; }
        // Returns the top element without popping
        char peek() { return isEmpty() ? ' ' : arr[top]; }
};

// Stack for evaluating postfix expressions (stores numbers)
class EvalStack 
{
    // Array to store numerical values
    double arr[MAX_SIZE];
    // Top index of the stack
    int top;
    
    public:
        // Constructor initializes stack as empty
        EvalStack() { top = -1; }
        // Checks if stack is empty
        bool isEmpty() { return top == -1; }
        // Checks if stack is full
        bool isFull() { return top == MAX_SIZE - 1; }
        // Pushes a numeric value onto the stack
        void push(double val) 
        { 
            if(!isFull())
            {
                arr[++top] = val; 
            }
        }
        
        // Pops a numeric value from the stack
        double pop() { return isEmpty() ? 0 : arr[top--]; }
};

// Determines precedence of operators
int precedence(char op) 
{
    switch(op) 
    {
        case '+': case '-': return 1;
        case '*': case '/': case '%': return 2;
        case '^': return 3;
        default: return 0;
    }
}

// Checks if a character is an operator
bool isOperator(char c) 
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

// Checks if a character is a parenthesis
bool isParenthesis(char c) 
{
    return c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']';
}

// Verifies matching pairs of parentheses
bool matchingParenthesis(char open, char close) 
{
    return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}

// Checks if parentheses are balanced in an expression
bool balancedParentheses(const string &exp) 
{
    Stack stack;
    for(char c : exp) 
    {
        if(c == '(' || c == '{' || c == '[')
        {
            stack.push(c);
        }
        else if(c == ')' || c == '}' || c == ']') 
        {
            if(stack.isEmpty() || !matchingParenthesis(stack.pop(), c))
            {
                return false;
            }
        }
    }
    
    // If stack is empty, parentheses are balanced
    return stack.isEmpty();
}

// Validates the expression for correct operand-operator ratio
bool isValidExpression(string expr) 
{
    int operands = 0, operators = 0;
    for(size_t i = 0; i < expr.length(); i++) 
    {
        char c = expr[i];
        if(isdigit(c)) 
        {
            operands++;
            while(i + 1 < expr.length() && isdigit(expr[i + 1]))
            {
                // Skip additional digits in a multi-digit number
                i++;
            }
        } 
        else if(isOperator(c)) 
        {
            operators++;
        } 
        else if(!isParenthesis(c) && !isspace(c)) 
        {
            cout << "Error: Invalid character '" << c << "' in expression" << endl;
            exit(1);
        }
    }
    // Ensure valid operand-operator ratio
    if(operands <= operators) 
    {
        cout << "Error: invalid number of operands" << endl;
        exit(2);
    }
    if(operators == 0 && operands > 1) 
    {
        cout << "Error: invalid number of operators" << endl;
        exit(3);
    }
    
    return true;
}

// Converts an infix expression to postfix notation
string infixToPostfix(string infix) 
{
    Stack stack;
    string postfix = "";
    for(size_t i = 0; i < infix.length(); i++) 
    {
        char c = infix[i];
        if(isdigit(c))
        {
            postfix += c;
            while(i + 1 < infix.length() && isdigit(infix[i + 1]))
            {
                // Append multi-digit numbers
                postfix += infix[++i];
            }
            postfix += ' ';
        } 
        else if(c == '(' || c == '{' || c == '[') 
        {
            stack.push('(');
        } 
        else if(c == ')' || c == '}' || c == ']') 
        {
            while(!stack.isEmpty() && stack.peek() != '(')
            {
                postfix += stack.pop();
                postfix += ' ';
            }
            // Remove the opening parenthesis
            stack.pop();
        } 
        else if(isOperator(c)) 
        {
            while(!stack.isEmpty() && precedence(stack.peek()) >= precedence(c))
            {
                postfix += stack.pop(); 
                postfix += ' ';
            }
            stack.push(c);
        }
    }
    
    while(!stack.isEmpty())
    {
        postfix += stack.pop();
    }
    return postfix;
}

// Removes spaces from the postfix expression
string PostfixToOutput(string postfix)
{
    
    string output = "";
    for(int i = 0; i < postfix.length(); i++)
    {
        
        if(postfix[i] != ' ')
        {
            
            output += postfix[i];
            
        }
        
    }
    
    return output;
    
}

// Evaluates a postfix expression
double evaluatePostfix(string postfix) 
{
    EvalStack stack;
    for(size_t i = 0; i < postfix.length(); i++) 
    {
        char c = postfix[i];
        if(isdigit(c)) 
        {
            double num = 0;
            while(isdigit(postfix[i]))
            {
                // Convert string to number
                num = num * 10 + (postfix[i++] - '0');
            }
            stack.push(num);
        } 
        else if(isOperator(c)) 
        {
            double b = stack.pop(), a = stack.pop(), res = 0;
            switch(c) 
            {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
                case '%': res = fmod(a, b); break;
                case '^': res = pow(a, b); break;
            }
            stack.push(res);
        }
    }
    
    return stack.pop();
}

int main() 
{
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    if (!isValidExpression(infix) || !balancedParentheses(infix)) 
    {
        
        cout << "Error: Invalid parentheses" << endl;
        return 1;
        
    }
    
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << PostfixToOutput(postfix) << endl;
    double result = evaluatePostfix(postfix);
    cout << fixed << setprecision(3) << "Result: " << result << endl;
    
    return 0;
}
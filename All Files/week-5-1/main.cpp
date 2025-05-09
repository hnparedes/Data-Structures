#include <iostream>
using namespace std;

struct Node {
    
    // Stores the integer data of the node.
    int data;
    
    // Pointer to the next node in the linked list.
    Node* next;
    
    // Constructor for the Node struct.
    Node(int d)
    {
        
        // Initializes the 'data' member with the provided value 'd'.
        data = d;
        
        // Initializes the 'next' pointer to NULL, indicating the node is currently the last node.
        next = NULL;
        
    }
    
    
};

struct Queue {
    
    Node *front, *rear;
    
    // Constructor to initialize an empty queue
    Queue()
    {
        
        front = rear = NULL;
        
    }
    
    // Enqueue: adds an element to the rear of the Queue
    void enQueue(int x)
    {
    
        Node* newNode = new Node(x);
    
        // If queue is empty, then new node is both front and rear.
        if (rear == NULL)
        {
        
            front = rear = newNode;
            return;
        
        }
    
        // Attach new node at the end of queue and update rear.
        rear->next = newNode;
        rear = newNode;
    
    }
    
};

// Function to print the elements of a linked list.
void printList(Node* node)
{
    
    while(node != NULL)
    {
        
        cout << "" << node->data << "->";
        node = node->next;
        
    }
    
    cout << "NULL\n";
    
}

int main()
{
    
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    
    Node* current = q.front;
    
    printList(current);

    return 0;
}
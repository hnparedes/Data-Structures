#include <iostream>
using namespace std;

// A linked list node
class Node 
{
    
    public:
        int data;
        Node *next;
        
    
};

// This function inserts a new node at the beginning of a linked list.
// It takes a pointer to the head of the list (headref) and the new data as input.
void insertBeg(Node** headref, int new_data)
{
    // 1. allocate node
    Node* new_node = new Node();
    // 2. put in the data
    new_node->data = new_data;
    // 3. Make next of new node as head
    new_node->next = *headref;
    // 4. move the head to point to the new node
    *headref = new_node;
    
}

// This function prints contents of linked list starting from head
void printList(Node *node)
{
    
    while(node != NULL)
    {
        
        cout << "" << node->data;
        // node = node->next;
    }
    
}

int main() 
{
  
    // Start with the empty list
    Node *head = NULL;
    // Insert 6. So linked list becomes 6->NULL
    // insertLast(&head, 6);
    
    // Insert 7 at the beginning.
    // So linked list becomes 7->6->NULL
    insertBeg(&head, 7);
    
    // Insert 1 at the beginning.
    // So linked list becomes 1->7->6->NULL
    // insertBeg(&head, 1);
    
    // Insert 4 at the end. So
    // linked list becomes 1->7->6->4->NULL
    // insertLast(&head, 4);
    
    // cout<< "Created Linked list is: ";
    printList(head);
    
    return 0;
  
}


#include <iostream>
using namespace std;
// A linked list node
class Node
{
    
    public:
        int data;
        Node *next;
        Node* prev;
        
};

// Inserts a new node at the beginning of a doubly linked list.
// Takes a pointer to the head of the list (headRef) and the new data (newData).
void insertBeg(Node** headRef, int newData)
{
    
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = (*headRef);
    newNode->prev = NULL;
    if (*headRef != NULL)
    {
        
        (*headRef)->prev = newNode;
        
    }
    *headRef = newNode;
    
}

// Inserts a new node after a given previous node in a doubly linked list.
// Takes a pointer to the previous node (prevNode) and the new data (newData).
void insertAfter(Node* prevNode, int newData)
{
    if (prevNode == NULL)
    {
        cout << "The given previous node cannot be NULL";
        return;
    }
    
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Inserts a new node at the end of a singly linked list.
// Takes a pointer to the head of the list (headRef) and the new data (newData).
void insertLast(Node** headRef, int newData)
{
    Node* newNode = new Node();
    Node* last = *headRef;
    newNode->data = newData;
    newNode->next = NULL;
    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    
    last->next = newNode;
    return;
}

// Function to delete a node with a given key
void deleteNode(Node** headRef, int key)
{
    // Store the head node
    Node* temp = *headRef;
    Node* prev = NULL;
    // Case 1: If head node itself holds the key
    if (temp != NULL && temp->data == key)
    {
        *headRef = temp->next; // Change head
        delete temp; // Free memory
        return;
    }
    // Case 2: Search for the key to be deleted
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    // If key was not present in the list
    if (temp == NULL)
    {
        cout << "Key " << key << " not found in the list." << endl;
        return;
    }
    // Case 3: Unlink the node from the linked list
    prev->next = temp->next;
    delete temp; // Free memory
}

// This function prints contents of the linked list
void printList(Node* node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
    cout << endl;
}

int main()
{
    Node* head = NULL;
    int num1;
    int num2;
    int num3;
    
    cout << "Insert Element 3: " << endl;
    cin >> num1;
    
    cout << "Insert Element 2: " << endl;
    cin >> num2;
    
    cout << "Insert Element 1: " << endl;
    cin >> num3;
    
    // insertBeg(&head, 7);
    // insertBeg(&head, 1);
    
    insertBeg(&head, num1);
    insertBeg(&head, num2);
    insertBeg(&head, num3);
    
    cout << "Created Linked List: ";
    printList(head);
    
    // Deleting a node with value 7
    cout << "Deleting node with key 7." << endl;
    deleteNode(&head, 7);
    cout << "Updated Linked List: ";
    printList(head);
    
    // Deleting a node with value 10 (not in list)
    cout << "Deleting node with key 10." << endl;
    deleteNode(&head, 10);
    cout << "Updated Linked List: ";
    printList(head);
    
    // Deleting the head node
    cout << "Deleting head node with key 1." << endl;
    deleteNode(&head, 1);
    cout << "Updated Linked List: ";
    printList(head);
    
    return 0;
}
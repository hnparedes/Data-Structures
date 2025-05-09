#include <iostream>
using namespace std;

class Node 
{
    
    int data;
    Node * left, * right;
    
    public:
        // Default constructor.
        Node();
        
    // Parameterized constructor.
    Node(int);
    
    // Insert function.
    Node * Insert(Node * , int);
    
    // Inorder traversal.
    void Inorder(Node * );
    
};

// Default Constructor definition.
Node::Node() 
{
    
    data = 0;
    left = right = NULL;
    
}

// Parameterized Constructor definition.
Node::Node(int value) 
{
    
    data = value;
    left = right = NULL;
    
}

// Insert function definition.
Node * Node::Insert(Node * root, int value) 
{
    if (!root) 
    {
        // Insert the first node, if root is NULL.
        return new Node(value);
    }
    
    // Insert data.
    if (value > root -> data) 
    {
    // Insert right node data, if the 'value'
    // to be inserted is greater than 'root' node data.
    // Process right nodes.
        root -> right = Insert(root -> right, value);
    } 
    else 
    {
    // Insert left node data, if the 'value'
    // to be inserted is greater than 'root' node data.
    // Process left nodes.
        root -> left = Insert(root -> left, value);
    }
    
    // Return 'root' node, after insertion.
    return root;
}

// Inorder traversal function
// This gives data in sorted order
void Node::Inorder(Node * root)
{
    
    if(root == NULL)
        return;
    Inorder(root -> left);
    cout << root -> data << " ";
    Inorder(root -> right);
    
}

int main()
{
    
    Node* root = new Node();
    root = NULL;
    
    root = root -> Insert(root, 50);
    root -> Insert(root, 30);
    root -> Insert(root, 20);
    root -> Insert(root, 40);
    root -> Insert(root, 70);
    root -> Insert(root, 60);
    root -> Insert(root, 80);
    
    root->Inorder(root);
    cout << endl;

    root->Insert(root, 25); // Add 25

    cout << "After insertion: " << endl;
    root->Inorder(root);
    cout << endl;
    
    return 0;
}
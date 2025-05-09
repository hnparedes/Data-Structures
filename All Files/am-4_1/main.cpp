// Hugo Paredes
// Data Structures COP3415 S02
// 4/20/25 2:42 PM
#include <iostream>
using namespace std;

// AVL tree node
struct Node {
    int value;
    Node *left, *right;
    int height;
};

// Get the height of the tree
int height(Node *N) 
{
    if(N == nullptr)
    {
        
        return 0;
        
    }
    
    return N->height;
}

// Get the balance factor of the node
int getBalance(Node *N) 
{
    if(N == nullptr)
    {
        
        return 0;
        
    }
    
    return height(N->left) - height(N->right);
}

// Right rotate the subtree rooted with y
Node *rightRotate(Node *y) 
{
    Node *x = y->left;
    Node *T2 = x->right;
    
    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Left rotate the subtree rooted with x
Node *leftRotate(Node *x) 
{
    Node *y = x->right;
    Node *T2 = y->left;
    
    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Insert a node into the AVL tree
Node* insert(Node* node, int value) 
{
    /* 1. Perform the normal BST insertion */
    if (node == nullptr)
    {
        
        return (new Node{value, nullptr, nullptr, 1});
        
    }

    if (value < node->value)
    {
        
        node->left = insert(node->left, value);
        
    }
    else if (value > node->value)
    {
        
        node->right = insert(node->right, value);
        
    }
    else // Equal keys are not allowed in BST
    {
        
        return node;
        
    }

    /* 2. Update height of the current node */
    node->height = 1 + max(height(node->left), height(node->right));

    /* 3. Get the balance factor of this node (to check whether this node became unbalanced) */
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && value < node->left->value)
    {
        
        return rightRotate(node);
        
    }

    // Right Right Case
    if (balance < -1 && value > node->right->value)
    {   
        
        return leftRotate(node);
        
    }

    // Left Right Case
    if (balance > 1 && value > node->left->value) 
    {
        
        node->left = leftRotate(node->left);
        return rightRotate(node);
        
    }

    // Right Left Case
    if (balance < -1 && value < node->right->value) 
    {
        
        node->right = rightRotate(node->right);
        return leftRotate(node);
        
    }

    /* return the (unchanged) node pointer */
    return node;
}

// Function to count nodes greater than a given value
int countGreaterNodes(Node *node, int value) 
{
    if (node == nullptr) 
    {
        
        return 0;
        
    }

    int count = 0;
    if (node->value > value) 
    {
        
        count++;
        count += countGreaterNodes(node->right, value);
        count += countGreaterNodes(node->left, value);
        
    } 
    else 
    {
        
        count += countGreaterNodes(node->right, value);
        
    }
    
    return count;
}

int main() 
{
    Node *root1 = nullptr;

    // Construct AVL tree for Sample Test Case 1
    root1 = insert(root1, 10);
    root1 = insert(root1, 20);
    root1 = insert(root1, 5);
    root1 = insert(root1, 15);
    root1 = insert(root1, 30);

    // Count nodes greater than 15
    int key1 = 15;
    cout << "Number of nodes greater than "<< key1 << ":" << countGreaterNodes(root1, 15) << endl;
    
    // Construct AVL tree for Sample Test Case 2
    Node *root2 = nullptr;
    root2 = insert(root2, 25);
    root2 = insert(root2, 15);
    root2 = insert(root2, 35);
    root2 = insert(root2, 10);
    root2 = insert(root2, 20);
    root2 = insert(root2, 30);
    root2 = insert(root2, 40);

    // Count nodes greater than 15
    int key2 = 15;
    cout << "Number of nodes greater than " << key2 << ":" << countGreaterNodes(root2, 15) << endl;

    return 0;
}

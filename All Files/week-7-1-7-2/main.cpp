#include <iostream>
#include <stdio.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node 
{
    
    int data;
    struct Node *left, *right; 
    
};

// Utility function to create a new tree node
Node* newNode(int data)
{
    
    Node*temp = new Node;
    temp->data = data;
    temp-> left = temp->right = NULL;
    return temp;
    
}

void printPostorder(struct Node* node)
{
    
    if(node == NULL)
    {
        
        return;
        
    }
    
    // first recur on left subtree
    printPostorder(node->left);
    
    // then recur on right subtree
    printPostorder(node->right);
    
    // now deal with the node-
    cout << node->data << " ";
    
}

int main()
{
    
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    printPostorder(root);

    return 0;
    
}
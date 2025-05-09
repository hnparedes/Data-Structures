#ifndef BST_H
#define BST_H

#include "BTNode.h"
#include <string>
#include <vector>

template <typename T>
class BST {
public:
    BST();

    ~BST();
    
    BST(const BST<T>& other);
    bool find_target(const T& val) const;
    int get_height() const;


    bool empty() const;

    void insert(const T& val);

    void preorder() const;
    void inorder() const;
    void postorder() const;

    void print() const;

    const T& get_min() const; //returns the minimum value in BST

    BTNode<T>* search(const T& val);
    BTNode<T>* search_parent(const T& val);

    void delete_node(const T& val);

private:
    BTNode<T>* root;
    void preorder(BTNode<T>* node) const;
    void inorder(BTNode<T>* node) const;
    void postorder(BTNode<T>* node) const;

    void print(const std::string& prefix, const BTNode<T>* node, bool isRight) const;

    void delete_leaf(BTNode<T>* child, BTNode<T>* parent);
    void delete_one_child(BTNode<T>* child, BTNode<T>* parent);
    void delete_two_children(BTNode<T>* node);

    const T& get_min(BTNode<T>* node) const;
    
    // START ASSIGNMENT 4 FUNCTIONS TO IMPLEMENT
    
    void destroyTree(BTNode<T>* node);
    void copyTree(BTNode<T>* otherNode, BTNode<T>*& newNode);
    void inorderTraversal(BTNode<T>* node, std::vector<T>& arr, const T& target) const;
    int getHeightHelper(BTNode<T>* node) const;
    
    // END ASSIGNMENT 4 FUNCTIONS TO IMPLEMENT

};

#endif

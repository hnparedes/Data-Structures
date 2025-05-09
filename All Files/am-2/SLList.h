#ifndef SLLIST_H
#define SLLIST_H

#include "SLLNode.h"

template <typename T>
class SLList {
public:
    //no-arg constructor
    SLList();

    //destructor
    ~SLList();

    //copy constructor
    SLList(const SLList<T>& other);

    SLList<T>& operator=(const SLList<T>& other);

    //methods
    unsigned size() const; //returns the size of the list
    bool empty() const; //return true if the list is empty
    void push_front(const T& val); //insert at the beginning of the list
    void print() const; //prints the content of the list

    void push_back(const T& val); //insert at the end of the list

    void pop_front(); //removes the first element
    void pop_back(); //removes the last element



    void clear(); //removes all elements from the list

    // Inserts n elements with the given value before the element at the specified position.
    void insert(unsigned pos, const T& value, unsigned n = 1);
    
    // Removes the element at the specified position.
    void erase(unsigned pos);

    // Removes all elements from the list whose value is equal to the given value.
    void remove(const T& value); 

private:
    SLLNode<T>* head; //the first node in the linked list
    SLLNode<T>* tail; //the last node in the linked list
    unsigned listSize; //the size of the list
};

#endif

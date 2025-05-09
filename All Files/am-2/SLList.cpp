#include "SLList.h"
#include <iostream>

template <typename T>
SLList<T>::SLList() {
    head = nullptr;
    tail = nullptr;
    listSize = 0;
}

template <typename T>
SLList<T>::~SLList() {
    clear();
}

template <typename T>
SLList<T>::SLList(const SLList<T>& other) {
    head = nullptr;
    tail = nullptr;
    listSize = 0;
    SLLNode<T>* cur = other.head;
    while (cur) {
        push_back(cur->data);
        cur = cur->next;
    }
}

template <typename T>
SLList<T>& SLList<T>::operator=(const SLList<T>& other) {
    clear();
    SLLNode<T>* cur = other.head;
    while (cur) {
        push_back(cur->data);
        cur = cur->next;
    }

    return *this;
}


template <typename T>
unsigned SLList<T>::size() const {
    return listSize;
}

template <typename T>
bool SLList<T>::empty() const {
    return (listSize == 0);
}

template <typename T>
void SLList<T>::push_front(const T& val) {
    head = new SLLNode<T>(val, head);

    //increment the list size
    listSize++;

    if (listSize == 1) {
        tail = head;
    }
}

template <typename T>
void SLList<T>::push_back(const T& val) {
    if (empty()) {
        head = new SLLNode<T>(val);
        tail = head;
    }
    else {
        tail->next = new SLLNode<T>(val); //add the node to the end
        tail = tail->next; //move the tail
    }

    //increment the list size
    listSize++;
}

template <typename T>
void SLList<T>::print() const {
    std::cout << "{ ";
    SLLNode<T>* cur = head;
    while (cur) {
        std::cout << cur->data; 
        if (cur->next) {
            std::cout << " -> ";
        }
        cur = cur->next;
    }
    std::cout << " }\n";
}


template<typename T>
void SLList<T>::pop_front() {
    if (!empty()) {
        SLLNode<T>* to_delete = head;
        head = head->next;
        delete to_delete;
        listSize--;
        if (empty()) {
            tail = head;
        }
    }
}

template<typename T>
void SLList<T>::pop_back() {
    if (empty()) {
        return;
    }
    else if (size() == 1) {
        pop_front();
    }
    else {
        SLLNode<T>* to_delete = tail;
        SLLNode<T>* cur = head;
        //search second from the last node
        while(cur->next != tail) {
            cur = cur->next;
        }
        tail = cur;
        tail->next = nullptr;
        delete to_delete;
        listSize--;
    }
}


template<typename T>
void SLList<T>::clear() {
    while(!empty()) {
        pop_front();
    }
}

template<typename T>
void SLList<T>::insert(unsigned pos, const T& value, unsigned n)
{
    
    if (pos > size()) 
        {
            return; // Position out of bounds
        }

        if (pos == 0) 
        {
            
            // Insert at the beginning
            for (unsigned i = 0; i < n; ++i) 
            {
                push_front(value); 
            }
            
        } 
        else if (pos == size()) 
        {
            
            // Insert at the end
            for (unsigned i = 0; i < n; ++i) 
            {
                push_back(value);
            }
            
        } 
        else 
        {
            
            // Insert in the middle
            SLLNode<T>* current = head;
            for (unsigned i = 0; i < pos - 1; ++i) 
            {
                current = current->next;
            }

            for (unsigned i = 0; i < n; ++i) 
            {
                SLLNode<T>* newNode = new SLLNode<T>(value);
                newNode->next = current->next;
                current->next = newNode;
                listSize++;
            }
            
        }
    
}

template<typename T>
void SLList<T>::erase(unsigned pos)
{
    
    if (pos >= size()) {
        return; // Position out of bounds
    }

    if (pos == 0) {
        // Remove the first element
        pop_front();
    } else {
        // Remove an element in the middle
        SLLNode<T>* current = head;
        for (unsigned i = 0; i < pos - 1; ++i) {
            current = current->next;
        }

        SLLNode<T>* to_remove = current->next;
        current->next = to_remove->next;
        if (pos == size() - 1) {
            tail = current; // Update tail if removing the last element
        }
        delete to_remove;
        listSize--;
    }
    
}

template<typename T>
void SLList<T>::remove(const T& value)
{
    
    SLLNode<T>* current = head;
    SLLNode<T>* prev = nullptr;

    while (current) 
    {
        if (current->data == value) 
        {
            // If it's the first node
            if (prev == nullptr) 
            {
                head = current->next;
            } 
            else 
            {
                prev->next = current->next;
            }

            SLLNode<T>* temp = current;
            current = current->next;
            delete temp;
            listSize--; 
        } 
        else 
        {
            prev = current;
            current = current->next;
        }
        
    }

    // Update tail if necessary
    if (listSize > 0) 
    {
        while (prev->next) 
        {
            prev = prev->next;
        }
        tail = prev;
    } 
    else 
    {
        tail = nullptr; 
    }
    
}
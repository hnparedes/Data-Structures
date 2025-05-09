#ifndef SLLNODE_H
#define SLLNODE_H

#include <iostream>

template <typename T>
class SLLNode {
public:
    SLLNode(const T& d = 0, SLLNode* n = nullptr) {
        data = d;
        next = n;
    }

    T data;
    SLLNode* next;
};

#endif
#include "SLLNode.h"
#include "SLList.h"
#include "SLList.cpp"

#include <iostream>

int main() {
    // SLList<double> l;
    // for(int i = 1; i <= 9; i++)
    // {
    
    //     l.push_back(i + (double) i / 10);    
        
    // }
    
    // l.print();
    // l.insert(0, 0.001);
    // l.insert(0, 0.001, 5);
    // l.insert(1, 0.001, 5);
    // l.insert(9, 0.001, 5);
    // l.erase(9);
    // l.erase(0);
    // l.erase(2);
    // l.print();
    
    SLList<char> l;

    l.push_back('a');
    l.push_back('b');
    l.push_back('a');
    l.push_back('a');
    l.push_back('c');
    l.push_back('d');
    l.push_back('a');
    l.print();
    l.remove('a');
    l.print();
    
    // std::cout << "Initial list " << std::endl;
    
    // l.push_front(1.1);
    // l.push_front(2.3);

    // l.print();

    return 0;
}
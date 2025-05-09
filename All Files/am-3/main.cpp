#include "BST.h"
#include "BST.cpp"
using namespace std;

int main() {
    /*
    1.	In the main function create BST object of integers dynamically in the heap.
    2.	Insert the following values to the created tree: 42, 9, 34, 77, 66
    3.	Create a second BST object of integers dynamically in the heap using the copy constructor.
    4.	Delete the first created object.
    5.	Print the second object.
    6.	Call find_target method with the following values: 84, 43, 76, 143, 45.
    7.	Call and print the result of get_height method.
    8.	Delete the second object.
    */
    
    // 1.
    BST<int>* bst1 = new BST<int>();
    
    // 2.
    bst1->insert(42);
    bst1->insert(34);
    bst1->insert(9);
    bst1->insert(77);
    bst1->insert(66);
    
    
    // 3.
    BST<int>* bst2 = new BST<int>(*bst1);
    
    // 4.
    delete bst1;
    
    // 5.
    std::cout << "Second BST:" << std::endl;
    bst2->print();

    // 6.
    cout << "find_target(84) = " << (bst2->find_target(84) ? 1 : 0) << endl;
    cout << "find_target(43) = " << (bst2->find_target(43) ? 1 : 0) << endl;
    cout << "find_target(76) = " << (bst2->find_target(76) ? 1 : 0) << endl;
    cout << "find_target(143) = " << (bst2->find_target(143) ? 1 : 0) << endl;
    cout << "find_target(45) = " << (bst2->find_target(45) ? 1 : 0) << endl;
    
    // 7.
    cout << "Tree's height is " << bst2->get_height() << endl;
    
    // 8.
    delete bst2;
    
    return 0;
}
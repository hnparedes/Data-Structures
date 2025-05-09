#include <iostream>
#include <vector>

using namespace std;

// template for generic type
template<typename K, typename V>

// Hashnode class
class Hashnode {

public:
    V value;
    K key;

    // Constructor of Hashnode
    Hashnode(K key, V value)
    {

        this->value = value;
        this->key = key;

    }

};

// template for generic type
template <typename K, typename V>
// Our own Hashmap class
class HashMap {
private: // Added private access specifier
    // hash element array
    vector<Hashnode<K, V>*> arr; // Changed to vector for dynamic size
    int capacity;
    // current size
    int size;
    // dummy node
    Hashnode<K, V>* dummy;
public:
    HashMap()
    {
        // Initial capacity of hash array
        capacity = 7;
        size = 0;
        arr.resize(capacity, nullptr); // Initialize vector with size and null pointers

        // dummy node with value and key -1
        dummy = new Hashnode<K, V>(-1, -1);
    }

    // This implements hash function to find index
    // for a key
    int hashCode(K key)
    {
        return key % capacity;
    }

    // Function to add key value pair
    void insertNode(K key, V value)
    {
        Hashnode<K, V>* temp = new Hashnode<K, V>(key, value);

        // Apply hash function to find index for given key
        int hashIndex = hashCode(key);

        // find next free space
        while (arr[hashIndex] != nullptr
                    && arr[hashIndex]->key != key
                    && arr[hashIndex]->key != -1) {
                    hashIndex++;
                    hashIndex %= capacity;
        }

        // if new node to be inserted
        // increase the current size
        if (arr[hashIndex] == nullptr
                    || arr[hashIndex]->key == -1)
                    size++;
        arr[hashIndex] = temp;
    }

    // Function to delete a key value pair an return the value
    V deleteNode(K key)
    {
        // Apply hash function
        // to find index for given key
        int hashIndex = hashCode(key);

        // finding the node with given key
        while (arr[hashIndex] != nullptr) {
            // if node found
            if (arr[hashIndex]->key == key) {
                Hashnode<K, V>* temp = arr[hashIndex];

                // Insert dummy node here for further use
                arr[hashIndex] = dummy;

                // Reduce size
                size--;
                return temp->value;
            }
            hashIndex++;
            hashIndex %= capacity;
        }

        // If not found return (V)NULL; // Consider returning a default value or throwing an exception
        return V(); // Return default value for V
    }

    // Function to search the value for a given key
    V search(K key)
    {
        // Apply hash function to find index for given key
        int hashIndex = hashCode(key);
        int counter = 0;

        // finding the node with given key
        while (arr[hashIndex] != nullptr) {

            if (counter++ > capacity) // to avoid infinite loop
                return V(); // Return default value for V

            // if node found return its value
            if (arr[hashIndex]->key == key)
                return arr[hashIndex]->value;
            hashIndex++;
            hashIndex %= capacity;
        }

        // If not found return null
        return V(); // Return default value for V
    }

    // Return current size
    int sizeofMap()
    {
        return size;
    }

    // Return true if size is 0
    bool isEmpty()
    {
        return size == 0;
    }

    // Function to display the stored key value pairs
    void display()
    {
        for (int i = 0; i < capacity; i++) {
            if (arr[i] != nullptr && arr[i]->key != -1)
                cout << "index "<<i<<" key = " << arr[i]->key
                    << " value = "
                    << arr[i]->value << endl;
        }
    }
};

// Driver method to test map class
int main()
{
    HashMap<int, int>* h = new HashMap<int, int>;
    h->insertNode(1, 1);
    h->insertNode(2, 2);
    h->insertNode(9, 3);
    h->display();
    cout << "size of the table: "<< h->sizeofMap() << endl;
    cout <<"deleted key = "<< h->deleteNode(2) << endl;
    cout <<"size of the table: "<< h->sizeofMap() << endl;
    cout << h->isEmpty() << endl;
    cout << "Value is: "<< h->search(9) << endl;
    return 0;
}
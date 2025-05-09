#include <iostream>
using namespace std;

// A class for Min Heap
class MinHeap {
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum size of the array
    int heapSize; // total number of elements inside the array

public:
    // Constructor
    MinHeap(int capacity);

    // to heapify a tree
    void Heapify();

    // to extract the root which is the minimum element
    int extractMin();

    // Inserts a new key 'k'
    void insertKey(int k);

    // percolateUp process for the index
    void percolateUp(int index);

    // percolateDown process for the index
    void percolateDown(int index);

    int minimum(int a, int indexa, int b, int indexb);

    // Prototype of a utility function to swap two integers
    void swap(int index1, int index2);

    // Build a minHeap of an array
    MinHeap *initHeapfromArray(int *values, int length);

    // Getter for heapSize
    int getHeapSize() const { return heapSize; }
};

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap) {
    heapSize = 0;
    capacity = cap;
    harr = new int[cap + 1]; // Adjusted for 1-based indexing
}

// Inserts a new key 'k'
void MinHeap::insertKey(int k) {
    if (heapSize == capacity) {
        cout << "\nOverflow: could not insert Key\n";
        return;
    }

    // First insert the new key at the end
    heapSize++;
    int i = heapSize;
    harr[i] = k;

    // Fix the min heap property if it is violated
    percolateUp(i);
}

MinHeap *MinHeap::initHeapfromArray(int *values, int length) {

    MinHeap *h = new MinHeap(length);

    // Just copy the values into our array.
    for (int i = 1; i <= length; i++) {

        h->harr[i] = values[i - 1];

    }

    // This is the number of values we copied.
    h->heapSize = length;

    // This takes our random values and rearranges them into a heapSize
    h->Heapify();
    return h;
}

int MinHeap::minimum(int a, int indexa, int b, int indexb) {

    // Return the value associated with a
    if (a < b) {

        return indexa;

    }

    // Return the value associated with b
    else {

        return indexb;

    }

}

// Runs percolate up on the heap pointed to by h on the node stored in index.
void MinHeap::percolateUp(int index) {

    // Can only percolate up if the node isn't the root.
    if (index > 1) {

        // See if our current node is smaller in value than its parent.
        if (harr[index / 2] > harr[index]) {

            // Move our node up one level.
            swap(index, (index / 2));

            // See if it needs to be done again.
            percolateUp(index / 2);
        }
    }
}

void MinHeap::percolateDown(int index) {
    int min;
    int left = 2 * index;
    int right = 2 * index + 1;

    // Only try to percolate down internal nodes.
    if (left <= heapSize) {
        min = left;
        if (right <= heapSize && harr[right] < harr[left]) {
            min = right;
        }

        // If the smallest child is smaller than the current node
        if (harr[index] > harr[min]) {
            swap(index, min);
            percolateDown(min);
        }
    }
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin() {
    int retval;

    // We can only remove an element, if one exists in the heap!
    if (heapSize > 0) {

        // This is where the minimum is stored.
        retval = harr[1];

        // Copy the last value into this top slot.
        harr[1] = harr[heapSize];

        // Our heap will have one fewer items.
        heapSize--;

        // Need to let this value move down to its rightful spot in the heap.
        percolateDown(1);

        // Now we can return our value.
        return retval;
    }
    // No value to return, indicate failure with a -1.
    else {
        return -1;
    }
}

void MinHeap::Heapify() {
    int i;

    // We form a heap by just running percolateDown on the first half of the
    // elements, in reverse order.
    for (i = heapSize / 2; i >= 1; i--) {
        percolateDown(i);
    }
}

// A utility function to swap two elements
void MinHeap::swap(int index1, int index2) {
    int temp = harr[index1];
    harr[index1] = harr[index2];
    harr[index2] = temp;
}

void sort(int values[], int length) {
    int i;
    MinHeap *h = new MinHeap(length);

    // Create a heap from the array of values.
    h = h->initHeapfromArray(values, length);

    cout << "Sorted array: ";
    // Remove these values from the heap one by one and store them back in the
    // original array.
    for (i = 0; i < length; i++) {
        values[i] = h->extractMin();
        cout << values[i] << (i == length - 1 ? "" : ", ");
    }
    cout << endl;
    delete h;
}

int main() {
    // Example usage of the MinHeap class

    // Inserting keys
    MinHeap mh1(11);
    mh1.insertKey(3);
    mh1.insertKey(2);
    mh1.insertKey(15);
    mh1.insertKey(5);
    mh1.insertKey(4);
    mh1.insertKey(45);

    cout << "Extracted min from mh1: " << mh1.extractMin() << endl;
    cout << "Extracted min from mh1: " << mh1.extractMin() << endl;

    cout << endl;

    // Initializing heap from an array and sorting
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << (i == n - 1 ? "" : ", ");
    }
    cout << endl;

    sort(arr, n); // Sort the array using the min-heap

    cout << endl;

    // Another example of inserting and extracting
    MinHeap mh2(7);
    mh2.insertKey(8);
    mh2.insertKey(12);
    mh2.insertKey(4);
    mh2.insertKey(6);
    mh2.insertKey(32);
    mh2.insertKey(24);
    mh2.insertKey(10);

    cout << "Extracting elements from mh2 in sorted order: ";
    while (mh2.getHeapSize() > 0) { // Use the getter here
        cout << mh2.extractMin() << (mh2.getHeapSize() == 0 ? "" : ", "); // And here
    }
    cout << endl;

    return 0;
}

// Hugo Paredes
// Data Structures COP3415 S02
// 4/20/25 4:57 PM
#include <iostream>
#include <vector>
using namespace std;

const int MAX_HEAP_SIZE = 10000;

// Min heap implementation
class MinHeap 
{
    
    public:
        vector<int> heap;
    
        int parent(int i) 
        { 
            return (i - 1) / 2; 
        }
        
        int left(int i) 
        { 
            return 2 * i + 1; 
        }
        
        int right(int i) 
        { 
            return 2 * i + 2; 
        }
    
        void minHeapify(int i) 
        {
            int l = left(i);
            int r = right(i);
            int smallest = i;
            if (l < heap.size() && heap[l] < heap[smallest])
            {
                smallest = l;
            }
            if (r < heap.size() && heap[r] < heap[smallest])
            {
                smallest = r;
            }
            if (smallest != i) 
            {
                swap(heap[i], heap[smallest]);
                minHeapify(smallest);
            }
        }
    
        void insertKey(int k) 
        {
            heap.push_back(k);
            int i = heap.size() - 1;
            while (i != 0 && heap[parent(i)] > heap[i]) 
            {
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }
    
        int extractMin() 
        {
            if (heap.empty())
            {
                return -1; // Or throw an error
            }
            if (heap.size() == 1) 
            {
                int root = heap[0];
                heap.pop_back();
                return root;
            }
            int root = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            minHeapify(0);
            return root;
        }
    
        int getMin() 
        {
            if (!heap.empty())
            {
                return heap[0];
            }
            return -1; // Or throw an error
        }
    
        int size() 
        {
            return heap.size();
        }
    
};

// Function to find the kth largest element in an array
int findKthLargest(int arr[], int n, int k) 
{
    
    MinHeap minHeap;

    // Maintain a min heap of size k
    for (int i = 0; i < n; i++) 
    {
        if (minHeap.size() < k) 
        {
            minHeap.insertKey(arr[i]);
        } 
        else if (arr[i] > minHeap.getMin()) 
        {
            minHeap.extractMin();
            minHeap.insertKey(arr[i]);
        }
    }
    
    return minHeap.getMin();

}

int main() 
{
    
    int arr1[] = {3, 2, 1, 5, 6, 4};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int k = 2;

    cout << "Kth largest element: " << findKthLargest(arr1, n, k) << endl;
    
    int arr2[] = {3, 2, 3, 1, 2, 4, 5, 5, 6};

    n = sizeof(arr2) / sizeof(arr2[0]);
    k = 4;

    cout << "Kth largest element: " << findKthLargest(arr2, n, k) << endl;
    
    int arr3[] = {10, 7, 11, 5, 27, 8, 9, 45};

    n = sizeof(arr3) / sizeof(arr3[0]);
    k = 3;

    cout << "Kth largest element: " << findKthLargest(arr3, n, k) << endl;
    
    int arr4[] = {100, 200, 300, 400, 500};

    n = sizeof(arr4) / sizeof(arr4[0]);
    k = 2;

    cout << "Kth largest element: " << findKthLargest(arr4, n, k) << endl;
    
    int arr5[] = {1, 2, 3, 4, 5};

    n = sizeof(arr5) / sizeof(arr5[0]);
    k = 5;

    cout << "Kth largest element: " << findKthLargest(arr5, n, k) << endl;

    return 0;
}
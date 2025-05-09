#include <iostream>
using namespace std;

class Queue {
public:
    int front, rear, size;
    int capacity;
    int* array;
};

// Function to create a queue
Queue* createQueue(int capacity) {
    Queue* queue = new Queue();
    queue->capacity = capacity;
    queue->size = 0;
    queue->front = queue->rear = -1;
    queue->array = new int[queue->capacity];
    return queue;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Function to add an element to the queue (enqueue)
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        cout << "Queue is full. Cannot enqueue " << item << ".\n";
        return;
    }

    // Circular increment for rear
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;

    // If it's the first element, set front to 0
    if (queue->front == -1) {
        queue->front = queue->rear;
    }

    queue->size = queue->size + 1;
    cout << item << " enqueued to queue\n";
}

// Function to remove an element from the queue (dequeue)
int dequeue(Queue* queue) {

    if(isEmpty(queue))
    {
        
        cout << "Queue is empty";
        return -1;
        
    }
    
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    
    if (queue->size == 0)
    {
        
        queue->front = queue->rear = -1;
        
    }
    
    cout << item << " is dequeued from queue ";
    return item;

}

// Function to get the front element
int getFront(Queue* queue) {
    if (isEmpty(queue)) {
        cout << "Queue is empty. No front element.\n";
        return -1;
    }
    return queue->array[queue->front];
}

// Function to get the rear element
int getRear(Queue* queue) {
    if (isEmpty(queue)) {
        cout << "Queue is empty. No rear element.\n";
        return -1;
    }
    return queue->array[queue->rear];
}

// Main Function
int main() {
    Queue* queue = createQueue(5); // Create a queue with capacity 5

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    cout << "Front item: " << getFront(queue) << endl;
    cout << "Rear item: " << getRear(queue) << endl;

    cout << "Dequeued item: " << dequeue(queue) << endl;

    enqueue(queue, 50);
    enqueue(queue, 60); // Queue is now full

    cout << "Front item: " << getFront(queue) << endl;
    cout << "Rear item: " << getRear(queue) << endl;


    return 0;
}

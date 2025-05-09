
#include <iostream>
using namespace std;

class Queue {
  
  public:
    int front, rear, size;
    int capacity;
    int *array;
    
};

// Creates a new queue with the given capacity.
Queue* createQueue(int capacity) 
{
    
    // 1. Allocates memory for a new Queue object.
    Queue* queue = new Queue();
    // 2. Sets the queue's capacity to the provided value.
    queue->capacity = capacity;
    // 3. Initializes the queue's size to 0 (empty).
    queue->size = 0;
    // 4. Sets both front and rear to -1, indicating an empty queue.
    queue->front = queue->rear = -1;
    // 5. Allocates memory for the queue's array, which will store the elements.
    queue->array = new int[queue->capacity];
    // 6. Returns a pointer to the created queue.
    return queue;
    
}

// Checks if the queue is full.
// Returns true if the queue's size is equal to its capacity, false otherwise.
int isFull(Queue* queue)
{
    
    return (queue->size == queue->capacity);
    
}

// Checks if the queue is empty.
// Returns true if the queue's size is 0, false otherwise.
int isEmpty(Queue* queue)
{
    
    return (queue->size == 0);
    
}

// Enqueues an item into the queue.
void enqueue(Queue* queue, int item)
{
    
    // 1. Checks if the queue is full. If so, prints an error message and returns.
    if(isFull(queue))
    {
        
        cout << "Queue is full. Cannot enqueue " << item << ".\n";
        return;
        
    }
    
    // 2. Updates the rear index using the modulo operator to handle circular queue behavior.
    queue->rear = (queue->rear + 1) % queue->capacity;
    // 3. Stores the item at the updated rear index in the queue's array.
    queue->array[queue->rear] = item;
    
    // 4. If the queue was initially empty (front == -1), sets the front index to the rear index.
    if(queue->front == -1)
    {
        
        queue->front = queue->rear;
        
    }
    
    // 5. Increments the queue's size.
    queue->size = queue->size + 1;
    // 6. Prints a message indicating that the item was enqueued.
    cout << item << " enqueued to queue\n";
    
}

int main()
{
    cout << "Testing" << endl;
    Queue* q = createQueue(10);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30); 

    return 0;
}
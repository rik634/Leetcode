// problem statement:  Implement a First-In-First-Out (FIFO) queue using an array. The implemented queue should support the following operations: push, dequeue, pop, and isEmpty.
//Implement the ArrayQueue class:

//void push(int x): Adds element x to the end of the queue.
//int pop(): Removes and returns the front element of the queue.
//int peek(): Returns the front element of the queue without removing it.
//boolean isEmpty(): Returns true if the queue is empty, false otherwise.

// solution: 
class ArrayQueue {
    // Array to store queue elements
    int* arr;
    // Indices for start and end of the queue
    int start, end;
    // Current size and maximum size of the queue
    int currSize, maxSize;
public:
    // Constructor
    ArrayQueue() {
        arr = new int[10];
        start = -1;
        end = -1;
        currSize = 0;
        maxSize = 10;
    }
    // Method to push an element into the queue
    void push(int x) {
        // Check if the queue is full
        if (currSize == maxSize) {
            cout << "Queue is full\nExiting..." << endl;
            exit(1);
        }
        // If the queue is empty, initialize start and end
        if (end == -1) {
            start = 0;
            end = 0;
        } 
        else {
            // Circular increment of end
            end = (end + 1) % maxSize;
        }
        arr[end] = x;
        currSize++;
    }
    // Method to pop an element from the queue
    int pop() {
        // Check if the queue is empty
        if (start == -1) {
            cout << "Queue Empty\nExiting..." << endl;
            exit(1);
        }
        int popped = arr[start];
        // If the queue has only one element, reset start and end
        if (currSize == 1) {
            start = -1;
            end = -1;
        }
        else {
            // Circular increment of start
            start = (start + 1) % maxSize;
        }
        currSize--;
        return popped;
    }
    // Method to get the front element of the queue
    int peek() {
        // Check if the queue is empty
        if (start == -1) {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[start];
    }
    // Method to determine whether the queue is empty
    bool isEmpty() {
        return (currSize == 0);
    }
};

//Time Complexity: O(1) for all operations (push, pop, peek, isEmpty) since they involve simple index manipulations and array accesses.
//Space Complexity: O(1) since we are using a fixed-size array and a few variables.

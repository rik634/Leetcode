// problem statement: Implement a First-In-First-Out (FIFO) queue using a singly linked list. The implemented queue should support the following operations: push, pop, peek, and isEmpty.
//Implement the LinkedListQueue class:
//void push(int x): Adds element x to the end of the queue.
//int pop(): Removes and returns the front element of the queue.
//int peek(): Returns the front element of the queue without removing it.
//boolean isEmpty(): Returns true if the queue is empty, false otherwise.

// solution:
// Node structure
struct Node {
    int val;
    Node *next;
    Node(int d) {
        val = d;
        next = NULL;
    }
};

// Structure to represent stack
class LinkedListQueue {
private:
    Node *start; // Start of the queue
    Node *end; // End of the queue
    int size; // Size of the queue

public:
    // Constructor
    LinkedListQueue() {
        start = end = NULL;
        size = 0;
    }

    // Method to push an element in the queue
    void push(int x) {
        // Creating a node 
        Node *element = new Node(x);
        
        // If it is the first element being pushed
        if(start == NULL) {
            // Initialise the pointers
            start = end = element;
        }
        else {
            end->next = element; // Updating the pointers
            end = element; // Updating the end
        }
        
        // Increment size by 1
        size++;
    }

    // Method to pop an element from the queue
    int pop() {
        // If the queue is empty
        if (start == NULL) {
            return -1; // Pop operation cannot be performed
        }
        
        int value = start->val; // Get the front value
        Node *temp = start; // Store the front temporarily
        start = start->next; // Update front to next node
        delete temp; // Delete old front node
        size--; // Decrement size
        
        return value; // Return data
    }
    
    // Method to get the front element in the queue
    int peek() {
        // If the stack is empty
        if (start == NULL) {
            return -1; // Top element cannot be accessed
        }
        
        return start->val; // Return the top
    }

    // Method to check if the queue is empty
    bool isEmpty() {
        return (size == 0);
    }
};
// time complexity: O(1) for all operations (push, pop, peek, isEmpty) since they involve constant time operations like pointer manipulation and value retrieval.
// space complexity: O(n) where n is the number of elements in the queue, as we are using a linked list to store the elements. Each element requires space for a node structure.


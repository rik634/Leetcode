// problem statement: Implement a Last-In-First-Out (LIFO) stack using a singly linked list. The implemented stack should support the following operations: push, pop, top, and isEmpty.
//Implement the LinkedListStack class:
//void push(int x): Pushes element x onto the stack.
//int pop(): Removes and returns the top element of the stack.
//int top(): Returns the top element of the stack without removing it.
//boolean isEmpty(): Returns true if the stack is empty, false otherwise.

// solution::
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
class LinkedListStack {
private:
    Node *head; // Top of Stack
    int size; // Size

public:
    // Constructor
    LinkedListStack() {
        head = NULL;
        size = 0;
    }

    // Method to push an element onto the stack
    void push(int x) {
        // Creating a node 
        Node *element = new Node(x);
        
        element->next = head; // Updating the pointers
        head = element; // Updating the top
        
        // Increment size by 1
        size++;
    }

    // Method to pop an element from the stack
    int pop() {
        // If the stack is empty
        if (head == NULL) {
            return -1; // Pop operation cannot be performed
        }
        
        int value = head->val; // Get the top value
        Node *temp = head; // Store the top temporarily
        head = head->next; // Update top to next node
        delete temp; // Delete old top node
        size--; // Decrement size
        
        return value; // Return data
    }
    
    // Method to get the top element of the stack
    int top() {
        // If the stack is empty
        if (head == NULL) {
            return -1; // Top element cannot be accessed
        }
        
        return head->val; // Return the top
    }

    // Method to check if the stack is empty
    bool isEmpty() {
        return (size == 0);
    }
};

// time complexity: O(1) for push, pop, size, isEmpty, peek operations.
// space complexity: O(N) because the stack requires space proportional to the number of elements it stores.

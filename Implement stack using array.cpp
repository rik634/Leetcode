// problem statement: Implement a Last-In-First-Out (LIFO) stack using an array. The implemented stack should support the following operations: push, pop, peek, and isEmpty.
//Implement the ArrayStack class:
//void push(int x): Pushes element x onto the stack. int pop(): Removes and returns the top element of the stack. int top(): Returns the top element of the stack without removing it. boolean isEmpty(): Returns true if the stack is empty, false otherwise.

// solution:
class ArrayStack {
private:
    // Array to hold elements
    int* stackArray;
    // Maximum capacity
    int capacity; 
     // Index of top element  
    int topIndex;   
public:
    // Constructor
    ArrayStack(int size = 1000) {
        capacity = size;
        stackArray = new int[capacity];
        // Initialize stack as empty
        topIndex = -1; 
    }
    // Destructor
    ~ArrayStack() {
        delete[] stackArray;
    }
    // Pushes element x 
    void push(int x) {
        if (topIndex >= capacity - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        stackArray[++topIndex] = x;
    }
    // Removes and returns top element
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            // Return invalid value
            return -1; 
        }
        return stackArray[topIndex--];
    }
    // Returns top element
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return stackArray[topIndex];
    }
   /* Returns true if the 
   stack is empty, false otherwise*/
    bool isEmpty() {
        return topIndex == -1;
    }
};

//Time Complexity: O(1) for all operations (push, pop, top, isEmpty).
//Space Complexity: O(N), where N is the maximum capacity of the stack, as we are using an array to store the elements.

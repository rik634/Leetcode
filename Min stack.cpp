// level: Medium
// problem statement: Design a stack that supports the following operations in constant time: push, pop, top, and retrieving the minimum element.
//Implement the MinStack class:
//MinStack(): Initializes the stack object.
//void push(int val): Pushes the element val onto the stack.
//void pop(): removes the element on the top of the stack.
//int top(): gets the top element of the stack.
//int getMin(): retrieves the minimum element in the stack.

// brute force: 
// Class to implement Minimum Stack
class MinStack {
private:
    stack <pair<int,int>> st;
public:
    MinStack() {
    }
    void push(int value) {
        
        // If stack is empty
        if(st.empty()) {
            
            // Push current value as minimum
            st.push( {value, value} );
            return;
        }
        int mini = min(getMin(), value);
        st.push({value, mini});
    }
    void pop() {
        st.pop(); 
    }
    int top() {
        // Return the top value
        return st.top().first;
    }
    int getMin() {
        // Return the minimum
        return st.top().second;
    }
};

//Time Complexity: O(1) for all operations (push, pop, top, getMin) as they involve constant time operations on the stack.
//Space Complexity: O(n) where n is the number of elements in the stack, as we store pairs of values (element and minimum) in the stack.

// optimized
class MinStack {
private:
    // Initialize a stack
    stack <int> st;
    // To store the minimum value 
    int mini;
    
public:
    
    // Empty Constructor
    MinStack() {
    }
    
    // Method to push a value in stack
    void push(int value) {
        
        // If stack is empty
        if(st.empty()) {
            //Update the minimum value
            mini = value;
            
            // Push current value as minimum
            st.push( value );
            return;
        }
        
        // If the value is greater than the minimum
        if(value > mini) {
            st.push(value);
        }
        else {
            // Add the modified value to stack
            st.push(2 * value - mini);
            // Update the minimum
            mini = value;
        }
    }
    
    // Method to pop a value from stack
    void pop() {
        // Base case
        if(st.empty()) return;
        
        // Get the top
        int x = st.top();
        st.pop(); // Pop operation
        
        // If the modified value was added to stack
        if(x < mini) {
            // Update the minimum
            mini = 2 * mini - x;
        }
    }
    
    // Method to get the top of stack
    int top() {
        // Base case
        if(st.empty()) return -1;
        
        // Get the top
        int x = st.top();
        
        // Returnn top if minimum is less than the top
        if(mini < x) return x;
        
        //Otherwise return mini
        return mini;
    }
    
    // Method to get the minimum in stack
    int getMin() {
        // Return the minimum
        return mini;
    }
};
//Time Complexity: O(1) for all operations (push, pop, top, getMin) as they involve constant time operations on the stack.
//Space Complexity: O(n) where n is the number of elements in the stack, as we store pairs of values (element and minimum) in the stack.

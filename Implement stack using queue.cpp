// problem statement: Implement a Last-In-First-Out (LIFO) stack using a single queue. The implemented stack should support the following operations: push, pop, top, and isEmpty.
//Implement the QueueStack class:
//push(int x): Pushes element x onto the stack.
//pop(): Removes and returns the top element of the stack.
//top(): Returns the top element of the stack without removing it.
//isEmpty(): Returns true if the stack is empty, false otherwise.

// solution: (using single queue)
class MyStack {
     queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        
        q.push(x);
        int size = q.size();
        for(int i=0;i<size-1;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        
        if(q.size()==0)
        {
            return -1;
        }
        int t=q.front();
        q.pop();
        return t;
    }
    
    int top() {
        if(q.size()==0)
        {
            return -1;
        }
        return q.front();
    }
    
    bool empty() {
        
        if(q.size()==0)
        {
            return true;
        }
        return false;
    }
};

//Time Complexity:
//Push operation: O(n) (where n is the number of elements in the queue at that time) because every time an element is pushed, all the elements in the queue are popped from the front and pushed in the back again.
//Pop operation: O(1) as constant operations are performed.
//Top operation: O(1) as constant operations are performed.
//IsEmpty operation: O(1) as constant operations are performed.

//Space Complexity: O(k) for storing k elements in the queue.

// solution( using 2 queue)
class MyStack {
private:
    std::queue<int> q1;
    std::queue<int> q2;

public:
    MyStack() {}

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int poppedVal = q1.front();
        q1.pop();
        std::swap(q1, q2);

        return poppedVal;
    }

    int top() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int topVal = q1.front();
        q2.push(q1.front());
        q1.pop();
        std::swap(q1, q2);

        return topVal;
    }

    bool empty() {
        return q1.empty();
    }
};
// Time complexity: push and empty are O(1), pop and top are O(n)
//Space complexity: O(n)

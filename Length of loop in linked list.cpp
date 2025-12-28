// problem statement: Given the head of a linked list, determine the length of a loop present in the linked list. If there's no loop present, return 0.
// brute force
class Solution {
public:
    // Function to return the length of loop using hashing
    int lengthOfLoop(Node* head) {
        // Hashmap to store visited nodes and their timer values
        unordered_map<Node*, int> visitedNodes;
        // Pointer to traverse the linked list
        Node* temp = head;
        // Timer to track visited nodes
        int timer = 0;
        // Traverse the linked list till temp reaches nullptr
        while (temp != NULL) {
            // If revisiting a node, return the difference of timer values
            if (visitedNodes.find(temp) != visitedNodes.end()) {
                // Calculate the length of the loop
                int loopLength = timer - visitedNodes[temp];
                // Return the length of the loop
                return loopLength;
            }
            // Store the current node and its timer value
            visitedNodes[temp] = timer;
            // Move to the next node
            temp = temp->next;
            // Increment the timer
            timer++;
        }
        // If traversal is completed and we reach the end of the list
        // means there is no loop
        return 0;
    }
};
// time complexity: O(n)
// space complexity:O(n)

// optimized
class Solution {
public:
    // Function to return the length of loop using Floyd's Algorithm
    int lengthOfLoop(Node* head) {
        // Initialize slow and fast pointers
        Node* slow = head;
        Node* fast = head;
        // Loop until fast and slow meet
        while (fast != NULL && fast->next != NULL) {
            // Move slow by one step
            slow = slow->next;
            // Move fast by two steps
            fast = fast->next->next;
            // If slow and fast meet, loop detected
            if (slow == fast) {
                // Count the length of the loop
                return countLoopLength(slow);
            }
        }
        // No loop found
        return 0;
    }
    // Function to count loop length
    int countLoopLength(Node* meetingPoint) {
        // Start from meeting point
        Node* temp = meetingPoint;
        int length = 1;
        // Move until we meet again
        while (temp->next != meetingPoint) {
            temp = temp->next;
            length++;
        }
        return length;
    }
};

// time complexity O(n)
// space complexity:O(1)

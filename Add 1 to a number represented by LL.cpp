// problem statement: Given the head of a singly linked list representing a positive integer number. Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. The task is to add one to the value represented by the linked list and return the head of a linked list containing the final value.
//The number will contain no leading zeroes except when the value represented is zero itself.

// iterative approach (reverse, do the addition operation, reverse again)
class Solution {
public:
    // function to reverse the linked list
    Node* reverseList(Node* node) {
        Node* prev = nullptr;
        Node* current = node;

        while (current) {
            Node* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }

    // Function to add one to the number represented by the linked list
    Node* addOne(Node* head) {
        // Reverse the list to make least significant digit accessible
        head = reverseList(head);

        Node* current = head;
        // Initial carry since we want to add 1
        int carry = 1;  

        // Traverse the list and add carry
        while (current && carry) {
            int sum = current->data + carry;
            current->data = sum % 10;
            carry = sum / 10;

            // If there's no next node and we still have a carry, append a new node
            if (!current->next && carry) {
                current->next = new Node(carry);
                carry = 0;  
            }

            current = current->next;
        }

        // Reverse the list back to restore original order
        head = reverseList(head);
        return head;
    }
};
// time complexity: O(n) + O(n) + O(n) = O(3*n) ~=O(n)
// space complexity: O(1)

// recursive approach
class Solution {
public:
    // Recursive function to add one from least significant digit (rightmost node)
    int addOneUtil(Node* node) {
        // Base case: when reaching beyond last node, return carry = 1
        if (!node) return 1;
        
        // Recurse to the end
        int carry = addOneUtil(node->next);  
        int sum = node->data + carry;
        node->data = sum % 10;
        // Return new carry
        return sum / 10;  
    }

    // Function to add one to the number represented by the linked list
    Node* addOne(Node* head) {
        // Perform recursive addition
        int carry = addOneUtil(head);

        // If carry remains after processing the head, create a new head node
        if (carry) {
            Node* newHead = new Node(carry);
            newHead->next = head;
            head = newHead;
        }

        return head;
    }
};
// time complexity:O(n)
// space complexity:O(n) (recursive stack space)


// problem statement: Given the head of a doubly linked list with its values sorted in non-decreasing order. 
//Remove all duplicate occurrences of any value in the list so that only distinct values are present in the list.
//Return the head of the modified linked list.

// solution:
class Solution {
public:
    // Function to remove duplicate values from a sorted doubly linked list
    Node* removeDuplicates() {
        // If the list is empty, return null
        if (!head) return nullptr;
        Node* current = head;
        // Traverse the list until the second last node
        while (current != nullptr && current->next != nullptr) {
            Node* nextDistinct = current->next;
            // Skip and delete all nodes with the same value as current
            while (nextDistinct != nullptr && nextDistinct->data == current->data) {
                Node* duplicateNode = nextDistinct;
                nextDistinct = nextDistinct->next;
                delete duplicateNode; // Free memory of duplicate node
            }
            // Connect current node to the next distinct node
            current->next = nextDistinct;
            if (nextDistinct != nullptr) {
                nextDistinct->prev = current;
            }
            // Move to the next node
            current = current->next;
        }
        // Return the updated head of the list
        return head;
    }
};
// time complexity: O(n)
// space complexity: O(1)

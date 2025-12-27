// problme statement: Given a Doubly Linked List, delete the last node of the Doubly Linked List.
class Solution {
public:
    // Function to delete tail of DLL
    Node* deleteTail(Node* head) {
        // If list is empty
        if (head == NULL) return NULL;

        // If only one node present
        if (head->next == NULL) {
            delete head;
            return NULL;
        }

        // Traverse to the last node
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Update second last node's next to NULL
        temp->prev->next = NULL;

        // Delete tail node
        delete temp;

        // Return head
        return head;
    }
};
// time complexity:O(N)
// space complexity:O(1)

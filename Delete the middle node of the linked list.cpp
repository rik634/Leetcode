// level: Medium
// problem statement: Given the head of a linked list of integers, delete the middle node of the linked list and return the modified head. However, if the linked list has an even number of nodes, delete the second middle node.

// brute force
class Solution {
public:
    // Function to delete the middle node of a linked list
    Node* deleteMiddle(Node* head) {
        // Initialize a temporary node to traverse the linked list
        Node* temp = head; 
        // Variable to hold the number of nodes in the linked list
        int n = 0;
        // Loop to count the number of nodes in the linked list
        while (temp != NULL) {
            n++;
            temp = temp->next;
        }
        // Calculate the index of the middle node
        int res = n / 2;
        // Reset the temporary node to the beginning of the linked list
        temp = head;
        // Loop to find the middle node to delete
        while (temp != NULL) {
            res--;
            // If the middle node is found
            if (res == 0) {
                // Create a pointer to the middle node
                Node* middle = temp->next;
                // Adjust pointers to skip the middle node
                temp->next = temp->next->next;
                // Free the memory allocated to the middle node
                free(middle);
                // Exit the loop after deleting the middle node
                break;
            }
            // Move to the next node in the linked list
            temp = temp->next;
        }
        // Return the head of the modified linked list
        return head;
    }
};
// time complexity:O(n) + O(n/2)
// space complexity:O(1)

// optimized
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }
        ListNode* prev=NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            prev=slow;
            slow = slow->next;
            fast=fast->next->next;
        }
        prev->next=prev->next->next;
        return head;
    }
};
// time complexity:O(N)
// space complexity: O(1)

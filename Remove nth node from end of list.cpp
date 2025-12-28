// level: Medium
// problem statement: Given a linked list and an integer N, the task is to delete the Nth node from the end of the linked list and print the updated linked list.

// brute force
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        int ind=len-n;
        if(ind==0)
        {
            return head->next;
        }
        temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL)
        {
            ind--;
            if(ind==0)
            {
                break;
            }
           temp=temp->next;
           prev=temp;
        }
        temp->next=temp->next->next;
        return head;
    }
};
// time complexity : O(L)+ O(L-N) (L= length of linked list, N=nth element)
// space complexity:O(1)

// optimized
class Solution {
public:
    // Function to delete the Nth node from the end 
    // using the optimized two-pointer method
    Node* deleteNthNodeFromEnd(Node* head, int N) {
        // Create a dummy node before head to handle edge cases
        Node* temp = new Node(0, head);

        // Initialize slow and fast pointers at dummy
        Node* slow = temp;
        Node* fast = temp;
        // Move fast pointer N+1 steps ahead to create a gap
        for (int i = 0; i <= N; i++) {
            fast = fast->next;
        }
        // Move both pointers until fast reaches the end
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        // Slow is now at node before target → delete target node
        slow->next = slow->next->next;
        // Return updated head
        return temp->next;
    }
};
// time complexity:O(L)
// space complexity:O(1)

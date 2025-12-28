// level: easy
//Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.
// brute force (iterative)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* temp=head;
        stack<int> st;
        while(temp!=NULL)
        {
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(!st.empty())
        {
            auto p = st.top();
            st.pop();
            temp->val=p;
            temp=temp->next;
        }
        return head;
    }
};
// time complexity:O(2*n) (n= length of linked list) =O(n)
// space complexity:O(n)

// optimal approach (iterative)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* front=NULL;
        while(temp!=NULL)
        {
            front = temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
};
// time complexity:O(n)
// space complexity:O(1)

// optimized (recursive)
class Solution {
public:
    // Recursive function to reverse the linked list
    ListNode* reverseList(ListNode* head) {
        // Base case: if list is empty or has one node
        if (head == NULL || head->next == NULL)
            return head;

        // Recursively reverse the rest of the list
        ListNode* newHead = reverseList(head->next);

        // Store the next node
        ListNode* front = head->next;

        // Make the next node point back to current
        front->next = head;

        // Break the current node's forward link
        head->next = NULL;

        // Return the new head of the reversed list
        return newHead;
    }
};
// time complexity:O(n)
// space complexity:O(n) (recursive stack space)

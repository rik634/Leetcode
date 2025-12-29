// level: Medium
// problem statement: Given the head of a singly linked list containing integers, shift the elements of the linked list to the right by k places and return the head of the modified list. 
//Do not change the values of the nodes, only change the links between nodes.

// brute force
class Solution {
public:
    // Function to rotate the list to the right by k positions
    ListNode* rotateRight(ListNode* head, int k) {
        // If list is empty or has only one node or no rotation needed
        if (!head || !head->next || k == 0) return head;

        // Repeat the rotation process k times
        for (int i = 0; i < k; i++) {
            // Initialize two pointers to traverse the list
            ListNode* curr = head;
            ListNode* prev = NULL;

            // Traverse to the last node
            while (curr->next) {
                prev = curr;
                curr = curr->next;
            }

            // Detach the last node and place it at the beginning
            prev->next = NULL;
            curr->next = head;
            head = curr;
        }

        // Return the rotated head
        return head;
    }
};
// time complexity:O(k*n)
// space complexity:O(1)

// optimized
class Solution {
public:
    int getLength(ListNode* node)
    {
        int l=0;
        while(node!=NULL)
        {
            l++;
            node=node->next;
        }
        return l;
    }
    ListNode* getKthNode(ListNode* node, int k)
    {
        int ind=1;
        while(ind<k)
        {
            node=node->next;
            ind++;
        }
        return node;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL )
        {
            return head;
        }
        
        int len = getLength(head);
        k=k%len;
        if(k==0)
        {
            return head;
        }
        ListNode* temp=getKthNode(head,len-k);
        ListNode* front=temp->next;
        
        temp->next=NULL;
        temp=front;
        while(temp!=NULL && temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=head;
        return front;
    }
};
// time complexity: O(n) (calculate length) + O(n) = O(n)
// space complexity:O(1)

// another code:
class Solution {
public:
    // Function to rotate the linked list to the right by k places
    ListNode* rotateRight(ListNode* head, int k) {
        // If list is empty or has only one node, or no rotation is needed
        if (!head || !head->next || k == 0)
            return head;

        // Initialize length and tail pointer
        int length = 1;
        ListNode* tail = head;

        // Traverse to find the tail and length
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // Make it a circular linked list
        tail->next = head;

        // Effective rotations needed
        k = k % length;

        // Traverse to the new tail (length - k - 1 steps from head)
        int stepsToNewTail = length - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // Set the new head
        ListNode* newHead = newTail->next;

        // Break the circle
        newTail->next = NULL;

        return newHead;
    }
};
// time complexity:O(n)
// space complexity:O(1)

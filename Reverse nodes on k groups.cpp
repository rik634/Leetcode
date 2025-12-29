// level: hard
// problme statement: Given the head of a singly linked list containing integers, reverse the nodes of the list in groups of k and return the head of the modified list. 
//If the number of nodes is not a multiple of k, then the remaining nodes at the end should be kept as is and not reversed.
//Do not change the values of the nodes, only change the links between nodes.

// solution:
class Solution {
public:
    ListNode* reverseLL(ListNode* node)
    {
        ListNode* temp=node;
        ListNode* prev=NULL;
        ListNode* front=NULL;
        while(temp!=NULL)
        {
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    ListNode* getKthNode(ListNode* node,int& k)
    {
        
         int ind=1;
            while(ind<k && node!=NULL)
            {
                node=node->next;
                ind++;
            }
        return node;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        if(k==1)
        {
            return head;
        }
        int ind;
        ListNode* prev=new ListNode(-1);
        prev->next=head;
        ListNode* curr=prev;
        ListNode* temp=curr;
        ListNode* front=NULL;
        while(temp!=NULL && temp->next!=NULL)
        {
            temp=temp->next;
           
            ListNode* kth = getKthNode(temp,k);
            if(kth==NULL)
            {
                break;
            }
            front=kth->next;
            prev->next=NULL;
            kth->next=NULL;
            temp=reverseLL(temp);
            prev->next=temp;
            temp = getKthNode(temp,k);
            temp->next=front;
            prev=temp;
        }
        return curr->next;
    }
};
// time complexity: O(n)
// space complexity:O(1)


// another code
class Solution {
public:
    // Function to reverse nodes in groups of k
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Creating a dummy node to handle edge cases easily
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Pointer to keep track of the previous group's tail
        ListNode* groupPrev = dummy;

        while (true) {
            // Finding the k-th node from the groupPrev
            ListNode* kth = getKthNode(groupPrev, k);
            if (!kth) break;

            // Store the next group's head
            ListNode* groupNext = kth->next;

            // Break the chain to reverse current k-group cleanly
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            // Reversing k nodes
            for (int i = 0; i < k; i++) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connecting previous group to the reversed group
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }

        // Returning the new head
        return dummy->next;
    }

    // Helper function to find the k-th node from the current node
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};
// time complexity: O(n)
// space complexity:O(1)

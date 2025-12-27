// level:easy
// problem statement: Given the head of a linked list of integers, determine the middle node of the linked list. However, if the linked list has an even number of nodes, return the second middle node.
// brute force

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        int mid;
        mid=(len/2)+1;
        temp=head;
        while(temp!=NULL)
        {
            mid--;
            if(mid==0)
            {
                break;
            }
            temp=temp->next;
        }
        return temp;
    }
};
// time complexity:O(n)+O(n/2)
// space complexity:O(1)


// optimized
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// time complexity:O(n/2)
// space complexity:O(1)

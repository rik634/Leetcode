// level:easy
// problem statement:  Given a Linked List, determine whether the linked list contains a cycle or not.

// brute force
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* temp=head;
        unordered_set<ListNode*> st;
        while(temp!=NULL)
        {
            if(st.find(temp)!=st.end())
            {
                return true;
            }
            st.insert(temp);
            temp=temp->next;
        }
        return false;
    }
};
// time complexity:O(n*n)
// space complexity:O(n)

// optimized
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                return true;
            }
        }
        return false;
    }
};
// time complexity:O(n)
// space complexity:O(1)

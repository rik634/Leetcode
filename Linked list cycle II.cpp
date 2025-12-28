// level: Medium
// problem statement:Given the head of a linked list that may contain a cycle, return the starting point of that cycle. If there is no cycle in the linked list return null.

// brute force (hash)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        unordered_set<ListNode*> st;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(st.find(temp)!=st.end())
            {
                return temp;
            }
            st.insert(temp);
            temp=temp->next;
        }

        return NULL;
    }
};
// time complexity:O(n)
// space complexity:O(n)


// optimized (tortoise and hare algorithm)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
            {
               slow=head;
               while(slow!=fast)
               {
                slow=slow->next;
                fast=fast->next;
               }
               return slow;
            }
        }
        return NULL;
    }
};
// time complexity:O(n)
// space complexity:O(1)

// level: easy
// problem statement:

// brute force
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* tailA=headA;
        ListNode* tailB=headB;
        unordered_set<ListNode*> st;
        while(tailA!=NULL)
        {
            st.insert(tailA);
            tailA=tailA->next;
        }
        while(tailB!=NULL)
        {
            if(st.find(tailB)!=st.end())
            {
                return tailB;
            }
            tailB=tailB->next;
        }
        return NULL;
    }
};
// time complexity:O(min(m,n)) (m=length of one LL, n = length of LL)
// space complexity:O(max(m,n))

// optimized

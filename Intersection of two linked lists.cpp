// level: easy
// problem statement:Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

// brute force
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* tailA=headA;
        ListNode* tailB=headB;
        ListNode* temp;
        while(tailA!=NULL && tailB!=NULL)
        {
            temp=tailB;
            while(temp!=NULL)
            {
                if(temp==tailA)
                {
                    return temp;
                }
                temp=temp->next;
            }
            tailA=tailA->next;
        }
        return NULL;
    }
};
// time complexity: O(m*n)
// space complexity:O(1)


// better approach (hashing)
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
// time complexity:O(m+n) (m=length of one LL, n = length of LL)
// space complexity:O(n) (we are soring the first list)

// optimized approac 1
class Solution {
public:
    int findLengthLL(ListNode* headA, ListNode* headB)
    {
        int len1 = 0, len2 = 0;
        while (headA != NULL || headB != NULL) {
           if (headA != NULL) {
              ++len1;
            headA = headA->next;
        }
        if (headB != NULL) {
            ++len2;
            headB = headB->next;
        }
    }
    return len1 - len2;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int diff = findLengthLL(headA,headB);
        if(diff<0) // headB is longer
        {
            while(diff!=0)
            {
                headB=headB->next;
                diff++;
            }
        }
        else
        {
            while(diff!=0)
            {
                headA=headA->next;
                diff--;
            }
        }
        while(headA!=NULL)
        {
            if(headA==headB)
            {
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
        
    }
};
// time complexity: O(max(m,n)) ()find length diff ) + O(abs(m-n)) + O(min(m,n)) 
// space complexity:O(1)

// optimal approach-2
node* intersectionPresent(node* head1, node* head2) {
    node* d1 = head1;
    node* d2 = head2;
    
    // Traverse both lists, when one reaches the end, redirect it to the head of the other list
    while (d1 != d2) {
        d1 = d1 == NULL ? head2 : d1->next;
        d2 = d2 == NULL ? head1 : d2->next;
    }
    
    return d1;  // If they meet, return the intersection node, otherwise NULL
}

// time complexity: O(2*max(m,n))
// space complexity:O(1)

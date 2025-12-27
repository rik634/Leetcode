// level:Medium
// problem statement: 

// if we are told not to delet the tail
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        node->val=node->next->val;
        node->next=node->next->next;
    }
};
// time complexity:O(1)
// space complexity:O(1)

// if we can delet the tail
class Solution {
public:
    void deleteNode(ListNode* node) {
        
       while(node->next->next!=NULL && node->next!=NULL)
       {
            node->val=node->next->val;
            node=node->next;
       }
       node->val=node->next->val;
       node->next=NULL;
    }
};
// time complexity:O(n) // n length od the node after the dleet node
// space complexity:O(1)

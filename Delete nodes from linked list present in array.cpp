// level: Medium
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
       
        unordered_set<int> s(nums.begin(),nums.end());
        while(head!=NULL &&  s.find(head->val)!=s.end())
        {
            head = head->next;
        }
        ListNode* temp = head;
        ListNode* prev=NULL;

        while(temp->next!=NULL && temp!=NULL)
        {
            int v = temp->next->val;
            if(s.find(v)!=s.end())
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;
    }
};
// Time complexity: O(n)
// soace complexity: O(n)

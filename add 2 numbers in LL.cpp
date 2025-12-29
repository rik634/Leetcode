// level: Medium
// problem statement:  Add two numbers represented as Linked Lists.

// solution:
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* curr = new ListNode(-1),*temp=curr;
        int a,b,c,carry=0;
        while((l1!=NULL || l2!=NULL) || carry)
        {
            int sum=0;
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            int value = sum%10;
            carry=sum/10;
            temp->next=new ListNode(value);
            temp=temp->next;
        }
        
        if(carry)
        {
            temp->next=new ListNode(carry);
        }
        return curr->next;
    }
};
// time complexity:O(max(m+n)
// space complexity;O(max(m,n))

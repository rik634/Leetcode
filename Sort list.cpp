// level: Medium
// problem statement: Given a linked list, sort its nodes based on the data value in them. Return the head of the sorted linked list.

// brute force
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* temp=head;
        vector<int> v;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        sort(v.begin(),v.end());
        temp=head;
        int ind=0;
        while(temp!=NULL)
        {
            temp->val=v[ind];
            ind++;
            temp=temp->next;
        }
        return head;
    }
};
// time complexity: O(n) + O(n) + O(nlogn) = O(n*(1+logn))
// space complexity:O(n)

// optimized
class Solution {
public:
    ListNode* mergeLLToSort(ListNode* left, ListNode* right)
    {
        ListNode* temp= new ListNode(-1);
        ListNode* curr=temp;

        while(left!=NULL && right!=NULL)
        {
            if(left->val<=right->val)
            {
                curr->next=left;
                left=left->next;
            }
            else
            {
                curr->next=right;
                right=right->next;
            }
            curr=curr->next;
        }
        if(left!=NULL)
        {
            curr->next=left;
        }
        else
        {
            curr->next=right;
        }
        return temp->next;
    }
    ListNode* findMiddle(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* middle = findMiddle(head);
        ListNode* r = middle->next;
        middle->next=NULL;
        ListNode* l=head;
        l = sortList(l);
        r = sortList(r);
        return mergeLLToSort(l,r);

    }
};
// time complexity: O(nlogn)
// space complexity:O(1)

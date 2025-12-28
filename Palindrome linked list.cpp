// level:Medium
// problem statement:  Given the head of a singly linked list representing a positive integer number.
//Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. 
//Check whether the linked list values form a palindrome or not. Return true if it forms a palindrome, otherwise, return false. .
// A palindrome is a sequence that reads the same forward and backwards.

// brute force
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        vector<int> v;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        int n = v.size();
        for(int i=0;i<n/2;i++)
        {
            if(v[i]!=v[n-i-1]){
                return false;
            }
        }
        return true;
    }
};
// time complexity:O(n) + O(n/2) = O(n)
// space complexity:O(n)

// brute force (with stack:
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        stack<int> st;
        ListNode* temp = head;
        int count=0;
        while(temp!=NULL)
        {
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL)
        {
            if(temp->val!=st.top())
            {
                return false;
            }
            temp=temp->next;
            st.pop();
        }
        return true;
    }
};
// time complexity:O(2*n)
// space complexity:O(n)

// optimized (reverse and compare) 
class Solution {
public:
    ListNode* reverseList(ListNode* node)
    {
        ListNode* prev=NULL;
        ListNode* front=NULL;
        ListNode* temp=node;
        while(temp!=NULL){
            front = temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        
       if(head==NULL || head->next==NULL)
       {
        return true;
       }
       ListNode* slow=head;
       ListNode* fast = head;
       while(fast!=NULL && fast->next!=NULL)
       {
          slow = slow->next;
          fast = fast->next->next;
       }
       ListNode* mid = slow;
       mid = reverseList(mid);
       ListNode* temp=head;
       while(mid!=NULL)
       {
           if(temp->val!=mid->val)
           {
            return false;
           }
           temp=temp->next;
           mid = mid->next;
       }
       return true;
    }
};
// time complexity: O(n/2) + O(n/2) + O(n/2)= O(n)
// space complexity:O(1)

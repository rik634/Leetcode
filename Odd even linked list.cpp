// level: Medium
// problem statement: Given the head of a singly linked list. Group all the nodes with odd indices followed by all the nodes with even indices and return the reordered list. 
//Consider the 1st node to have index 1 and so on. The relative order of the elements inside the odd and even group must remain the same as the given input.
// solution:
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* temp=head,*curr=temp;
        int count=0;
        ListNode* even=new ListNode(1),*temp2=even;
        ListNode* odd = new ListNode(2),*temp1=odd;
        ListNode* front=NULL;
        while(temp!=NULL)
        {
            count++;
            curr=temp;
            temp=temp->next;
            curr->next=NULL;
            if(count%2!=0)
            {
                temp1->next=curr;
                temp1=curr;
            }
            else
            {
                temp2->next=curr;
                temp2=curr;
            }  
        }
        head=odd->next;
        temp1->next=even->next;
        return head;
    }
};
// time complexity:O(n)
// space complexity:O(1)

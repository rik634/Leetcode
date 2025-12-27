// problem statement: Given the head of a linked list, print the length of the linked list.
class Solution {
public:
    
    int lengthOfLinkedList(Node* head) {
     
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};
// time complexity:O(n)
// space complexity:O(1)

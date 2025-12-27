// problem statement: Given the head of a linked list and an integer value, find out whether the integer is present in the linked list or not. Return true if it is present, or else return false.
class Solution {
public:
   
    bool searchValue(Node* head, int key) {
       
        Node* current = head;
        while (current != NULL) {
            if (current->data == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};
// time complexity:O(n)
// space complexity:O(1)

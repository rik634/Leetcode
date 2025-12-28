// problem statement: Given a linked list containing only 0's, 1's, and 2's, sort the linked list by rearranging the links (not by changing the data values).
// solution:
class Solution {
public:
    // Function to sort linked list of 0s, 1s, and 2s by rearranging the links
    void sortZeroOneTwo(ListNode* ll) {
        // Create dummy nodes for three lists: 0s, 1s, and 2s
        ListNode* zeroDummy = new ListNode(-1);
        ListNode* oneDummy = new ListNode(-1);
        ListNode* twoDummy = new ListNode(-1);
        // Tail pointers to build each of the lists
        ListNode* zeroTail = zeroDummy;
        ListNode* oneTail = oneDummy;
        ListNode* twoTail = twoDummy;

        // Traverse original list and distribute nodes into 0s, 1s, or 2s list
        ListNode* curr = ll;
        while (curr) {
            if (curr->data == 0) {
                zeroTail->next = curr;
                zeroTail = zeroTail->next;
            } else if (curr->data == 1) {
                oneTail->next = curr;
                oneTail = oneTail->next;
            } else {
                twoTail->next = curr;
                twoTail = twoTail->next;
            }
            curr = curr->next;
        }

        // Connect the three lists:
        // zeroTail -> oneDummy.next -> twoDummy.next
        // Handle edge cases if 0s or 1s list is empty
        zeroTail->next = oneDummy->next ? oneDummy->next : twoDummy->next;
        oneTail->next = twoDummy->next;
        twoTail->next = nullptr;  // end the list

        // Update head to new sorted list
        ll = zeroDummy->next;

        // Delete dummy nodes (they were placeholders)
        delete zeroDummy;
        delete oneDummy;
        delete twoDummy;
    }
};

// time complexity:O(n)
// space complexity:O(1)

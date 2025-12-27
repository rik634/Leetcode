// problem statement: Given a doubly linked list of size ‘N’ consisting of positive integers, your task is to reverse it and return the head of the modified doubly linked list.
// brute force:
// Function to reverse a doubly linked list using a stack (brute force)
Node* reverseDLL(Node* head) {
    // If list is empty or has only one node, return as-is
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    // Stack to store node data
    stack<int> st;
    // Pointer to traverse the list
    Node* temp = head;
    // Push all node values to stack
    while (temp != nullptr) {
        st.push(temp->data);
        temp = temp->next;
    }
    // Reset temp to head for second pass
    temp = head;
    // Replace node values with those from stack
    while (temp != nullptr) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    // Return head of reversed list
    return head;
}
// time complexity: O(2*n)
// space complexity:O(1)

// optimized
// Function to reverse the doubly linked list in-place
Node* reverseDLL(Node* head) {
    // If list is empty or has one node, nothing to reverse
    if (head == nullptr || head->next == nullptr) return head;
    // Pointer to track the current node
    Node* curr = head;
    // Traverse the DLL
    while (curr != nullptr) {
        // Swap next and back pointers of current node
        Node* temp = curr->next;
        curr->next = curr->back;
        curr->back = temp;
        // Move to the next node in original order
        head = curr;          
        curr = temp;          
    }
    // Return new head after full reversal
    return head;
}
// time complexity: O(n)
// space complexity:O(1)


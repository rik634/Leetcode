## Problem statement
- Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):
  1. BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
  2. boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
  3. int next() Moves the pointer to the right, then returns the number at the pointer.
- Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.
- You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.


### Solution
```cpp
class BSTIterator {
    vector<TreeNode*> res;
    int ind;

public:
    BSTIterator(TreeNode* root) {

        stack<TreeNode*> st;
        while (true) {
            if (root != NULL) {
                st.push(root);
                root = root->left;
            } else {
                if (st.empty()) {
                    break;
                }
                root = st.top();
                st.pop();
                res.push_back(root);
                root = root->right;
            }
        }
        ind = -1;
    }

    int next() {
        ind++;
        if (ind == res.size()) {
            return -1;
        }
        return res[ind]->val;
    }

    bool hasNext() {

        if ((ind + 1) == res.size()) {
            return false;
        }
        return true;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)

### Optimal
- The optimal approach uses lazy evaluation — only traversing as far as needed, on demand
```cpp
class BSTIterator {
public:
    stack<TreeNode*> st;
    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
    BSTIterator(TreeNode* root) { pushLeft(root); }

    int next() {

        TreeNode* node = st.top();
        st.pop();
        pushLeft(node->right);
        return node->val;
    }

    bool hasNext() { return !st.empty(); }
};
```
- Time complexity: constructor time: O(h), next: O(h) ~=O(1) (amortized, hasNext: O(1)
- Space complexity: O(h)

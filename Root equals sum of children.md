## Problem statemnt
- You are given the root of a binary tree that consists of exactly 3 nodes: the root, its left child, and its right child.
- Return true if the value of the root is equal to the sum of the values of its two children, or false otherwise.

### Solution
```cpp
class Solution {
public:
    bool checkTree(TreeNode* root) {

        if (root == NULL) {
            return true;
        }
        if (root->left == NULL && root->right == NULL) {
            return true;
        }
        int sum = 0;
        if (root->left != NULL) {
            sum += root->left->val;
        }
        if (root->right != NULL) {
            sum += root->right->val;
        }

        return (sum == root->val) && checkTree(root->left) &&
               checkTree(root->right);
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n/2)

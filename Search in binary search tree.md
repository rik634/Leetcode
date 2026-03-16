## Problem statement
- You are given the root of a binary search tree (BST) and an integer val.
- Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

### Recursive
```cpp
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        if (root == NULL) {
            return NULL;
        }
        if (root->val == val) {
            return root;
        }
        if (val < root->val) {
            return searchBST(root->left, val);
        }
        return searchBST(root->right, val);
    }
};
```
- Time complexity: O(logn)
- Space complexity: O(logN)

### Iterative
```cpp
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        while (root != NULL && root->val != val) {
            if (root->val > val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return root;
    }
};
```
- Time complexity: O(logn)
- Space complexity: O(
- 1)

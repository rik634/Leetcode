## Problem statement
- Given a Binary Search Tree and a key value return the node in the BST having data equal to ‘key’ otherwise return nullptr.

### Solution
```cpp
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        if (root == NULL) {
            return NULL;
        }
        if (root->val == val) {
            return root;
        } else if (root->val < val) {
            return searchBST(root->right, val);
        }
        return searchBST(root->left, val);
    }
};
```
- Time complexity: O(logN) (during each recurive call, we discard half of its subtree)
- Space complexity: O(logN) 

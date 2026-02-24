## Problem statement
- You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.
- For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
- For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.
- The test cases are generated so that the answer fits in a 32-bits integer.


### Solution
```cpp
class Solution {
public:
    void dfs(TreeNode* node, int curr, int& sum) {
        if (node->left == NULL && node->right == NULL) {
            sum += (curr * 2 + node->val);
            return;
        }
        curr = 2 * curr + node->val;
        if (node->left != NULL) {
            dfs(node->left, curr, sum);
        }
        if (node->right != NULL) {
            dfs(node->right, curr, sum);
        }
    }
    int sumRootToLeaf(TreeNode* root) {

        int sum = 0;
        int curr = 0;
        dfs(root, curr, sum);
        return sum;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(h) (h=logn)

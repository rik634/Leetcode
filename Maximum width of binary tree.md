## Problem statement
- Given the root of a binary tree, return the maximum width of the given tree.
- The maximum width of a tree is the maximum width among all levels.
- The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
- It is guaranteed that the answer will in the range of a 32-bit signed integer.

### Solution
```cpp
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }
        int mx = 0;
        int l = 0;
        int r = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            long long f = q.front().second;
            l = 0;
            r = 0;
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                long long c = p.second - f;
                if (i == 0) {
                    l = p.second;
                } else if (i == size - 1) {
                    r = p.second;
                }
                if (p.first->left != NULL) {
                    q.push({p.first->left, 2 * c + 1});
                }
                if (p.first->right != NULL) {
                    q.push({p.first->right, 2 * c + 2});
                }
            }
            mx = max(mx, r - l + 1);
        }
        return mx;
    }
};
```
- Time complexity: O(N), each node is processed once in level order traversal.
- Space Complexity: O(N), in worst case, the queue holds all the nodes of the last level i.e. N/2 nodes.

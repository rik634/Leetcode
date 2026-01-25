## Problem statement
- Assuming standing on the right side of a binary tree and given its root, return the values of the nodes visible, arranged from top to bottom.

### Solution
```cpp
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> res;

        if (root == NULL) {
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                if (i == size - 1) {
                    res.push_back(p->val);
                }
                if (p->left != NULL) {
                    q.push(p->left);
                }
                if (p->right != NULL) {
                    q.push(p->right);
                }
            }
        }
        return res;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)

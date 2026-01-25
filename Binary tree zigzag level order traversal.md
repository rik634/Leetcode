## Problem statement


### Soluton
```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if (root == NULL) {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                temp.push_back(p->val);
                if (p->left != NULL) {
                    q.push(p->left);
                }
                if (p->right != NULL) {
                    q.push(p->right);
                }
            }
            if (flag == true) {
                reverse(temp.begin(), temp.end());
            }
            flag = !flag;
            res.push_back(temp);
        }
        return res;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)

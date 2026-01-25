## problem statement
- Given a Binary Tree, return the Vertical Order Traversal of it starting from the Leftmost level to the Rightmost level.
- If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

### Solution
```cpp
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        if (root == NULL) {
            return {};
        }
        vector<vector<int>> res;
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        // x height y width

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            mp[x][y].insert(node->val);
            if (node->left != NULL) {
                q.push({node->left, {x - 1, y + 1}});
            }
            if (node->right != NULL) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }
        for (auto u : mp) {
            vector<int> arr;
            for (auto v : u.second) {
                for (auto it : v.second) {
                    arr.push_back(it);
                }
            }
            res.push_back(arr);
        }
        return res;
    }
};
```
- Time complexity: O(nlogn) (for each node N, we have insertion in multiset and map, whcih take logN time)
- Space complexity: O(n)

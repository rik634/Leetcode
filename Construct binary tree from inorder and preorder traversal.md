## Problem statment
- Given the Preorder and Inorder traversal of a Binary Tree, construct the Unique Binary Tree represented by them..

### Solution
```cpp
class Solution {
public:
    int preIndex = 0;
    TreeNode* getTree(int l, int r, vector<int>& preorder, vector<int>& inorder,
                      unordered_map<int, int>& mp) {
        if (l > r) {
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[preIndex]);
        int ind = mp[preorder[preIndex]];
        preIndex++;

        node->left = getTree(l, ind - 1, preorder, inorder, mp);
        node->right = getTree(ind + 1, r, preorder, inorder, mp);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = preorder.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        return getTree(0, n - 1, preorder, inorder, mp);
    }
};
```
- Time Complexity: O(N), as ach node is visited once.
- Space Complexity: O(N), for the hashmap and recursion stack (worst case when tree is skewed).


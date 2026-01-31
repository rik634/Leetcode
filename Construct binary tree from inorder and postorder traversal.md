## Problem statement
- Given the Postorder and Inorder traversal of a Binary Tree, construct the Unique Binary Tree represented by them.

### Solution
```cpp
class Solution {
    int postIndex = 0;
public:
    TreeNode* getTree(int l, int r, int& n, vector<int>& inorder,
                      vector<int>& postorder, unordered_map<int, int>& mp) {
        if (l > r) {
            return NULL;
        }
        TreeNode* node = new TreeNode(postorder[postIndex]);
        postIndex++;

        int ind = mp[node->val];
        node->right = getTree(ind + 1, r, n, inorder, postorder, mp);
        node->left = getTree(l, ind - 1, n, inorder, postorder, mp);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n = inorder.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        reverse(postorder.begin(), postorder.end());
        return getTree(0, n - 1, n, inorder, postorder, mp);
    }
};
```
- Time complexity: O(n) (reverse) + O(n) (visiting each node once) = O(n)
- Space complexity: O(n) (map+recursive stack space)  

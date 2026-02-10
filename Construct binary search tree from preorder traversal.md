## Problem statement
- Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.
- It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.
- A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.
- A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.righ

### Solution
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int preIndex = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder, vector<int>& inorder,
                              unordered_map<int, int>& mp, int l, int r) {
        if (l > r) {
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[preIndex]);
        preIndex++;
        int ind = mp[node->val];
        node->left = bstFromPreorder(preorder, inorder, mp, l, ind - 1);
        node->right = bstFromPreorder(preorder, inorder, mp, ind + 1, r);

        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        unordered_map<int, int> mp;
        int n = inorder.size();
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return bstFromPreorder(preorder, inorder, mp, 0, n - 1);
    }
};
```
- Time complexity: O(nlogn) (sorting) + O(N) (map) + O(n) (node creation) = O(nlogn)
- Space complexity: O(n) (inorder,map,recusrive stack space) = O(n)

### Solution
```cpp
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> st;
        st.push(root);

        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* newNode = new TreeNode(preorder[i]);
            if (st.top()->val > preorder[i]) {
                st.top()->left = newNode;
                st.push(newNode);
            }
            else {
                TreeNode* curr = st.top(); st.pop();
                while (!st.empty() && st.top()-> val < preorder[i]) {
                    curr = st.top();
                    st.pop();
                }
                curr->right = newNode;
                st.push(newNode);
            }
        }
        return root;
    }
};
```
- Time complexity: O(n) [As we iterate through every element in preorder only once]
- Space complexity: O(n) [Worst case, we do not pop out of the stack]

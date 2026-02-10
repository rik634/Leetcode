## Problem statement


### Solution
```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL || root==p || root==q)
        {
            return root;
        }
        TreeNode* l = lowestCommonAncestor(root->left,p,q);
        TreeNode* r = lowestCommonAncestor(root->right,p,q);
        if(l!=NULL && r!=NULL)
        {
            return root;
        }
        if(l!=NULL)
        {
            return l;
        }
        return r;

    }
};
```
- Time Complexity: O(N), where N is the number of nodes in the binary tree. In the worst case, we may need to traverse all nodes to find the LCA.
- Space Complexity: O(H), where H is the height of the binary tree. This is due to the recursive stack space used during the traversal. In the worst case, for a skewed tree, H can be equal to N, but for a balanced tree, H will be log(N).

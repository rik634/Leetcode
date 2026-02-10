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
- Time complexity: O(logn)
- Space complexity: O(logn)

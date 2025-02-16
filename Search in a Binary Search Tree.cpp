//level: Easy
//link:https://leetcode.com/problems/search-in-a-binary-search-tree/description/?envType=study-plan-v2&envId=leetcode-75
//solution

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        if(root==NULL)
        {
            return NULL;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            if(p->val==val)
            {
                return p;
            }
            if(p->val<val && p->right!=NULL)
            {
                q.push(p->right);
            }
            if(p->val>val && p->left!=NULL)
            {
                q.push(p->left);
            }
        }
        return NULL;
    }
};

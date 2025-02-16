//level: Easy
//link: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75
//solution

class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if(root==NULL)
        {
            return 0;
        }
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
};

//level:Medium
//Link:https://leetcode.com/problems/binary-tree-right-side-view/description/?envType=study-plan-v2&envId=leetcode-75
//solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
         vector<int> v;
          if(root==NULL)
          {
            return v;
          }
         
          queue<TreeNode*> q;
          q.push(root);
          while(!q.empty())
          {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                auto p=q.front();
                q.pop();
                if(i==(size-1))
                {
                    v.push_back(p->val);
                }
                if(p->left!=NULL)
                {
                    q.push(p->left);
                }
                if(p->right!=NULL)
                {
                    q.push(p->right);
                }
            }
          }
          return v;
    }
};

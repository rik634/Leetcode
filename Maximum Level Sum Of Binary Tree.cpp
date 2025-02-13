//level:medium
//link:https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/?envType=study-plan-v2&envId=leetcode-75
//solution

**
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
    int maxLevelSum(TreeNode* root) {
        
        if(root==NULL)
        {
            return -1;
        }
        long long mx=INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        long long sum;
        int index=1;
        int x=0;
        while(!q.empty())
        {
            int size = q.size();
            sum=0;
            for(int i=0;i<size;i++)
            {
                auto p=q.front();
                q.pop();
                sum+=p->val;
                if(p->left!=NULL)
                {
                    q.push(p->left);
                }
                if(p->right!=NULL)
                {
                    q.push(p->right);
                }
            }
            if(sum>mx)
            {
                mx=sum;
                x=index;
            }
            index++;
        }
        return x;
    }
};

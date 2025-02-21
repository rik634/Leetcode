//level: Medium
//link: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/
//solution

//Time Complexity: O(N^2) for FindElement function, and O(1) for find function
//space complexity: O(N)
class FindElements {
public:
    TreeNode* node=NULL;
    unordered_set<int> s;
    FindElements(TreeNode* root) {
        
        if(root!=NULL)
        {
            root->val=0;
            node=root;
        queue<TreeNode*> q;
        q.push(root);
        int n;
        while(!q.empty())
        {
            auto p= q.front();
            q.pop();
            s.insert(p->val);
            n=p->val;
            if(p->left!=NULL)
            {
                p->left->val = 2 * n + 1;
                q.push(p->left);
            }
            if(p->right!=NULL)
            {
                p->right->val = 2*n+2;
                q.push(p->right);
            }
        }
        }
        
    }
    
    bool find(int target) {
        
       if(s.find(target)!=s.end())
       {
        return true;
       }
       return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

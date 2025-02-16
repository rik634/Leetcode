//level: Medium
//link: https://leetcode.com/problems/number-of-provinces/description/?envType=study-plan-v2&envId=leetcode-75
//solution

class Solution {
public:
    void dfs(vector<int> adj[],vector<bool>& vis, int u)
    {
        vis[u]=true;
        for(auto v:adj[u])
        {
            if(vis[v]==false)
            {
                dfs(adj,vis,v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                count++;
                dfs(adj,vis,i);
            }
        }
        return count;
    }
};

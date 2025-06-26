// Level: Medium
// Link: https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
// Solution


class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st)
    {
        vis[node]=true;
        for(auto it:adj[node])
        {
            if(vis[it]==false)
            {
                dfs(it,adj,vis,st);
            }
        }
        st.push(node);
    }
    void dfs1(int node, vector<vector<int>>& adjT, vector<bool>& vis)
    {
        vis[node]=true;
        for(auto it:adjT[node])
        {
            if(vis[it]==false)
            {
                dfs1(it,adjT,vis);
            }
        }
       
    }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        //O(V)
        vector<bool> vis(n,false);
        //O(V)
        stack<int> st;
        
        // O(V+E)
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                dfs(i,adj,vis,st);
            }
        }
        // reverse the edges
        //O(V+E)
        vector<vector<int>> adjT(n);
        for(int i=0;i<n;i++)
        {
            vis[i]=false;
            for(auto it:adj[i])
            {
                adjT[it].push_back(i);
            }
        }
        
        int count=0;
        //O(V+E)
        while(!st.empty())
        {
            int p = st.top();
            st.pop();
            if(vis[p]==false){
                count++;
                dfs1(p,adjT, vis);
            }
        }
        return count;
    }
};
// - Time Complexity: O(3*(V+E))
// - Space Complexity: O(V) + O(V) + O(V+E)

// Level: Medium
class Solution {
  private:
    int timer=1;
  private:
    bool dfs(int node, int parent, vector<bool>& vis, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low,int c, int d)
    {
        vis[node]=true;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node])
        {
            if(it==parent)
            {
                continue;
            }
            if(vis[it]==false)
            {
                if(dfs(it,node,vis,adj,tin,low,c,d)==true)
                {
                    return true;
                }
                low[node] = min(low[node],low[it]);
                if(low[it]>tin[node] && ((c==it && d==node) || (c==node && d==it)))
                {
                   return true;
                }
            }
            else
            {
                low[node]=min(low[node],low[it]);
            }
        }
        return false;
    }
  public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> vis(V,false);
        vector<int> tin(V,0);
        vector<int> low(V,0);
        vector<vector<int>> bridges;
       
        for(int i=0;i<V;i++)
        {
            if(dfs(i,-1,vis,adj,tin,low,c,d)==true)
            {
                return true;
            }
        }
        
        return false;
    }
};

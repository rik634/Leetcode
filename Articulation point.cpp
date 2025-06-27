// Level: hard
// Link:
// Solution
// User function Template for C++

class Solution {
private:
    int timer=0;
private:
    void dfs(int node, int parent, vector<bool>& vis, vector<int> adj[], vector<int>& tin, vector<int>& low, vector<int>& mark)
    {
        vis[node]=true;
        tin[node]=low[node]=timer;
        timer++;
        int child=0;
        for(auto it: adj[node])
        {
            if(it==parent)
            {
                continue;
            }
            if(vis[it]==false)
            {
                dfs(it,node,vis,adj,tin,low,mark);
                low[node]=min(low[node],low[it]);
                if(low[it]>=tin[node] && parent!=-1)
                {
                    mark[node]=1;
                }
                child++;
            }
            else
            {
                low[node]=min(low[node],tin[it]);
            }
            
        }
        if(child>1 && parent==-1)
        {
            mark[node]=1;
        }
        
    }
public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V,false);
        vector<int> tin(V,0);
        vector<int> low(V,0);
        vector<int> mark(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==false)
            {
                dfs(i,-1,vis,adj,tin,low,mark);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(mark[i]==1)
            {
                ans.push_back(i);
            }
        }
        if(ans.size()==0)
        {
            return {-1};
        }
        return ans;
    }
};
// Time Complexity: O(V+2E) (DFS)
// Space Complexity: O(3V)

// Level: Hard
// Link: https://leetcode.com/problems/critical-connections-in-a-network/description/
// Solution
class Solution {
private:
    int timer=1;
private:
    void dfs(int node, int parent, vector<bool>& vis, vector<vector<int>>& adj, vector<int>& low, vector<int>& tin,  vector<vector<int>>& bridges)
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
                dfs(it,node,vis,adj,low,tin,bridges);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node])
                {
                    bridges.push_back({it,node});
                }
            }
            else
            {
                // it is alredy visites, part of the component, if we remove that edge, it is still reachable
                low[node]=min(low[node],low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        // create graph from the connection
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++)
        {
            // undirected graph
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        // for DFS, we will need
        vector<bool> vis(n,false);
        vector<int> tin(n,0);
        vector<int> low(n,0);
        // to store the bridges
        vector<vector<int>> bridges;
        dfs(0,-1,vis,adj,low,tin,bridges);
        return bridges;
    }
};
// Time Complexity: O(V+2E)
// Space Complexity: O(V+2E) + O(3*V)

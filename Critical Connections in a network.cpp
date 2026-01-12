// Level: Hard
// Link: https://leetcode.com/problems/critical-connections-in-a-network/description/
// problem statement: There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through 
  //the network.A critical connection is a connection that, if removed, will make some servers unable to reach some other servers. Return all critical connections in the network in any order.
// Solution
class Solution {
public:
int time=0;
    void dfs(int u, int parent,vector<int>& low, vector<int>& disc, vector<int> adj[],vector<vector<int>>& bridges)
    {
        time++;
        low[u]=disc[u]=time;

        for(auto v:adj[u])
        {
            if(v==parent)
            {
                continue;
            }
            if(disc[v]==-1)
            {
                dfs(v,u,low,disc,adj,bridges);
                low[u]=min(low[u],low[v]);
                if(low[v]>disc[u])
                {
                    bridges.push_back({u,v});
                }
            }
            else
            {
                low[u]=min(low[u],disc[v]);
            }

        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> bridges;
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> low(n,-1),disc(n,-1);

        dfs(0,-1,low,disc,adj,bridges);
        return bridges;
    }
};
// Time Complexity: O(V+2E) where V = no. of vertices, E = no. of edges. It is because the algorithm is just a simple DFS traversal.
// Space Complexity: O(V+2E) + O(2*V) where V = no. of vertices, E = no. of edges. O(V+2E) to store the graph in an adjacency list and O(2V) for the two arrays i.e. tin, low,  each of size V.

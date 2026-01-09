// Algorithm
// problem statement: Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertices from the source vertex S. 
//Note: If the Graph contains a negative cycle then return an array consisting of only -1.

// brute force (Edge List):
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,1e8);
        dist[src]=0;
        for(int i=0;i<(V-1);i++)
        {
            for(auto it:edges)
            {
                int u = it[0];
                int v =it[1];
                int w =it[2];
                if(dist[u]!=1e8 && (dist[u]+w)<dist[v])
                {
                    dist[v]=w+dist[u];
                }
            }
        }
        for(auto it: edges)
        {
            int u = it[0];
            int v =it[1];
            int w =it[2];
            if(dist[u]!=1e8 && (dist[u]+w)<dist[v])
            {
                return {-1};
            }
        }
        return dist;
    }
};

// Time complexity: O(V*E)
// Space complexity: O(V)


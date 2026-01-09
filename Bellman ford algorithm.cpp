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

// basic optimization (early termination)
//In many real-world graphs, shortest paths are found in fewer than \(V-1\) iterations. We add a changed flag to stop if no updates occurred in a full pass

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,1e8);
        dist[src]=0;
        for(int i=0;i<(V-1);i++)
        {
            bool changed=false;
            for(auto it:edges)
            {
                int u = it[0];
                int v =it[1];
                int w =it[2];
                if(dist[u]!=1e8 && (dist[u]+w)<dist[v])
                {
                    dist[v]=w+dist[u];
                    changed=true;
                }
            }
            if(changed==false)
            {
                return dist;
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
// Time Complexity: \(O(V\times E)\) worst-case, but often much closer to \(O(E)\) on average. 
// space complexity: O(V)

// Professional Optimization: The Shortest Path Faster Algorithm (SPFA)
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<pair<int,int>> adj[V];
        for(auto it:edges) {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(V,1e8);
        queue<int> q;
        vector<bool> inQueue(V,false);
        vector<int> count(V,0);
        
        dist[src]=0;
        inQueue[src]=true;
        q.push(src);
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            inQueue[p]=false;
            
            for(auto it:adj[p]){
                if((dist[p]+it.second)<dist[it.first]){
                    dist[it.first]=dist[p]+it.second;
                    if(inQueue[it.first]==false){
                        count[it.first]++;
                        if(count[it.first]>=V){
                            return {-1};
                        }
                        q.push(it.first);
                        inQueue[it.first]=true;
                    }
                }
            }
        }
        return dist;
    }
};

// Time complexity: O(k*E) (average case), O(V*E) (worst case) (k=is a small constant (usually k~=2) 
// Space complexity: O(V+E)

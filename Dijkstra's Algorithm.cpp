// problem statement: Given a weighted, undirected, and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is an edge between i and j, second integers corresponds to the weight of that edge. 
//You are given the source vertex S and You have to Find the shortest distance of all the vertex from the source vertex S. 
//You have to return a list of integers denoting the shortest distance between each node and Source vertex S.
//Note: The Graph doesn’t contain any negative weight cycle

// brute force (using array):
// This method/ way is optimal for dense graph
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
      vector<pair<int,int>> adj[V];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int> dist(V,INT_MAX);
        vector<bool> vis(V,false);
        dist[src]=0;
        for(int i=0;i<V;i++) {
            int u=-1;
            for(int v=0;v<V;v++){
                if(vis[v]==false && (u==-1 || dist[v]<dist[u])){
                    u=v;
                }
            }
            if(dist[u]==INT_MAX){
                break;
            }
            for(auto it:adj[u]){
                int v = it.first;
                int wt = it.second;
                if((dist[u]+wt)<dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
            vis[u]=true;
        }
        for(auto it:dist){
            if(it==INT_MAX){
                it=-1;
            }
        }
        return dist;
    }
};
// Time complexity: O(E) (adjacency list creation) + O(V*(V+E))  = O(E+V^2+VE) = O(V*V) 
// Space complexity: O(V+2E) (adj) + O(V) (vis) + O(V) (dist) = O(V+E)

// standard optimizaion (priority queue)
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int,int>> adj[V];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int> dist(V,INT_MAX);
        dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({dist[src],src});
        
        while(!q.empty()){
            auto p = q.top();
            q.pop();
            int d = p.first;
            int u = p.second;  
             // Important: Skip outdated entries
            if (d > dist[u]) continue;  
            for(auto it:adj[u]) {
                int v = it.first;
                int dd = it.second;
                if((dist[u]+dd)<dist[v]){
                    dist[v]=dist[u]+dd;
                    q.push({dist[v],v});
                }
            }
        }
        for(auto it:dist) {
            if(it==INT_MAX){
                it=-1;
            }
        }
        return dist;
    }
};
// max number of elemtns in priority queue at a time is E. so, for each push/pop operations, time complexity if O(logE). we perform this operations total of E times in worst case. so, O(ElogE). As, E<=V^2. so, O(ElogE) = O(Elog(V*V)) = O(ElogV)
// Time complexity: O(E) (adj creation)  + O(ElogV) = O(ElogV)
// space complexity: O(V+E) (adj) + O(V) (dist) + O(E) (priority queue) = O(V+E)


// further optimized (using set)
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int,int>> adj[V];
        for(int i=0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int> dist(V,INT_MAX);
        dist[src]=0;
        set<pair<int,int>> st;
        st.insert({dist[src],src});
        while(!st.empty()) {
            int d = st.begin()->first;
            int u = st.begin()->second;
            st.erase(st.begin());
            for(auto it:adj[u]){
                int v = it.first;
                int wt = it.second;
                if((dist[u]+wt)<dist[v]){
                    if(dist[v]!=INT_MAX){
                        st.erase({dist[v],v});
                    }
                    dist[v]=dist[u]+wt;
                    st.insert({dist[v],v});
                }
            }
        }
        for(auto it:dist){
            if(it==INT_MAX){
                it=-1;
            }
        }
        return dist;
    }
};
// Unlike the lazy priority_queue approach (which can grow to size $E$), the set version never exceeds size $V$. This is because you erase the old distance before inserting the new one.
// so, every insert/erase opration takes O(logV). We do this for at most E edges. So, O(ElogV)
// Time complexity: O(E) (adj creation) + O(ElogV) + O(V) (dist) = O(ElogV)
// space complexity: O(V+E) (adj) + O(V) (set) + O(V) (dist) = O(V+E)

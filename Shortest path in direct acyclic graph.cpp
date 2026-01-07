// problem statement: iven a Directed Acyclic Graph of N vertices from 0 to N-1 and M edges and a 2D Integer array edges, where there is a directed edge from vertex edge[i][0] to vertex edge[i][1] with a distance of edge[i][2] for all i.
//Find the shortest path from source vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex. The source vertex is assumed to be 0.

// solution:
class Solution {
  private:
    // Helper function to perform DFS-based Topological Sort
    void topoSort(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st) {

      // Mark the current node as visited
      vis[node] = 1;

      // Traverse all adjacent nodes
      for (auto it : adj[node]) {

        // Get the target node from the pair
        int v = it.first;

        // If the node is not visited, call DFS on it
        if (!vis[v]) {
          topoSort(v, adj, vis, st);
        }
      }

      // Push the current node onto the stack after visiting all neighbors
      st.push(node);
    }

  public:
    // Function to find the shortest paths from node 0 to all other nodes
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {

      // Create adjacency list for the graph
      vector<pair<int, int>> adj[N];
      
      // Fill the adjacency list with edges
      for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        // Store (target node, weight)
        adj[u].push_back({v, wt});
      }

      // Initialize visited array to keep track of visited nodes
      int vis[N] = {0};

      // Stack to store the topological order
      stack<int> st;

      // Call topoSort for all unvisited nodes
      for (int i = 0; i < N; i++) {
        if (!vis[i]) {
          topoSort(i, adj, vis, st);
        }
      }

      // Initialize the distance vector with infinity
      vector<int> dist(N);
      for (int i = 0; i < N; i++) {
        dist[i] = 1e9;
      }

      // Distance to the source node (0) is 0
      dist[0] = 0;

      // Process all nodes in topological order
      while (!st.empty()) {
        int node = st.top();
        st.pop();

        // Relax all outgoing edges from the current node
        for (auto it : adj[node]) {
          int v = it.first;
          int wt = it.second;

          // Update distance if a shorter path is found
          if (dist[node] + wt < dist[v]) {
            dist[v] = wt + dist[node];
          }
        }
      }

      // Replace all unreachable nodes' distances with -1
      for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) {
          dist[i] = -1;
        }
      }

      // Return the final distance array
      return dist;
    }
};
//Time Complexity: O(N+M) {for the topological sort} + O(N+M) {for relaxation of vertices, each node and its adjacent nodes get traversed} ~ O(N+M),where N= number of vertices and M= number of edges.
//Space Complexity:  O(N) {for the stack storing the topological sort} + O(N) {for storing the shortest distance for each node} + O(N) {for the visited array} + O( N+2M) {for the adjacency list} ~ O(N+M) .

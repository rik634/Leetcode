// problem statement: Given an Undirected Graph having unit weight, find the shortest path from the source to all other nodes in this graph. 
//In this problem statement, we have assumed the source vertex to be ‘0’. If a vertex is unreachable from the source node, then return -1 for that vertex.

// solution:
class Solution {
public:
    // Function to find the shortest path from source to all vertices
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {

        // Create an adjacency list of size N to store the undirected graph
        vector<int> adj[N]; 
        // Build the graph by adding edges to the adjacency list
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        }
        // Initialize the distance array with a large value (treated as infinity)
        int dist[N];
        for (int i = 0; i < N; i++) 
            dist[i] = 1e9;
        // Set the source node distance to 0
        dist[src] = 0;
        // Use a queue to perform BFS traversal
        queue<int> q;
        // Start BFS from the source node
        q.push(src); 
        // Loop until queue is empty
        while (!q.empty()) {
            // Get the front node from the queue
            int node = q.front(); 
            q.pop(); 
            // Traverse all adjacent nodes
            for (auto it : adj[node]) {

                // If a shorter path to neighbor is found
                if (dist[node] + 1 < dist[it]) {
                    dist[it] = 1 + dist[node]; 
                    q.push(it); 
                }
            }
        }
        // Initialize the result array with -1 for unreachable nodes
        vector<int> ans(N, -1);

        // Fill in the result array with distances where reachable
        for (int i = 0; i < N; i++) {
            if (dist[i] != 1e9) {
                ans[i] = dist[i]; 
            }
        }
        // Return the final shortest distances
        return ans; 
    }
};
//Time Complexity: O(M) { for creating the adjacency list from given list ‘edges’} + O(N + 2M) { for the BFS Algorithm} + O(N) { for adding the final values of the shortest path in the resultant array} ~ O(N+2M). Where N= number of vertices and M= number of edges.
//Space Complexity:  O(N) {for the stack storing the BFS} + O(N) {for the resultant array} + O(N) {for the dist array storing updated shortest paths} + O( N+2M) {for the adjacency list} ~ O(N+M),Where N= number of vertices and M= number of edges.

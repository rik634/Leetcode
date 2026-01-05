// problem statement:

// solution (BFS)
class Solution {
public:
    // Function to count connected components in an undirected graph
    int countComponents(int V, vector<vector<int>>& edges) {
        
        // Create adjacency list from edge list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Vector to keep track of visited nodes
        vector<int> visited(V, 0);
        
        // Variable to count the number of connected components
        int components = 0;

        // Traverse all nodes in the graph
        for (int i = 0; i < V; ++i) {

            // If the node is not visited, it's a new component
            if (!visited[i]) {
                components++;

                // Start BFS from this node
                queue<int> q;
                q.push(i);
                visited[i] = 1;

                // Perform BFS traversal
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    // Visit all unvisited neighbors
                    for (auto &nbr : adj[node]) {
                        if (!visited[nbr]) {
                            visited[nbr] = 1;
                            q.push(nbr);
                        }
                    }
                }
            }
        }

        // Return the total number of connected components
        return components;
    }
};
//Time Complexity: O(V+E),Each vertex is visited exactly once, and each edge is processed at most twice (once from each end).
//Space Complexity: O(V+E), To build Adjacency List.

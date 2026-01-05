// Algorithm

// code:

class Solution {
public:
    // Function to perform DFS traversal
    void dfs(int v, vector<int> adj[], 
             vector<int>& visited, 
             vector<int>& result) {
        
        // Mark current node as visited
        visited[v] = 1;

        // Store node in result
        result.push_back(v);

        // Traverse all neighbours
        for (int u : adj[v]) {
            if (!visited[u]) {
                dfs(u, adj, visited, result);
            }
        }
    }
};

// Time Complexity: O(V+E), each vertex is visited once and every edge is checked once in the adjacency list.
//Space Complexity: O(V) , additional amount of space required for recursion stack.

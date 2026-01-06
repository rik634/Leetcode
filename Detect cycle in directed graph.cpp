// problem statement: 

// DFS:
class Solution {
private:
	bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
		vis[node] = 1;
		pathVis[node] = 1;

		// traverse for adjacent nodes
		for (auto it : adj[node]) {
			// when the node is not visited
			if (!vis[it]) {
				if (dfsCheck(it, adj, vis, pathVis) == true)
					return true;
			}
			// if the node has been previously visited
			// but it has to be visited on the same path
			else if (pathVis[it]) {
				return true;
			}
		}

		pathVis[node] = 0;
		return false;
	}
public:
	// Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) {
		int vis[V] = {0};
		int pathVis[V] = {0};

		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				if (dfsCheck(i, adj, vis, pathVis) == true) return true;
			}
		}
		return false;
	}
};

// Time Complexity: O(V+E)+O(V) , where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity.
// Space Complexity: O(2N) + O(N) ~ O(2N): O(2N) for two visited arrays and O(N) for recursive stack space.

// BFS (Kahn's algorithm/ topological sort)
class Solution {
public:
    // Function to detect a cycle in a directed graph
    bool isCyclic(int V, vector<vector<int>>& adj) {
        // Initialize indegree array to store incoming edges count
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto &nbr : adj[i]) {
                indegree[nbr]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for (auto &nbr : adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        // If processed node count is not equal to total nodes, a cycle exists
        return count != V;
    }
};
//Time Complexity: O(V+E), Each vertex and edge is processed exactly once while calculating in-degrees and during the BFS traversal.
//Space Complexity: O(V+E), We store the adjacency list, an in-degree array and a queue.


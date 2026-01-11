// Algorithm
// problem statement: 

// Prism's Algorithm: 
// find the sum of all edge weights of the MST
class Solution{  
    public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int spanningTree(int V, vector<vector<int>> adj[])
	{
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> pq;
		vector<int> vis(V, 0);
		// {wt, node}
		pq.push({0, 0});
		int sum = 0;
		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int node = it.second;
			int wt = it.first;
			if (vis[node] == 1) continue;
			// add it to the mst
			vis[node] = 1;
			sum += wt;
			for (auto it : adj[node]) {
				int adjNode = it[0];
				int edW = it[1];
				if (!vis[adjNode]) {
					pq.push({edW, adjNode});
				}
			}
		}
		return sum;
	}
};
// Time Complexity: O(E*logE) + O(E*logE)~ O(E*logE), where E = no. of given edges.
  //The maximum size of the priority queue can be E so after at most E iterations the priority queue will be empty and the loop will end. Inside the loop, there is a pop operation that will take logE time. 
//This will result in the first O(E*logE) time complexity. Now, inside that loop, for every node, we need to traverse all its adjacent nodes where the number of nodes can be at most E. 
//If we find any node unvisited, we will perform a push operation and for that, we need a logE time complexity. So this will result in the second O(E*logE). 

//Space Complexity: O(E) + O(V), where E = no. of edges and V = no. of vertices. O(E) occurs due to the size of the priority queue and O(V) due to the visited array. If we wish to get the mst, we need an extra O(V-1) space to store the edges of the most.

// prim's algorihm (Find MST)
class Solution {
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    vector<pair<int,int>> spanningTree(int V, vector<vector<pair<int, int>>>& adj) {
        // 1. Priority Queue: stores {weight, node, parent}
        // Min-heap based on the first element (weight)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // 2. Visited array
        vector<bool> visited(V, false);
        // 3. sum variable
        int sum = 0;
        // 4. MST array to store edges (parent, node)
        vector<pair<int, int>> mstEdges;
        // Start from node 0 with weight 0 and parent -1
        pq.push({0, 0, -1});

        while (!pq.empty()) {
            // Pop the element with minimum edge weight
            auto top = pq.top();
            pq.pop();

            int wt = top[0];
            int node = top[1];
            int parent = top[2];
            // If node is already visited, skip it
            if (visited[node]) continue;
            // Mark node as visited
            visited[node] = true;
            // Add weight to total sum
            sum += wt;
            // If it's not the starting node, add the edge to MST array
            if (parent != -1) {
                mstEdges.push_back({parent, node});
            }
            // Iterate through adjacent nodes
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;
                // If the neighbor is not visited, push to PQ
                if (!visited[adjNode]) {
                    pq.push({edgeWt, adjNode, node});
                }
            }
        }
        return mstEdges;
    }
};
// Time complexity: O(ElogV)
// space complexity: O(V+E)


// Kruskal's Algorithm
class DisjointSet {
    /* To store the ranks, parents and 
    sizes of different set of vertices */
    vector<int> rank, parent, size;
    
public:

    // Constructor
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    // Function to find ultimate parent
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    // Function to implement union by rank
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    // Function to implement union by size
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// Solution class
class Solution{
public:

    // Function to get the sum of weights of edges in MST
    int spanningTree(int V, vector<vector<int>> adj[]) {   
        // To store the edges
        vector<pair<int, pair<int, int>>> edges;
        
        // Getting all edges from adjacency list
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int v = it[0]; // Node v
                int wt = it[1]; // edge weight
                int u = i; // Node u
                edges.push_back({wt, {u, v}});
            }
        }
        // Creating a disjoint set of V vertices
        DisjointSet ds(V);
        // Sorting the edges based on their weights
        sort(edges.begin(), edges.end());
        // To store the sum of edges in MST
        int sum = 0;      
        // Iterate on the edges
        for (auto it : edges) {
            int wt = it.first; // edge weight
            int u = it.second.first; // First node
            int v = it.second.second; // Second node
            
            // Join the nodes if not in the same set 
            if (ds.findUPar(u) != ds.findUPar(v)) {
                
                // Update the sum of edges in MST
                sum += wt;
                
                // Unite the nodes 
                ds.unionBySize(u, v);
            }
        }
        // Return the computed sum
        return sum;
    }
};
//Time Complexity: O(N + E) + O(E log E) + O(E * 4α * 2), where N = number of nodes and E = number of edges. O(N + E) for extracting edge information from the adjacency list. O(E log E) for sorting the array consisting of the edge tuples. 
   //Finally, we are using disjoint set operations inside a loop. The loop will continue for E times. Inside that loop, there are two disjoint set operations like findUPar() and UnionBySize(), each taking 4, so it will result in 4 * 2. That is why the last term O(E * 4 * 2) is added.

//Space Complexity: O(N) + O(N) + O(E) , where E = number of edges and N = number of nodes. O(E) space is taken by the array that we are using to store the edge information. 
   //In the disjoint set data structure, we are using two N-sized arrays (i.e., a parent and a size array, as we are using unionBySize() function; otherwise, a rank array of the same size if unionByRank() is used), which result in the first two terms O(N).

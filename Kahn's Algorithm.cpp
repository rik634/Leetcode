// problem statement: Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.
//Note: In topological sorting, node u will always appear before node v if there is a directed edge from node u towards node v(u -> v).

// solution:
lass Solution {
public:
    /* Function to return the topological
     sorting of given graph */
    vector<int> topoSort(int V, vector<int> adj[]) {
        
        vector<int> ans;
	    vector<int> inDegree(V, 0);
	    for(int i=0; i<V; i++) {
	        for(auto it : adj[i]) inDegree[it]++;
	    }
	    queue<int> q;
	    for(int i=0; i<V; i++) {
	        if(inDegree[i] == 0) q.push(i);
	    }
	    while(!q.empty()) {
	        int node = q.front();
	        ans.push_back(node);
	        q.pop();
	        // Traverse the neighbours
	        for(auto it : adj[node]) {    
	            // Decrement the in-degree
	            inDegree[it]--;       
	            /* Add the node to queue if 
	            its in-degree becomes zero */
	            if(inDegree[it] == 0) q.push(it);
	        }
	    }    
	    // Return the result
	    return ans;
    }
};
//Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph. We traverse each vertex and edge once.
//Space Complexity: O(V), where V is the number of vertices. We use an array to store the in-degrees and a queue for BFS.

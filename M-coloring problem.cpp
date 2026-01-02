// problem statement:  Given an undirected graph and a number m, determine if the graph can be colored with at most m colors such that no two adjacent vertices of the graph are colored with the same color.
/ Function to check if it is safe to assign a color to a node
bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
    for (int k = 0; k < n; k++) {
        // Check if adjacent node has the same color
        if (k != node && graph[k][node] == 1 && color[k] == col) {
            return false;
        }
    }
    return true;  // Safe to assign the color
}

// Recursive function to solve the coloring problem
bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
    // If all nodes are assigned colors, return true
    if (node == N) {
        return true;
    }

    // Try different colors for the node
    for (int i = 1; i <= m; i++) {
        if (isSafe(node, color, graph, N, i)) {
            color[node] = i;
            // Recursively check for the next node
            if (solve(node + 1, color, m, N, graph)) return true;
            color[node] = 0;  // Backtrack if the color assignment fails
        }
    }
    return false;  // If no solution is found
}

// Function to check if graph can be colored with m colors
bool graphColoring(bool graph[101][101], int m, int N) {
    int color[N] = { 0 };
    // Start solving from node 0
    if (solve(0, color, m, N, graph)) return true;
    return false;
}

//Time Complexity: O(m^N), where m is the number of colors and N is the number of nodes in the graph. This is because we try to color each node with m different colors, leading to an exponential time complexity in the worst case.
//Space Complexity: O(N), where N is the number of nodes in the graph. This is due to the recursion stack and the color array used to store the colors assigned to each node.

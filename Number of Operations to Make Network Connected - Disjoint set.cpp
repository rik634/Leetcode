// Level: Medium
// Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
// problem statement: You are given a graph with n vertices and m edges. You can remove one edge from anywhere and add that edge between any two vertices in one operation. 
   //Find the minimum number of operations that will be required to make the graph connected. If it is not possible to make the graph connected, return -1.

// logic: The goal is to connect $n$ computers. To connect $K$ separate components, you need at least $K-1$ edges.
// Solution
class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n, 0);
        size.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 0;
        }
    }
    int findParent(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    void unionBySize(int x, int y) {
        int pu = findParent(x);
        int pv = findParent(y);
        if (pu == pv) {
            return;
        }
        if (size[pu] <= size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        DisjointSet ds(n);
        int extra = 0;

        for (auto it : connections) {
            int a = it[0];
            int b = it[1];

            if (ds.findParent(a) == ds.findParent(b)) {
                extra++;
            } else {
                ds.unionBySize(a, b);
            }
        }

        int noOfComponents = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findParent(i) == i) {
                noOfComponents++;
            }
        }
        if (extra >= (noOfComponents - 1)) {
            return noOfComponents - 1;
        }
        return -1;
    }
};
// - Time Complexity: O(E*4*alpha) (To calculate the extra edges) + O(N*4*alpha) (To calculate the count of components) ~= O(E+N)
// - Space Complexity: O(2*N) (To store parent and size array)



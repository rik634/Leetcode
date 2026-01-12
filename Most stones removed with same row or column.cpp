// Level:Medium
// Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
// problem statement:

// logic: In this problem, it is clearly stated that a stone can be removed if it shares either the same row or the same column as another stone that has not been removed. 
     //So, we can assume that these types of stones, sharing either the same row or column, are connected and belong to the same group
     //If we carefully observe, for each group we can remove all the stones leaving one stone intact. 
     //Thus, we can conclude that at most we can remove (size of the group - 1) number of stones from a group as we need to leave one stone untouched for each group.
     // The fundamental idea is to treat rows and columns as nodes in a graph. If a stone exists at $(row, col)$, it acts as an edge connecting the row node to the column node.

// Solution

class DisjointSet {

public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
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
    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();

        int count = 0;
        int maxRow = 0;
        int maxCol = 0;
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> mp;
        // connect node row and node col by edge
        for (auto it : stones) {
            int row = it[0];
            int col = it[1] + maxRow + 1;
            ds.unionBySize(row, col);
            mp[row] = 1;
            mp[col] = 1;
        }
        // count number of components
        for (auto it : mp) {
            if (ds.findParent(it.first) == it.first) {
                count++;
            }
        }
        return n - count;
    }
};

//  Time complexity: O(N) + O(N*alpha*(N)) + O(2*N*alpha*(N)) =O(N*alpha(N))
// space complexity: O(2*N) = O(N)

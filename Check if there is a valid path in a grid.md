## Problem statement
- You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:
  1. 1 which means a street connecting the left cell and the right cell.
  2. 2 which means a street connecting the upper cell and the lower cell.
  3. 3 which means a street connecting the left cell and the lower cell.
  4. 4 which means a street connecting the right cell and the lower cell.
  5. 5 which means a street connecting the left cell and the upper cell.
  6. 6 which means a street connecting the right cell and the upper cell.

- You will initially start at the street of the upper-left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.
- Notice that you are not allowed to change any street.
- Return true if there is a valid path in the grid or false otherwise.

### Logic:
- Here, this problem involves the connectivity,and specifically static connectivity. So, this is related to graph, means, BFS, DFS or union find comes into picture.
- Note:If the entire graph is provided upfront in the problem (for example, this problem directly provides the grid through a 2D array grid), and we are then asked queries about connectivity (such as whether there exists a path from the start to the end), this is referred to as static connectivity.
- The opposite concept is dynamic connectivity, where graph updates and connectivity queries are interleaved. In other words, after a connectivity query, the graph may still be modified.

### Solution
```cpp
class Solution {
public:
    vector<vector<unordered_set<int>>> mp = {
        {},
        {{1, 4, 6}, {}, {1, 3, 5}, {}}, // left, up, right, down
        {{}, {2, 3, 4}, {}, {2, 5, 6}}, // 2
        {{1, 4, 6}, {}, {}, {2, 5, 6}}, // 3
        {{}, {}, {1, 3, 5}, {2, 5, 6}}, // 4
        {{1, 4, 6}, {2, 3, 4}, {}, {}}, // 5
        {{}, {2, 3, 4}, {1, 3, 5}, {}}  // 6
    };
    vector<int> dx = {0, -1, 0, 1};
    vector<int> dy = {-1, 0, 1, 0};
    bool hasValidPath(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        q.push({0, 0});
        vis[0][0] = true;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            if (x == m - 1 && y == n - 1) {
                return true;
            }

            for (int i = 0; i < 4; i++) {
                int r = x + dx[i];
                int c = y + dy[i];
                if (mp[grid[x][y]][i].size() == 0) {
                    continue;
                }
                if (r >= 0 && r < m && c >= 0 && c < n &&
                    mp[grid[x][y]][i].find(grid[r][c]) !=
                        mp[grid[x][y]][i].end() &&
                    vis[r][c] == false) {
                    q.push({r, c});
                    vis[r][c] = true;
                }
            }
        }
        return false;
    }
};
```
- Time complexity: O(m*n)
- Space complexity: O(m*n)

### Union find solution:
- In BFS/ DFS we are searching alll the 4 directions because, here we don't know where the exit is.
- In case of disjoint set/ union find, we are just gluing the pieces together. Here, checking all 4 directions would be like gluing the same 2 pieces together twice. So, it is enough to only check the right and down direction.

```cpp
class DisjointSet {
public:
    vector<int> parent;
    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findParent(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    void unionFind(int x, int y) {
        int px = findParent(x);
        int py = findParent(y);
        if (px != py) {
            parent[px] = py;
        }
    }
};
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        DisjointSet ds(m * n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // right
                if (j + 1 < n) {
                    int curr = grid[i][j];
                    int next = grid[i][j + 1];
                    if ((curr == 1 || curr == 4 || curr == 6) &&
                        (next == 1 || next == 3 || next == 5)) {
                        ds.unionFind(n * i + j, n * i + j + 1);
                    }
                }
                if (i + 1 < m) {
                    int curr = grid[i][j];
                    int next = grid[i + 1][j];
                    if ((curr == 2 || curr == 3 || curr == 4) &&
                        (next == 2 || next == 5 || next == 6)) {
                        ds.unionFind(n * i + j, n * (i + 1) + j);
                    }
                }
            }
        }
        return ds.findParent(0) == ds.findParent(m * n - 1);
    }
};
```
- Time complexity: O(m*n*alpha(m*n))  (grid processing: O(m*n), unionFind per edge: alpha(m*n)) alpha denotes the ackerman functions, which we get due to path compression during finding the parent of any node
- Space complexity: O(m*n)

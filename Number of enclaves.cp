// level: Medium
// problem statement: You are given an N x M binary matrix grid, where 0 represents a sea cell and 1 represents a land cell. 
//A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid. Find the number of land cells in the grid for which we cannot walk off the boundary of the grid in any number of moves..

// BFS:
class Solution {
public:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int total = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    total++;
                    if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                        vis[i][j] = true;
                        q.push({i, j});
                    }
                }
            }
        }
        int count = 0;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            count++;
            for (int i = 0; i < 4; i++) {
                int r = dx[i] + p.first;
                int c = dy[i] + p.second;
                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1 &&
                    vis[r][c] == false) {
                    vis[r][c] = true;
                    q.push({r, c});
                }
            }
        }
        return total - count;
    }
};
// Time complexity: O(n*m) + O(4*n*m)
// space complexity: O(n*m) (visited array) + O(n*m) (queue) = O(n*m)



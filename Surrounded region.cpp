// level: Medium
// problem statement: Given a matrix mat of size N x M where every element is either ‘O’ or ‘X’. Replace all ‘O’ with ‘X’ that is surrounded by ‘X’.
//An ‘O’ (or a set of ‘O’) is considered to be surrounded by ‘X’ if there are ‘X’ at locations just below, just above just left, and just right of it.

// BFS:
class Solution {
public:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) &&
                    board[i][j] == 'O') {
                    board[i][j] = '#';
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int r = dx[i] + p.first;
                int c = dy[i] + p.second;
                if (r >= 0 && r < m && c >= 0 && c < n && board[r][c] == 'O') {
                    board[r][c] = '#';
                    q.push({r, c});
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
// Time complexity: O(m*n) + O(n*m) + O(n*m*4) 
// space complexity: O(n*m) (queue)

// DFS:
class Solution {
private:
    // DFS to mark boundary-connected 'O's as visited
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& mat, int delrow[], int delcol[]) {
        // mark current cell visited
        vis[row][col] = 1;
        // cache dimensions
        int n = mat.size(), m = mat[0].size();
        // try 4 directions
        for (int k = 0; k < 4; k++) {
            // compute next cell
            int nrow = row + delrow[k], ncol = col + delcol[k];
            // check bounds and unvisited 'O'
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
                // continue DFS
                dfs(nrow, ncol, vis, mat, delrow, delcol);
            }
        }
    }

public:
    // Flip all 'O' not connected to boundary to 'X'
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
        // handle empty matrix
        if (n == 0 || m == 0) return mat;
        // direction arrays for 4-neighbors
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        // visited matrix
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // traverse first and last row
        for (int j = 0; j < m; j++) {
            // start DFS from unvisited boundary 'O' (top row)
            if (!vis[0][j] && mat[0][j] == 'O') dfs(0, j, vis, mat, delrow, delcol);
            // start DFS from unvisited boundary 'O' (bottom row)
            if (!vis[n - 1][j] && mat[n - 1][j] == 'O') dfs(n - 1, j, vis, mat, delrow, delcol);
        }

        // traverse first and last column
        for (int i = 0; i < n; i++) {
            // start DFS from unvisited boundary 'O' (left col)
            if (!vis[i][0] && mat[i][0] == 'O') dfs(i, 0, vis, mat, delrow, delcol);
            // start DFS from unvisited boundary 'O' (right col)
            if (!vis[i][m - 1] && mat[i][m - 1] == 'O') dfs(i, m - 1, vis, mat, delrow, delcol);
        }

        // flip all unvisited 'O' to 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // convert enclosed 'O' to 'X'
                if (!vis[i][j] && mat[i][j] == 'O') mat[i][j] = 'X';
            }
        }

        // return updated board
        return mat;
    }
};
//Time Complexity: O(N × M), since each cell is visited at most once during DFS and once during the final traversal.
//Space Complexity: O(N × M), due to the visited matrix and the recursion stack in the worst case.

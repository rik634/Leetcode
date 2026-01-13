// level: Medium
// problem statement:

// recursion:
class Solution {
public:
    int f(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 || y < 0) {
            return 1e8;
        }
        if (x == 0 && y == 0) {
            return grid[0][0];
        }

        int up = grid[x][y] + f(x - 1, y, grid);
        int left = grid[x][y] + f(x, y - 1, grid);
        return min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        return f(m - 1, n - 1, grid);
    }
};
// Time complexity; O(2^(m+n))
// space complexity: O(m+n) (recursive stack space)

// memoization
class Solution {
public:
    int f(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (x < 0 || y < 0) {
            return 1e8;
        }
        if (x == 0 && y == 0) {
            return dp[x][y] = grid[0][0];
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        int up = grid[x][y] + f(x - 1, y, grid, dp);
        int left = grid[x][y] + f(x, y - 1, grid, dp);
        return dp[x][y] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, grid, dp);
    }
};
// Time complexity: O(m*n)
// space coplexity: O(m*n) (dp) + O(m+n) (recursive stack space)

// tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1e8));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                } else {
                    int up = grid[i][j];
                    if (i > 0)
                        up += dp[i - 1][j];
                    else
                        up += 1e9;

                    int left = grid[i][j];
                    if (j > 0)
                        left += dp[i][j - 1];
                    else
                        left += 1e9;

                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
// Time complexity: O(m*n)
// space complexity: O(m*n)


// space optimzied
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
       
        vector<int> prev(n,1e9);
        for (int i = 0; i < m; i++) {
            vector<int> temp(n,1e9);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    temp[j] = grid[i][j];
                } else {
                    int up = grid[i][j];
                    if (i > 0)
                        up += prev[j];
                    else
                        up += 1e9;

                    int left = grid[i][j];
                    if (j > 0)
                        left += temp[j - 1];
                    else
                        left += 1e9;

                    temp[j] = min(up, left);
                }
            }
            prev=temp;
        }
        return prev[n - 1];
    }
};
// Time complexity: O(m*n)
// space complexity: O(n)

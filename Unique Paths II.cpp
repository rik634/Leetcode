// level: Medium
// problem statement:

// recursion
class Solution {
public:
    int f(int x, int y, vector<vector<int>>& obstacleGrid) {
        if (x < 0 || y < 0 || obstacleGrid[x][y] == 1) {
            return 0;
        }

        if (x == 0 && y == 0) {
            return 1;
        }

        int up = f(x - 1, y, obstacleGrid);
        int left = f(x, y - 1, obstacleGrid);
        return up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        return f(m - 1, n - 1, obstacleGrid);
    }
};
// Time complexity: O(2^(m+n))
// Space complexity: O(m+n) (recursive stack space)

// memoization
class Solution {
public:
    int f(int x, int y, vector<vector<int>>& obstacleGrid,
          vector<vector<int>>& dp) {
        if (x < 0 || y < 0 || obstacleGrid[x][y] == 1) {
            return 0;
        }

        if (x == 0 && y == 0) {
            return dp[x][y] = 1;
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        int up = f(x - 1, y, obstacleGrid, dp);
        int left = f(x, y - 1, obstacleGrid, dp);
        return dp[x][y] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, obstacleGrid, dp);
    }
};
// Time complexity: O(m*n)
// space complexity: O(m*n) + o(m+n) (recursive stack space)

// tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 1) {
                break;
            }
            dp[0][i] = 1;
        }
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1) {
                break;
            }
            dp[i][0] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
// Time complexity: O(m*n)
// space complexity: O(m*n)

// space optimized
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }

        vector<int> prev(n, 0);
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 1) {
                break;
            }
            prev[i] = 1;
        }

        for (int i = 1; i < m; i++) {
            vector<int> temp(n, 0);
            if (prev[0] == 1 && obstacleGrid[i][0] == 0) {
                temp[0] = 1;
            }
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    temp[j] = 0;
                } else {
                    temp[j] = prev[j] + temp[j - 1];
                }
            }
            prev = temp;
        }
        return prev[n - 1];
    }
};
// Time complexity: O(m*n)
// space complexity: O(n)

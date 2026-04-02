## Problem statement
- You are given an m x n grid. A robot starts at the top-left corner of the grid (0, 0) and wants to reach the bottom-right corner (m - 1, n - 1). The robot can move either right or down at any point in time.
- The grid contains a value coins[i][j] in each cell:
  1. If coins[i][j] >= 0, the robot gains that many coins.
  2. If coins[i][j] < 0, the robot encounters a robber, and the robber steals the absolute value of coins[i][j] coins.
- The robot has a special ability to neutralize robbers in at most 2 cells on its path, preventing them from stealing coins in those cells.
- Note: The robot's total coins can be negative.
- Return the maximum profit the robot can gain on the route.

### Brute force
```cpp
class Solution {
public:
    int checkMax(int i, int j, vector<vector<int>>& coins, int k, int& m,
                 int& n) {
        if (i >= m || j >= n) {
            return INT_MIN;
        }
        if (i == m - 1 && j == n - 1) {
            return (coins[i][j] < 0 && k > 0) ? 0 : coins[i][j];
        }
        int right = coins[i][j] + max(checkMax(i, j + 1, coins, k, m, n),
                                      checkMax(i + 1, j, coins, k, m, n));
        int down = INT_MIN;
        if (coins[i][j] < 0 && k > 0) {
            down = max(checkMax(i, j + 1, coins, k - 1, m, n),
                       checkMax(i + 1, j, coins, k - 1, m, n));
        }
        return max(right, down);
    }
    int maximumAmount(vector<vector<int>>& coins) {

        int m = coins.size();
        int n = coins[0].size();
        return checkMax(0, 0, coins, 2, m, n);
    }
};
```
- Time complexity: O((3^k)*(2^(m+n))) (The Path: To get from (0, 0) to (m-1, n-1), you must take exactly (m + n - 2) steps. In a simple grid traversal, this usually results in 2^{m+n} paths., The "k" Factor: At each cell where a coin is negative, you have an additional choice: use one of your k neutralizers or don't. While $k$ is small (k=2), it still adds significant branching. )
- Space complexity: O(m+n)

### Memoization
```cpp
class Solution {
public:
    int checkMax(int i, int j, vector<vector<int>>& coins, int k, int& m,
                 int& n, vector<vector<vector<int>>>& dp) {
        if (i >= m || j >= n) {
            return -1e9;
        }
        if (i == m - 1 && j == n - 1) {
            return (coins[i][j] < 0 && k > 0) ? 0 : coins[i][j];
        }
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        int right = coins[i][j] + max(checkMax(i, j + 1, coins, k, m, n, dp),
                                      checkMax(i + 1, j, coins, k, m, n, dp));
        int down = INT_MIN;
        if (coins[i][j] < 0 && k > 0) {
            down = max(checkMax(i, j + 1, coins, k - 1, m, n, dp),
                       checkMax(i + 1, j, coins, k - 1, m, n, dp));
        }
        return dp[i][j][k] = max(right, down);
    }
    int maximumAmount(vector<vector<int>>& coins) {

        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(3, -1)));
        return checkMax(0, 0, coins, 2, m, n, dp);
    }
};
```
- Time complexity: O(m*n*3)
- Space complexity; o(m*n*3)

### Tabulation
```cpp
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {

        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(3, -1e9)));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int k = 0; k < 3; k++) {
                    if (i == m - 1 && j == n - 1) {
                        dp[i][j][k] =
                            (coins[i][j] < 0 && k > 0) ? 0 : coins[i][j];
                    } else {
                        // Path without neutralizing current cell
                        int moveDown = (i + 1 < m) ? dp[i + 1][j][k] : -1e9;
                        int moveRight = (j + 1 < n) ? dp[i][j + 1][k] : -1e9;
                        int take = coins[i][j] + max(moveDown, moveRight);

                        // 2. Path with neutralizing current cell (if negative
                        // and k > 0)
                        int skip = -1e9;
                        if (coins[i][j] < 0 && k > 0) {
                            int moveDownK =
                                (i + 1 < m) ? dp[i + 1][j][k - 1] : -1e9;
                            int moveRightK =
                                (j + 1 < n) ? dp[i][j + 1][k - 1] : -1e9;
                            skip = 0 + max(moveDownK, moveRightK);
                        }

                        dp[i][j][k] = max(take, skip);
                    }
                }
            }
        }
        return dp[0][0][2];
    }
};
```
- Time complexity: O(m*n)
- Space complexity: O(m*n)

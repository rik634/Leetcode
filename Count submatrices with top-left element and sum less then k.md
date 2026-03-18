## Problem statement
- You are given a 0-indexed integer matrix grid and an integer k.
- Return the number of submatrices that contain the top-left element of the grid, and have a sum less than or equal to k.

### Brute force
```cpp
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        int count = 0;
        dp[0][0] = grid[0][0];
        if (dp[0][0] <= k) {
            count = 1;
        }
        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
            if (dp[0][i] <= k) {
                count++;
            } 
        }
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
            if (dp[i][0] <= k) {
                count++;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] =
                    dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + grid[i][j];
                if (dp[i][j] <= k) {
                    count++;
                } 
                else
                {
                    break;
                }
            }
        }
        return count;
    }
};
```
- Time complexity: O(n) + O(m) + O(n*m)
- Space complexity: O(n*m)

### Space optimized
```cpp
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, 0);
        int count = 0;
        prev[0] = grid[0][0];
        if (prev[0] <= k) {
            count = 1;
        }
        for (int i = 1; i < n; i++) {
            prev[i] = prev[i - 1] + grid[0][i];
            if (prev[i] <= k) {
                count++;
            }
        }

        for (int i = 1; i < m; i++) {
            vector<int> temp(n, 0);

            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    temp[0] = prev[0] + grid[i][0];
                    if (temp[0] <= k) {
                        count++;
                    }
                } else {
                    temp[j] = prev[j] + temp[j - 1] - prev[j - 1] + grid[i][j];
                    if (temp[j] <= k) {
                        count++;
                    } else {
                        break;
                    }
                }
            }
            prev = temp;
        }
        return count;
    }
};
```
- Time complexity: O(n*m)
- Space complexity: O(n)

### More space optimized
```cpp
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        if (grid[0][0] <= k) {
            count = 1;
        }
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i - 1][0];
            if (grid[i][0] <= k) {
                count++;
            }
        }
        for (int i = 1; i < n; i++) {
            grid[0][i] += grid[0][i - 1];
            if (grid[0][i] <= k) {
                count++;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] +=
                    (grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1]);
                if (grid[i][j] <= k) {
                    count++;
                }
            }
        }
        return count;
    }
};
```
- Time complexity: O(n*m)
- Space complexity: O(1)

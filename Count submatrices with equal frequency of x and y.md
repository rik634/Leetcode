## Problem statement
- Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:
  1. grid[0][0]
  2. an equal frequency of 'X' and 'Y'.
  3. at least one 'X'

### Solution
```cpp
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<pair<int, int>>> dp(m, vector<pair<int, int>>(n, {0, 0}));

        if (grid[0][0] == 'X') {
            dp[0][0] = {1, 0};
        } else if (grid[0][0] == 'Y') {
            dp[0][0] = {0, 1};
        }
        int x, y;

        for (int i = 1; i < n; i++) {
            x = dp[0][i - 1].first + ((grid[0][i] == 'X') ? 1 : 0);
            y = dp[0][i - 1].second + ((grid[0][i] == 'Y') ? 1 : 0);
            if (x == y && x >= 1) {
                count++;
            }
            dp[0][i] = {x, y};
        }

        for (int i = 1; i < m; i++) {
            x = dp[i - 1][0].first + ((grid[i][0] == 'X') ? 1 : 0);
            y = dp[i - 1][0].second + ((grid[i][0] == 'Y') ? 1 : 0);
            if (x == y && x >= 1) {
                count++;
            }
            dp[i][0] = {x, y};
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                x = grid[i][j] == 'X' ? 1 : 0;
                y = grid[i][j] == 'Y' ? 1 : 0;
                x += dp[i - 1][j].first + dp[i][j - 1].first -
                     dp[i - 1][j - 1].first;
                y += dp[i - 1][j].second + dp[i][j - 1].second -
                     dp[i - 1][j - 1].second;
                if (x == y && x >= 1) {
                    count++;
                }
                dp[i][j].first = x;
                dp[i][j].second = y;
            }
        }
        return count;
    }
};
```
- Time complexity: O(m*n)
- Space complexity: O(n*m)

### Space optimized
```cpp
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<int> colX(n, 0);
        vector<int> colY(n, 0);
        for (int i = 0; i < m; i++) {
            int rowX = 0;
            int rowY = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'X') {
                    rowX++;
                } else if (grid[i][j] == 'Y') {
                    rowY++;
                }
                colX[j] += rowX;
                colY[j] += rowY;
                if (colX[j] > 0 && colX[j] == colY[j]) {
                    count++;
                }
            }
        }
        return count;
    }
};
```
- Time complexity: O(n*m)
- Space complexity: O(n)

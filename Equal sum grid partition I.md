## Problem statement
- You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:
  1. Each of the two resulting sections formed by the cut is non-empty.
  2. The sum of the elements in both sections is equal.
- Return true if such a partition exists; otherwise return false

### Solution
```cpp
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        long long total = 0;
        vector<long long> row(m, 0);
        vector<long long> col(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }
        long long curr = 0;
        for (int i = 0; i < m - 1; i++) {
            curr += row[i];
            if ((long long)2 * curr == total) {
                return true;
            }
        }
        curr = 0;
        for (int i = 0; i < n - 1; i++) {
            curr += col[i];
            if ((long long)2 * curr == total) {
                return true;
            }
        }
        return false;
    }
};
```
- Time complexity: O(n*m)
- Space complexity: O(n+m)

### Space optimized
```cpp
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        long long total = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }
        if (total % 2 != 0) {
            return false;
        }
        long long target = total / 2;
        long long curr = 0;
        for (int i = 0; i < m - 1; i++) {

            for (int j = 0; j < n; j++) {
                curr += grid[i][j];
            }
            if (curr == target) {
                return true;
            }
        }
        curr = 0;
        for (int i = 0; i < n - 1; i++) {

            for (int j = 0; j < m; j++) {
                curr += grid[j][i];
            }

            if (curr == target) {
                return true;
            }
        }
        return false;
    }
};
```
- Time complexity: O(n*m)
- Space complexity: O(1)

## Problem statement
- You are given an m x n integer matrix grid and an integer k.
- For every contiguous k x k submatrix of grid, compute the minimum absolute difference between any two distinct values within that submatrix.
- Return a 2D array ans of size (m - k + 1) x (n - k + 1), where ans[i][j] is the minimum absolute difference in the submatrix whose top-left corner is (i, j) in grid.
- Note: If all elements in the submatrix have the same value, the answer will be 0.
- A submatrix (x1, y1, x2, y2) is a matrix that is formed by choosing all cells matrix[x][y] where x1 <= x <= x2 and y1 <= y <= y2.

### Solution
```cpp
class Solution {
public:
    int findMinDiff(int i, int j, int& k, vector<vector<int>>& grid) {
        set<int> res;
        for (int l = i; l < (i + k); l++) {
            for (int r = j; r < (j + k); r++) {
                res.insert(grid[l][r]);
            }
        }
        if (res.size() == 1) {
            return 0;
        }
        int mn = INT_MAX;
        int prev = 0;
        int ind = 0;
        for (auto it : res) {
            if (ind != 0) {
                mn = min(mn, abs(it - prev));
            }
            ind++;
            prev = it;
        }
        return mn;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[0].size(); j++) {
                ans[i][j] = findMinDiff(i, j, k, grid);
            }
        }
        return ans;
    }
};
```
- Time complexity: O((m-k)*(n--k)*k*k*log(k^2))
- Space complexity: O(k*k))

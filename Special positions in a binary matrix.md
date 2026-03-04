## Problem statement
- Given an m x n binary matrix mat, return the number of special positions in mat.
- A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

### Solution
```cpp
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, int> row;
        unordered_map<int, int> col;
        vector<pair<int, int>> v;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                    v.push_back({i, j});
                }
            }
        }
        int count = 0;
        for (int i = 0; i < v.size(); i++) {

            if ((row[v[i].first] == 1) && (col[v[i].second] == 1)) {
                count++;
            }
        }
        return count;
    }
};
```
- Time complexity: O(m*n)
- Space complexity: O(n+m) + O(n*m)

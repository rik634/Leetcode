## Problem statement
- You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
- You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

### Solution
```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int r = (n / 2) - 1;

        for (int i = 0; i <= r; i++) {          // row
            for (int j = i; j < n - i - 1; j++) // col
            {
                int a = matrix[i][j];
                int b = matrix[j][n - 1 - i];
                int c = matrix[n - 1 - j][i];
                int d = matrix[n - 1 - i][n - 1 - j];
                swap(matrix[i][j], matrix[n - 1 - j][i]);
                swap(matrix[j][n - 1 - i], matrix[n - 1 - i][n - 1 - j]);
                swap(matrix[j][n - 1 - i], matrix[n - 1 - j][i]);
            }
        }
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(1)

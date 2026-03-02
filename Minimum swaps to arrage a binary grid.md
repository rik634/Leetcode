## Problem statement
- Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.
- A grid is said to be valid if all the cells above the main diagonal are zeros.
- Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.
- The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).


### Solution
```cpp
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {

        int n = grid.size();
        vector<int> zero(n);
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) {
                count++;
            }
            zero[i] = count;
        }
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            int need = n - i - 1;
            int j = i;
            while (j < n && zero[j] < need) {
                j++;
            }
            if (j == n) {
                return -1;
            }
            while (j > i) {
                swap(zero[j], zero[j - 1]);
                j--;
                swaps++;
            }
        }
        return swaps;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n)

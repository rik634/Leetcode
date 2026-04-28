## Problem statement
- You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.
- A uni-value grid is a grid where all the elements of it are equal.
- Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1

### Logic:
- Here, we are assuming that the median will always minimize the number of operations
### Solution
```cp
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        int m = grid.size();
        int n = grid[0].size();
        if (m * n == 1) {
            return 0;
        }
        vector<int> nums;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                nums.push_back(grid[i][j]);
            }
        }

        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        int mid = nums[(nums.size() / 2)];
        int ops = 0;
        for (auto it : nums) {

            if (it % x != mid % x) {
                return -1;
            }
            ops += abs(it - mid) / x;
        }
        return ops;
    }
};
```
- Time complexity: O(m*n) (2d matrix) + O(m*n) (nth_eleemtn sort) = O(m*n)
- Space complexity: O(m*n)

### prefix and suffix sum
- Instead of assuming that the median will always minimize the number of operations, we will check each element to see if it can be the final common value for the grid.

```cpp
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        int m = grid.size();
        int n = grid[0].size();

        vector<int> nums;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] % x != grid[0][0] % x) {

                    return -1;
                }
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(), nums.end());
        int l = nums.size();
        vector<int> prefix(l, 0);
        vector<int> suffix(l, 0);

        for (int i = 1; i < l; i++) {

            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        for (int i = l - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + nums[i + 1];
        }

        int mn = INT_MAX;
        for (int i = 0; i < l; i++) {

            int left = (i * nums[i] - prefix[i]) / x;
            int right = (suffix[i] - (m * n - i - 1) * nums[i]) / x;
            mn = min(mn, left + right);
        }
        return mn;
    }
};
```
- Time complexity: O(mn*logmn)
- Space complexity: O(m*n)

### Two pointers
- In this approach, we don’t start by fixing the final common value of the grid. Instead, we take a gradual approach. We progressively make all elements equal by extending the prefix and suffix of the flattened array that already contain equal elements.

```cpp
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        int m = grid.size();
        int n = grid[0].size();

        vector<int> nums;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] % x != grid[0][0] % x) {

                    return -1;
                }
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(), nums.end());
        int res = 0;
        int l = 0;
        int r = nums.size() - 1;
        // Gradually move prefixIndex and suffixIndex towards the middle
        while (l < r) {
            // If the prefix of equal elements is shorter than the suffix
            if (l < (nums.size() - r - 1)) {
                // Calculate the number of operations required to extend the
                // prefix
                int prefix = (l + 1) * (nums[l + 1] - nums[l]) / x;
                res += prefix;
                // Move the prefix index forward
                l++;
            } else {
                // Calculate the number of operations required to extend the
                // suffix
                int suffix = (nums.size() - r) * (nums[r] - nums[r - 1]) / x;
                res += suffix;
                // Move the suffix index backward
                r--;
            }
        }
        return res;
    }
};
```
- Time complexity: O(mn*logmn)
- Space complexity: O(mn)

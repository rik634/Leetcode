## Problem statement
- You are given an integer array nums consisting only of 0, 1, and 2.
- A pair of indices (i, j) is called valid if nums[i] == 1 and nums[j] == 2.
- Return the minimum absolute difference between i and j among all valid pairs. If no valid pair exists, return -1.
- The absolute difference between indices i and j is defined as abs(i - j)

### Solution
```cpp
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {

        int mn = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {

                if ((nums[i] == 1 && nums[j] == 2) ||
                    (nums[i] == 2 && nums[j] == 1)) {
                    mn = min(mn, abs(i - j));
                }
            }
        }
        return mn == INT_MAX ? -1 : mn;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(1)

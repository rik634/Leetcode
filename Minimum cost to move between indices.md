## Problem statement
- You are given an integer array nums where nums is strictly increasing.
- For each index x, let closest(x) be the adjacent index such that abs(nums[x] - nums[y]) is minimized. If both adjacent indices exist and give the same difference, choose the smaller index.
- From any index x, you can move in two ways:
   - To any index y with cost abs(nums[x] - nums[y]), or
   - To closest(x) with cost 1.
- You are also given a 2D integer array queries, where each queries[i] = [li, ri].
- For each query, calculate the minimum total cost to move from index li to index ri.
- Return an integer array ans, where ans[i] is the answer for the ith query.
- The absolute difference between two values x and y is defined as abs(x - y).

### Solution
```cpp
class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();
        int m = queries.size();
        vector<int> closest(n, 0);
        closest[0] = 1;
        closest[n - 1] = n - 2;
        for (int i = 1; i < n - 1; i++) {
            int d1 = abs(nums[i - 1] - nums[i]);
            int d2 = abs(nums[i + 1] - nums[i]);
            if (d1 <= d2) {
                closest[i] = i - 1;
            } else {
                closest[i] = i + 1;
            }
        }
        vector<int> prefix(n, 0);
        for (int i = 1; i < n; i++) {
            if (closest[i - 1] == i) {
                prefix[i] = prefix[i - 1] + 1;
            } else {
                prefix[i] = prefix[i - 1] + abs(nums[i] - nums[i - 1]);
            }
        }
        vector<int> suffix(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            if (closest[i + 1] == i) {
                suffix[i] = suffix[i + 1] + 1;
            } else {
                suffix[i] = suffix[i + 1] + abs(nums[i + 1] - nums[i]);
            }
        }
        vector<int> res(m, 0);
        for (int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            if (l <= r) {
                res[i] = prefix[r] - prefix[l];
            } else {
                res[i] = suffix[r] - suffix[l];
            }
        }
        return res;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)

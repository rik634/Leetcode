## Problem statement


### Recursion
```cpp
class Solution {
public:
    void f(int ind, int& n, vector<int>& nums, vector<int> current,
           vector<int>& res) {
        if (ind == n) {
            if (current.size() > res.size()) {
                res = current;
            }
            return;
        }

        // consider the current index
        if (current.size() == 0 || nums[ind] % current.back() == 0) {
            current.push_back(nums[ind]);
            f(ind + 1, n, nums, current, res);
            current.pop_back();
        }
        // skip the current index
        f(ind + 1, n, nums, current, res);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> current;
        vector<int> res;
        f(0, n, nums, current, res);
        return res;
    }
};
```
- Time complexity: O(nlogn) + O(n*(2^n))
- Space complexity: O(n*n) (stack space+ time reqieurs to make vector copies for current vector)

### Optimized
```cpp
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> res;
        vector<int> prev(n, -1);
        int mx = -1;
        int ind = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > mx) {
                mx = dp[i];
                ind = i;
            }
        }

        while (prev[ind] != -1) {
            res.push_back(nums[ind]);
            ind = prev[ind];
        }
        res.push_back(nums[ind]);
        reverse(res.begin(), res.end());
        return res;
    }
};
```
- Time complexity: O(n*n)+ O(n)
- Space complexity: O(n)

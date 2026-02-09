## Problem statement
- 


### Brute force
```cpp
class Solution {
public:
    void solve(vector<int>& nums, int ind, int l1, int l2, int sum1, int sum2,
               int& mxDiff, int& n) {
        if (l1 > n || l2 > n) {
            return;
        }
        if (ind == nums.size() && l1 == n && l2 == n) {
            mxDiff = min(mxDiff, abs(sum1 - sum2));
            return;
        }
        solve(nums, ind + 1, l1 + 1, l2, sum1 + nums[ind], sum2, mxDiff, n);
        solve(nums, ind + 1, l1, l2 + 1, sum1, sum2 + nums[ind], mxDiff, n);
    }
    int minimumDifference(vector<int>& nums) {

        int m = nums.size();
        int n = m / 2;
        int l1 = 0;
        int l2 = 0;
        int sum1 = 0;
        int sum2 = 0;
        int ind = 0;
        int mxDiff = INT_MAX;
        solve(nums, ind, l1, l2, sum1, sum2, mxDiff, n);
        return mxDiff;
    }
};
```
- Time complexity: O(2^m)
- Space complexity: O(n) (recursive stack space)


### Better
```cpp
class Solution {
public:
    int minimumDifference(vector<int>& nums) {

        int m = nums.size();
        int n = m / 2;
        vector<vector<int>> left(n + 1);
        vector<vector<int>> right(n + 1);

        int sum = accumulate(nums.begin(), nums.end(), 0);

        // find all possible subset sums
        for (int mask = 0; mask < (1 << n); mask++) {
            int count = 0;
            int leftSum = 0;
            int rightSum = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    count++;
                    leftSum += nums[i];
                    rightSum += nums[i + n];
                }
                
            }
            left[count].push_back(leftSum);
            right[count].push_back(rightSum);
        }

        // sort the right index for binary search
        for (int i = 0; i <= n; i++) {
            sort(right[i].begin(), right[i].end());
        }
        int res = min(abs(sum - 2 * left[n][0]), abs(sum - 2 * right[n][0]));

        for (int k = 1; k < n; k++) {
            for (auto a : left[k]) {
                int b = (sum - 2 * a) / 2;
                int l = n - k;
                auto&  v = right[l];
                auto itr = lower_bound(v.begin(), v.end(), b);
                if (itr != v.end()) {
                    res = min(res, abs(sum - 2 * (a + *itr)));
                }
            }
        }
        return res;
    }
};
```
- Time complexity: O((2^n)*(log(2^n))) = O(n*(2^n))
- Space cpomplexity: O(n2^n)(storage)


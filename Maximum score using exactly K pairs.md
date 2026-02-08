## Problem statement
- You are given two integer arrays nums1 and nums2 of lengths n and m respectively, and an integer k.
- You must choose exactly k pairs of indices (i1, j1), (i2, j2), ..., (ik, jk) such that:
  0 <= i1 < i2 < ... < ik < n
  0 <= j1 < j2 < ... < jk < m
- For each chosen pair (i, j), you gain a score of nums1[i] * nums2[j].
- The total score is the sum of the products of all selected pairs.
- Return an integer representing the maximum achievable total score.
- Note: Please do not copy the description during the contest to maintain the integrity of your submissions.

### Solution
```cpp
class Solution {
public:
    long long f(int ind1, int ind2, vector<int>& nums1, vector<int>& nums2,
                int k, vector<vector<vector<long long>>>& dp) {
        if (k == 0) {
            return 0;
        }
        if (ind1 < 0 || ind2 < 0) {
            return -1e15;
        }
        if (dp[ind1][ind2][k] != -2e18) {
            return dp[ind1][ind2][k];
        }
        // take current
        long long both = (long long)nums1[ind1] * nums2[ind2];
        long long rem = f(ind1 - 1, ind2 - 1, nums1, nums2, k - 1, dp);
        long long take = rem < -1e15 ? -1e15 : both + rem;

        long long left = f(ind1 - 1, ind2, nums1, nums2, k, dp);

        long long right = f(ind1, ind2 - 1, nums1, nums2, k, dp);

        return dp[ind1][ind2][k] = max(take, max(left, right));
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        int n = nums1.size();
        int m = nums2.size();

        long long uncomputed = -2e18;

        vector<vector<vector<long long>>> dp(
            n + 1, vector<vector<long long>>(
                       m + 1, vector<long long>(k + 1, uncomputed)));

        return f(n - 1, m - 1, nums1, nums2, k, dp);
    }
};
```
- Time complexity: O(n*m*k)
- Space complexigty: O(n*m*k) + O(m+n)

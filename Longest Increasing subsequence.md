## Problem statement
- Given an integer array nums, return the length of the longest strictly increasing subsequence.
- A subsequence is a sequence derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3, 6, 2, 7] is a subsequence of [0, 3, 1, 6, 2, 2, 7].
- The task is to find the length of the longest subsequence in which every element is greater than the previous one.

### Recursion
```cpp
class Solution {
public:
    int f(int ind, int prev, int& n, vector<int>& nums) {
        if (ind == n) {
            return 0;
        }
        int notTake = f(ind + 1, prev, n, nums);
        int take = 0;
        if (prev == -1 || nums[ind] > nums[prev]) {
            take = 1 + f(ind + 1, ind, n, nums);
        }
        return max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        return f(0, -1, n, nums);
    }
};
```
- Time comeplxity: O(2^n)
- Space complexity: O(n)

### Memoization
```cpp
class Solution {
public:
    int f(int ind, int prev, int& n, vector<int>& nums,vector<vector<int>>& dp) {
        if (ind == n) {
            return 0;
        }
        if(dp[ind][prev+1]!=-1)
        {
            return dp[ind][prev+1];
        }
        int notTake = f(ind + 1, prev, n, nums,dp);
        int take = 0;
        if (prev == -1 || nums[ind] > nums[prev]) {
            take = 1 + f(ind + 1, ind, n, nums,dp);
        }
        return dp[ind][prev+1]=max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0, -1, n, nums,dp);
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n*n) + O(n) (recursive stack space)

### Tabulation:
```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i - 1; j >= -1; j--) {
                int notTake = dp[i + 1][j + 1];
                int take = 0;
                if (j == -1 || nums[i] > nums[j]) {
                    take = 1 + dp[i + 1][i + 1];
                }
                dp[i][j + 1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n*n)

### Space optimized
```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> prev(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            vector<int> temp(n + 1, 0);
            for (int j = i - 1; j >= -1; j--) {
                int notTake = prev[j + 1];
                int take = 0;
                if (j == -1 || nums[i] > nums[j]) {
                    take = 1 + prev[i + 1];
                }
                temp[j + 1] = max(take, notTake);
            }
            prev = temp;
        }
        return prev[0];
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n)

### DP with legth array
```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> lis(n,1);
        int mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    lis[i]=max(lis[i],lis[j]+1);
                }
            }
            mx=max(mx,lis[i]);
        }
        return mx;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n)

### using binary search
```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<int> lis;
        lis.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            if (nums[i] > lis.back()) {
                lis.push_back(nums[i]);
            } else {
                int c =
                    lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                lis[c] = nums[i];
            }
        }
        return lis.size();
    }
};
```
- Time complexity: O(nlogn)
- Space complexity: O(n)

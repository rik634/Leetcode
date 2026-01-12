// Level: Medium
// problem statement: 

// Recursion:
class Solution {
public:
    int f(int ind, vector<int>& nums) {
        if (ind == 0) {
            return nums[0];
        }
        if (ind == 1) {
            return max(nums[0], nums[1]);
        }
        int take = nums[ind] + f(ind - 2, nums);
        int notTake = f(ind - 1, nums);
        return max(take, notTake);
    }
    int rob(vector<int>& nums) {

        int n = nums.size();

        return f(n - 1, nums);
    }
};
// Time complexity: O(2^n)
// Space complexity: O(n) (recursive stack space)

// Memoization
class Solution {
public:
    int f(int ind, vector<int>& nums,vector<int>& dp) {
        if (ind == 0) {
            return dp[ind]=nums[0];
        }
        if (ind == 1) {
            return dp[ind]=max(nums[0], nums[1]);
        }
        int take = nums[ind] + f(ind - 2, nums,dp);
        int notTake = f(ind - 1, nums,dp);
        return dp[ind]=max(take, notTake);
    }
    int rob(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n,-1);
        return f(n - 1, nums,dp);
    }
};
// Time complexity: O(n)
// space complexity: O(n) (dp) +O(n) (recursive stack space) = O(n)

// Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        if (n == 1) {
            return dp[n - 1];
        }
        dp[1] = max(nums[0], nums[1]);
        if (n == 2) {
            return dp[n - 1];
        }
        for (int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }
};
// Time complexity: O(n)
// Space complexity: O(n)

// Space optimized
class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
       
        if (n == 1) {
            return nums[0];
        }
       
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        int prev2=nums[0];
        int prev=max(nums[0], nums[1]);
        int curr;
        for (int i = 2; i < n; i++) {
            curr = max(nums[i]+prev2,prev);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};
// Time complexity: O(n)
// Space complexity: O(1)

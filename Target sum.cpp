// Level: Medium
// Link: https://leetcode.com/problems/target-sum/description/
// problem statement: 

// recursion
class Solution {
public:
    int f(int ind, vector<int>& nums, int S) {

        if (ind == 0) {
            if (S == 0 && nums[ind] == 0) {
                return 2;
            }
            if (S == 0 || nums[ind] == S) {
                return 1;
            }
            return 0;
        }
        int notTake = f(ind - 1, nums, S);
        int take = 0;
        if (nums[ind] <= S) {
            take = f(ind - 1, nums, S - nums[ind]);
        }
        return notTake + take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int S = sum - target;
        if (S % 2 != 0 || S < 0) {
            return 0;
        }
        return f(n - 1, nums, S / 2);
    }
};
// Time complexity: O(2^n)
// space complexity: O(n) (recursive stack space)

// memoization
class Solution {
public:
    int f(int ind, vector<int>& nums, int S, vector<vector<int>>& dp) {

        if (ind == 0) {
            if (S == 0 && nums[ind] == 0) {
                return 2;
            }
            if (S == 0 || nums[ind] == S) {
                return 1;
            }
            return 0;
        }
        if (dp[ind][S] != -1) {
            return dp[ind][S];
        }
        int notTake = f(ind - 1, nums, S, dp);
        int take = 0;
        if (nums[ind] <= S) {
            take = f(ind - 1, nums, S - nums[ind], dp);
        }
        return dp[ind][S] = notTake + take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int S = sum - target;
        if (S % 2 != 0 || S < 0) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>((S / 2) + 1, -1));
        return f(n - 1, nums, S / 2, dp);
    }
};
// Time complexity: O(n*S)
// space complexity: O(n*S) + O(n) (recursive stack space)

// tabulation
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int S = sum - target;
        if (S % 2 != 0 || S < 0) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>((S / 2) + 1, 0));
        for (int i = 0; i < dp[0].size(); i++) {
            if (i == 0 && nums[0] == 0) {
                dp[0][i] = 2;
            } else if (i == 0 || nums[0] == i) {
                dp[0][i] = 1;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= (S / 2); j++) {
                int notTake = dp[i - 1][j];
                int take = 0;
                if (nums[i] <= j) {
                    take = dp[i - 1][j - nums[i]];
                }
                dp[i][j] = take + notTake;
            }
        }
        return dp[n - 1][S / 2];
    }
};
// Time complexity: O(n*S)
// space complexity: O(n*S)

// space optimized
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int S = sum - target;
        if (S % 2 != 0 || S < 0) {
            return 0;
        }
        vector<int> prev((S/2)+1,0);
        for (int i = 0; i <=(S/2); i++) {
            if (i == 0 && nums[0] == 0) {
                prev[i] = 2;
            } else if (i == 0 || nums[0] == i) {
                prev[i] = 1;
            }
        }
        for (int i = 1; i < n; i++) {
            vector<int> temp((S/2)+1,0);
            for (int j = 0; j <= (S / 2); j++) {
                int notTake = prev[j];
                int take = 0;
                if (nums[i] <= j) {
                    take = prev[j - nums[i]];
                }
                temp[j] = take + notTake;
            }
            prev=temp;
        }
        return prev[S / 2];
    }
};
// Time complexity: O(n*S)
// space complexity: O(S)

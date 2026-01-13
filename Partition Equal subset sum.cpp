// level: Medium
// problem statement: Given an array arr of n integers, return true if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal else return false.

// recursion:
class Solution {
public:
    bool checkEqualPartition(int ind, vector<int>& nums, int target) {
        if (ind == 0) {
            return nums[0] == target;
        }
        if (target == 0) {
            return true;
        }

        int notTake = checkEqualPartition(ind - 1, nums, target);
        int take = false;
        if (nums[ind] <= target) {
            take = checkEqualPartition(ind - 1, nums, target - nums[ind]);
        }
        return notTake || take;
    }
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;

        return checkEqualPartition(n - 1, nums, target);
    }
};
// Time complexity: O(n) + O(2^n)
// space complexity: O(n) (recursive stack space)

// memooization
class Solution {
public:
    int checkEqualPartition(int ind, vector<int>& nums, int target,
                            vector<vector<int>>& dp) {
        if (ind == 0) {
            return nums[0] == target;
        }
        if (target == 0) {
            return dp[ind][target] = 1;
        }
        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }
        int notTake = checkEqualPartition(ind - 1, nums, target, dp);
        int take = 0;
        if (nums[ind] <= target) {
            take = checkEqualPartition(ind - 1, nums, target - nums[ind], dp);
        }
        return dp[ind][target] = notTake || take;
    }
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return checkEqualPartition(n - 1, nums, target, dp) == 1;
    }
};
// Time complexity: O(n) + O(n*sum)
// space complexity: O(n*sum) + O(n) (stack space)



// tabulation
class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if (nums[0] <= target) {
            dp[0][nums[0]] = true;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                int notTake = dp[i - 1][j];
                int take = false;
                if (nums[i] <= j) {
                    take = dp[i - 1][j - nums[i]];
                }
                dp[i][j] = notTake || take;
            }
        }
        return dp[n - 1][target];
    }
};
// Time complexity: O(n) + O(n*sum)
// space complexity: O(n*sum)


// space optimized
class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;
        vector<bool> prev(target + 1, false);
        if (nums[0] <= target) {
            prev[nums[0]] = true;
        }
        for (int i = 1; i < n; i++) {
            vector<bool> temp(target + 1, false);
            temp[0] = true;
            for (int j = 1; j <= target; j++) {
                int notTake = prev[j];
                int take = false;
                if (nums[i] <= j) {
                    take = prev[j - nums[i]];
                }
                temp[j] = notTake || take;
            }
            prev = temp;
        }
        return prev[target];
    }
};
// Time complexity: O(n) + O(n*sum)
// space complexity: O(sum)

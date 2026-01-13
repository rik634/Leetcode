// problem statement: We are given an array ‘ARR’ with N positive integers. We need to find if there is a subset in “ARR” with a sum equal to K. If there is, return true else return false.
//A subset/subsequence is a contiguous or non-contiguous part of an array, where elements appear in the same order as the original array.

// recursion:
class Solution {
public:
    bool subsetSumUtil(int ind, int target, vector<int>& arr) {
        if (target == 0) return true;t
        if (ind == 0) return arr[0] == target;
        bool notTaken = subsetSumUtil(ind - 1, target, arr);
        bool taken = false;
        if (arr[ind] <= target) {
            taken = subsetSumUtil(ind - 1, target - arr[ind], arr);
        }
        return notTaken || taken;
    }

    bool subsetSumToK(int n, int k, vector<int>& arr) {
       
        return subsetSumUtil(n - 1, k, arr);
    }
};
// time complexity: O(2^n)
// space complexity: O(n) (recursive stack space) 

// Memoization:
class Solution {
public:
    bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (ind == 0) return arr[0] == target;
        if (dp[ind][target] != -1) return dp[ind][target];
        bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

        bool taken = false;
        if (arr[ind] <= target) {
            taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
        }
        return dp[ind][target] = notTaken || taken;
    }
    bool subsetSumToK(int n, int k, vector<int>& arr) {
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return subsetSumUtil(n - 1, k, arr, dp);
    }
};
// Time complexity: O(n*k)
// space complexity: O(n*k) +O(n)

// Tabulation:
class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if (arr[0] <= k) {
            dp[0][arr[0]] = true;
        }
        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {
                bool notTaken = dp[ind - 1][target];
                bool taken = false;
                if (arr[ind] <= target) {
                    taken = dp[ind - 1][target - arr[ind]];
                }
                dp[ind][target] = notTaken || taken;
            }
        }
        return dp[n - 1][k];
    }
};
// Time complexity: O(n*k)
// space complexity: O(n*k)


// Space optimized;
class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vector<bool> prev(k + 1, false);

        prev[0] = true;
        if (arr[0] <= k) {
            prev[arr[0]] = true;
        }

        for (int ind = 1; ind < n; ind++) {
            vector<bool> cur(k + 1, false);
            cur[0] = true; 
            for (int target = 1; target <= k; target++) {
                bool notTaken = prev[target]; // skip current element
                bool taken = false;
                if (arr[ind] <= target) {
                    taken = prev[target - arr[ind]]; // take current element
                }
                cur[target] = notTaken || taken; // store result for current target
            }
            prev = cur; // move to next iteration
        }
        return prev[k];
    }
};
// Time complexity: O(n*k)
// space complexity: O(n)

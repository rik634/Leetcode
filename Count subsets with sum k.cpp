// problem statement:  Given an array arr of n integers and an integer K, count the number of subsets of the given array that have a sum equal to K

// recursion:
class Solution {
public:
    // Function to count subsets that sum up to target
    int countSubsets(vector<int>& nums, int target) {
        return solve(nums.size() - 1, target, nums, dp);
    }

private:
    // Recursive helper with memoization
    int solve(int index, int target, vector<int>& nums) {
        // Base case: if target is 0, we found a valid subset
        if (target == 0) return 1;
        // Base case: if we are at index 0, check if nums[0] equals target
        if (index == 0) return (nums[0] == target ? 1 : 0);

        // Case 1: Exclude current element
        int notTake = solve(index - 1, target, nums);

        // Case 2: Include current element (if it is not greater than target)
        int take = 0;
        if (nums[index] <= target) {
            take = solve(index - 1, target - nums[index], nums);
        }
        // Store result in dp and return
        return take + notTake;
    }
};
// Time complexity: O(2^(n+target))
// space complexity: O(n+target)

// memoization:
class Solution {
public:
    // Function to count subsets that sum up to target
    int countSubsets(vector<int>& nums, int target) {
        // Initialize dp table with -1 (uncomputed states)
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return solve(nums.size() - 1, target, nums, dp);
    }

private:
    // Recursive helper with memoization
    int solve(int index, int target, vector<int>& nums, vector<vector<int>>& dp) {
        // Base case: if target is 0, we found a valid subset
        if (target == 0) return 1;

        // Base case: if we are at index 0, check if nums[0] equals target
        if (index == 0) return (nums[0] == target ? 1 : 0);

        // If already computed, return from dp
        if (dp[index][target] != -1) return dp[index][target];

        // Case 1: Exclude current element
        int notTake = solve(index - 1, target, nums, dp);

        // Case 2: Include current element (if it is not greater than target)
        int take = 0;
        if (nums[index] <= target) {
            take = solve(index - 1, target - nums[index], nums, dp);
        }

        // Store result in dp and return
        return dp[index][target] = take + notTake;
    }
};
// Time complexity: O(n*target)
// space complexity: O(n*target) + O(n+target) (recursive stack space)

// tabulation
class Solution {
public:
    int countSubsets(vector<int>& arr, int K) {
        // Get number of elements
        int n = arr.size();

        // Create dp table with dimensions n x (K+1)
        vector<vector<int>> dp(n, vector<int>(K + 1, 0));

        // Base case: one subset (empty set) makes sum 0
        dp[0][0] = 1;

        // If first element is <= K, mark dp[0][arr[0]] as 1
        if (arr[0] <= K) dp[0][arr[0]] = 1;

        // Fill the table
        for (int i = 1; i < n; i++) {
            for (int target = 0; target <= K; target++) {
                // Exclude current element
                int notTake = dp[i - 1][target];

                // Include current element if possible
                int take = 0;
                if (arr[i] <= target) take = dp[i - 1][target - arr[i]];

                // Total ways
                dp[i][target] = notTake + take;
            }
        }

        // Final answer
        return dp[n - 1][K];
    }
};

// Time complexity: O(n*target)
// space complexity: O(n*target)

// space optimized
class Solution {
public:
    int countSubsets(vector<int>& arr, int K) {
        // Create a dp array of size K+1 initialized to 0
        vector<int> dp(K + 1, 0);

        // Base case: One subset (empty set) makes sum 0
        dp[0] = 1;

        // If first element <= K, mark it as a subset
        if (arr[0] <= K) dp[arr[0]] += 1;

        // Loop through elements starting from index 1
        for (int i = 1; i < arr.size(); i++) {
            // Create a temporary dp array for current element
            vector<int> curr(K + 1, 0);

            // Empty set always makes sum 0
            curr[0] = 1;

            // Iterate over all possible targets
            for (int t = 0; t <= K; t++) {
                // Exclude current element
                int notTake = dp[t];

                // Include current element if possible
                int take = 0;
                if (arr[i] <= t) {
                    take = dp[t - arr[i]];
                }

                // Total ways = include + exclude
                curr[t] = take + notTake;
            }

            // Update dp for next iteration
            dp = curr;
        }

        // Return answer for sum K
        return dp[K];
    }
};
// Time complexity: O(n*target)
// space complexity: O(target)

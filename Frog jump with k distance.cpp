// problem statement: 

// recursion:
int solveUtil(int ind, vector<int>& height,  int k) {
    if (ind == 0) return 0;
    int mmSteps = INT_MAX;

    for (int j = 1; j <= k; j++) {
        // Ensure jump does not go out of bounds
        if (ind - j >= 0) {
            // Cost of taking the jump
            int jump = solveUtil(ind - j, height, k) + abs(height[ind] - height[ind - j]);
            // Store the minimum cost
            mmSteps = min(jump, mmSteps);
        }
    }
    // Save the result in dp array
    return  mmSteps;
}

// Function to get minimum cost to reach end
int solve(int n, vector<int>& height, int k) {
    // Start recursion from last index
    return solveUtil(n - 1, height,  k);
}
// Time complexity: O(k^n)
// space complexity: O(n) (recursive stack space)

// Memoization:
int solveUtil(int ind, vector<int>& height, vector<int>& dp, int k) {
    // Base case: starting point has zero cost
    if (ind == 0) return 0;
    // Return already computed result
    if (dp[ind] != -1) return dp[ind];
    // Initialize minimum steps as large value
    int mmSteps = INT_MAX;
    // Try all possible jumps from 1 to k
    for (int j = 1; j <= k; j++) {
        // Ensure jump does not go out of bounds
        if (ind - j >= 0) {
            // Cost of taking the jump
            int jump = solveUtil(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
            // Store the minimum cost
            mmSteps = min(jump, mmSteps);
        }
    }
    return dp[ind] = mmSteps;
}

// Function to get minimum cost to reach end
int solve(int n, vector<int>& height, int k) {
    // DP array initialized to -1
    vector<int> dp(n, -1);
    // Start recursion from last index
    return solveUtil(n - 1, height, dp, k);
}
// Time complexity:O(n * k), where n is the number of stairs and k is the maximum jump allowed. For each index, we compute up to k recursive calls, each memoized.
// space complexity: O(n) due to the memoization array dp storing results for all indices from 0 to n-1.

// Tabulation:
int solveUtil(int n, vector<int>& height, vector<int>& dp, int k) {
   
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        int mmSteps = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int jump = dp[i - j] + abs(height[i] - height[i - j]);
                mmSteps = min(mmSteps, jump);
            }
        }
        dp[i] = mmSteps;
    }
    return dp[n - 1];
}
int solve(int n, vector<int>& height, int k) {
  
    vector<int> dp(n, -1);
    return solveUtil(n, height, dp, k);
}
// Time complexity: O(n*k)
// space complexity: O(n)

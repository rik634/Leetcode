// level: Medium
// problem statement:

// recursion:
class Solution {
public:
    int f(int ind, int amount, vector<int>& coins) {
        if (amount == 0) {
            return 0;
        }
        if (ind < 0) {
            return 1e8;
        }
        // nottake
        int notTake = f(ind - 1, amount, coins);
        int take = 1e8;
        if (coins[ind] <= amount) {
            take = 1 + f(ind, amount - coins[ind], coins);
        }
        return min(notTake, take);
    }
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
       
        int c = f(n - 1, amount, coins);
        if (c == 1e8) {
            return -1;
        }
        return c;
    }
};
// Time complexity: O(2^(amount+n))
// space complexity: O(amount+n)

// memoization
class Solution {
public:
    int f(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) {
            return 0;
        }
        if (ind < 0) {
            return 1e8;
        }
        if (dp[ind][amount] != -1) {
            return dp[ind][amount];
        }
        // nottake
        int notTake = f(ind - 1, amount, coins, dp);
        int take = 1e8;
        if (coins[ind] <= amount) {
            take = 1 + f(ind, amount - coins[ind], coins, dp);
        }
        return dp[ind][amount] = min(notTake, take);
    }
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int c = f(n - 1, amount, coins, dp);
        if (c >= 1e8) {
            return -1;
        }
        return c;
    }
};
// Time complexity: O(amount*n)
// space complexity: O(n*amount) + O(amount+n) (recursive stack space)

// tabulation

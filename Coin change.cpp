// level: Medium
// problem statement:  Given an integer array of coins representing coins of different denominations and an integer amount representing a total amount of money. 
//Return the fewest number of coins that are needed to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1. There are infinite numbers of coins of each type

// Recursion:
class Solution {
public:
    int f(int ind, int amount, vector<int>& coins) {

        if (ind == 0) {
            return (amount % coins[ind] == 0) ? (amount / coins[ind]) : 1e8;
        }
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
        if (c >= 1e8) {
            return -1;
        }
        return c;
    }
};
// Time complexity: O(2^(n+amount))
// space complexity: O(n+amount)

// Memoization
class Solution {
public:
    int f(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp) {

        if (ind == 0) {
            return (amount % coins[ind] == 0) ? (amount / coins[ind]) : 1e9;
        }
        if (dp[ind][amount] != INT_MAX) {
            return dp[ind][amount];
        }
        int notTake = f(ind - 1, amount, coins, dp);
        int take = INT_MAX;
        if (coins[ind] <= amount) {
            take = 1 + f(ind, amount - coins[ind], coins, dp);
        }
        return dp[ind][amount] = min(notTake, take);
    }
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));
        int c = f(n - 1, amount, coins, dp);
        if (c >= 1e9) {
            return -1;
        }
        return c;
    }
};
// Time complexity: O(n*amount)
// space complexity: O(n*amount) + O(n+amount) (recursive stack space)

// tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

        for (int i = 0; i <= amount; i++) {
            if ((i % coins[0]) == 0) {
                dp[0][i] = i / coins[0];
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                int notTake = dp[i - 1][j];
                int take = INT_MAX;
                if (coins[i] <= j) {
                    take = 1 + dp[i][j - coins[i]];
                }
                dp[i][j] = min(notTake, take);
            }
        }
        return dp[n - 1][amount] >= 1e9 ? -1 : dp[n - 1][amount];
    }
};
// Time complexity: O(amount) + O(n*amount)
// space complexity: O(n*amount)

// space optimized
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<int> prev(amount + 1, 1e9);
        for (int i = 0; i <= amount; i++) {
            if ((i % coins[0]) == 0) {
                prev[i] = i / coins[0];
            }
        }
        for (int i = 1; i < n; i++) {
            vector<int> temp(amount + 1, 1e9);
            for (int j = 0; j <= amount; j++) {
                int notTake = prev[j];
                int take = INT_MAX;
                if (coins[i] <= j) {
                    take = 1 + temp[j - coins[i]];
                }
                temp[j] = min(notTake, take);
            }
            prev = temp;
        }
        return prev[amount] >= 1e9 ? -1 : prev[amount];
    }
};
// Time complexity: O(n*amount)
// space complexity: O(amount)

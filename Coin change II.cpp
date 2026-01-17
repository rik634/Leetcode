// level: Medium
// problem statement: We are given an array Arr with N distinct coins and a target. We have an infinite supply of each coin denomination. 
//We need to find the number of ways we sum up the coin values to give us the target.

// recursion:
class Solution {
public:
    int f(int ind, int amount, vector<int>& coins) {
        if (amount == 0) {
            return 1;
        }
        if (ind == 0) {
            return (amount % coins[ind] == 0) ? 1 : 0;
        }
        int notTake = f(ind - 1, amount, coins);
        int take = 0;
        if (coins[ind] <= amount) {
            take = f(ind, amount - coins[ind], coins);
        }
        return take + notTake;
    }
    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        return f(n - 1, amount, coins);
    }
};
// Time complexity: O(2^(n+amount))
// space complexity: O(n+amount) (recursive stack space)

// memoization:
class Solution {
public:
    int f(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) {
            return 1;
        }
        if (ind == 0) {
            return (amount % coins[ind] == 0) ? 1 : 0;
        }
        if (dp[ind][amount] != -1) {
            return dp[ind][amount];
        }
        int notTake = f(ind - 1, amount, coins, dp);
        int take = 0;
        if (coins[ind] <= amount) {
            take = f(ind, amount - coins[ind], coins, dp);
        }
        return dp[ind][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(n - 1, amount, coins, dp);
    }
};
// Time complexity: O(n*amount)
// space complexity: O(n*amount) + O(n+amount) (recursive stack space)

// tabulation
class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        vector<vector<unsigned long long>> dp(
            n, vector<unsigned long long>(amount + 1, 0));

        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= amount; i++) {
            if (i % coins[0] == 0) {
                dp[0][i] = 1;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j];

                if (coins[i] <= j) {
                    dp[i][j] = (dp[i][j] + dp[i][j - coins[i]]);
                }
            }
        }
        return dp[n - 1][amount];
    }
};
// Time complexity: O(n*amount)
// space complexity: O(n*amount)

// space optimized
class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<unsigned long long> prev(amount + 1, 0);
        prev[0]=1;
        for (int i = 1; i <= amount; i++) {
            if (i % coins[0] == 0) {
                prev[i] = 1;
            }
        }
        for (int i = 1; i < n; i++) {
            vector<unsigned long long> temp(amount + 1, 0);
            temp[0] = 1;
            for (int j = 1; j <= amount; j++) {
                temp[j] = prev[j];

                if (coins[i] <= j) {
                    temp[j] += temp[j - coins[i]];
                }
            }
            prev = temp;
        }
        return prev[amount];
    }
};
// Time complexity: O(n*amount)
// space complexity: O(amount)


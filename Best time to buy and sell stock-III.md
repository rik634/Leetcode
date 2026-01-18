## Problem statement
- We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:
  1. We can buy and sell the stock any number of times.
  2. In order to sell the stock, we need to first buy it on the same or any previous day.
  3. We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
  4. We can do at most 2 transactions.
 
### Logic
Every day, we can either skip trading or buy/sell a stock based on whether we are holding one and how many trades are left. To find the maximum profit, we try all possible choices using recursion.
  - Think in terms of three things: the current day, whether we can buy or need to sell, and how many trades are left.
  - If we can buy: either skip or buy the stock.
  - If we need to sell: either skip or sell the stock (which completes one trade).
  - Return the maximum profit from these options.

Base Cases
  - If all days are finished → profit is 0.
  - If no trades are left → profit is 0.

### Recursion:
```cpp
class Solution {
public:
    int f(int ind, int buy, int count, vector<int>& prices, int& n) {
        if (count == 0 || ind == n) {
            return 0;
        }
        int profit = 0;
        if (buy == 0) { // we can buy
            profit = max(f(ind + 1, 0, count, prices, n),
                         -prices[ind] + f(ind + 1, 1, count, prices, n));
        } else { // we can sell
            profit = max(f(ind + 1, 1, count, prices, n),
                         prices[ind] + f(ind + 1, 0, count - 1, prices, n));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        return f(0, 0, 2, prices, n);
    }
};
```
- Time complexity: O(2^n)
- Space complexity: O(n)

### Memoization:
```cpp
class Solution {
public:
    int f(int ind, int buy, int count, vector<int>& prices, int& n,
          vector<vector<vector<int>>>& dp) {
        if (count == 0 || ind == n) {
            return 0;
        }
        if (dp[ind][buy][count] != -1) {
            return dp[ind][buy][count];
        }
        int profit = 0;
        if (buy == 0) {
            profit = max(f(ind + 1, 0, count, prices, n, dp),
                         -prices[ind] + f(ind + 1, 1, count, prices, n, dp));
        } else {
            profit = max(f(ind + 1, 1, count, prices, n, dp),
                         prices[ind] + f(ind + 1, 0, count - 1, prices, n, dp));
        }
        return dp[ind][buy][count] = profit;
    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 0, 2, prices, n, dp);
    }
};
```
- Time complexity: O(n*2*3)
- Space complexity: O(n*2*3) + O(n)

### Tabulation:
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j >= 0; j--) {
                for (int k = 1; k < 3; k++) {
                    int profit;
                    if (j == 0) {
                        profit =
                            max(dp[i + 1][0][k], -prices[i] + dp[i + 1][1][k]);
                    } else {
                        profit = max(dp[i + 1][1][k],
                                     prices[i] + dp[i + 1][0][k - 1]);
                    }
                    dp[i][j][k] = profit;
                }
            }
        }
        return dp[0][0][2];
    }
};
```
- Time complexity: O(n*2*3)
- Space complexity: O(n*2*3)

### Space optimized:
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> prev(2, vector<int>(3, 0));
        for (int i = n - 1; i >= 0; i--) {
            vector<vector<int>> temp(2, vector<int>(3, 0));
            for (int j = 1; j >= 0; j--) {
                for (int k = 1; k < 3; k++) {
                    int profit;
                    if (j == 0) {
                        profit = max(prev[0][k], -prices[i] + prev[1][k]);
                    } else {
                        profit = max(prev[1][k], prices[i] + prev[0][k - 1]);
                    }
                    temp[j][k] = profit;
                }
            }
            prev = temp;
        }
        return prev[0][2];
    }
};
```
- Time complexity: O(n*2*3)
- Space complexity:O(2*3) = O(1)


## Problem statement
- We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed
  1. We can buy and sell the stock any number of times.
  2. In order to sell the stock, we need to first buy it on the same or any previous day.
  3. We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
  4. We can do at most K transactions.


### Logic


### Recursion
```cpp
class Solution {
public:
    int f(int ind, int buy, int count, vector<int>& prices, int& n) {
        if (count == 0 || ind == n) {
            return 0;
        }
        int profit = 0;
        if (buy == 0) {
            profit = max(f(ind + 1, 0, count, prices, n),
                         -prices[ind] + f(ind + 1, 1, count, prices, n));
        } else {
            profit = max(f(ind + 1, 1, count, prices, n),
                         prices[ind] + f(ind + 1, 0, count - 1, prices, n));
        }
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();
        return f(0, 0, k, prices, n);
    }
};
```
- Time complexity: O(2^n) Even though the count (transactions) acts as a base case, in the worst case (where $k$ is large), the recursion tree behaves like a full binary tree with a depth of $n$. This leads to approximately $2^n$ operations.
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
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return f(0, 0, k, prices, n, dp);
    }
};
```
- Time complexity: O(n*2*k)
- Space complexity: O(n*2*k) + O(n)

### Tabulation
```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                for (int l = 1; l <= k; l++) {
                    int profit = 0;
                    if (j == 0) {
                        profit =
                            max(dp[i + 1][0][l], -prices[i] + dp[i + 1][1][l]);
                    } else {
                        profit = max(dp[i + 1][1][l],
                                     prices[i] + dp[i + 1][0][l - 1]);
                    }
                    dp[i][j][l] = profit;
                }
            }
        }
        return dp[0][0][k];
    }
};
```
- Time complexit: O(n*2*k)
- Space complexity: O(n*2*k)

### Space optimized
```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> prev(2, vector<int>(k + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            vector<vector<int>> temp(2, vector<int>(k + 1, 0));
            for (int j = 0; j < 2; j++) {
                for (int l = 1; l <= k; l++) {
                    int profit = 0;
                    if (j == 0) {
                        profit = max(prev[0][l], -prices[i] + prev[1][l]);
                    } else {
                        profit = max(prev[1][l], prices[i] + prev[0][l - 1]);
                    }
                    temp[j][l] = profit;
                }
            }
            prev = temp;
        }
        return prev[0][k];
    }
};
```
- Time complexity: O(n*2*k)
- Space complexity: O(2*k)

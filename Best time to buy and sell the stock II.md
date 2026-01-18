## Problem statement:
- We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:
  1. We can buy and sell the stock any number of times.
  2. In order to sell the stock, we need to first buy it on the same or any previous day.
  3. We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
 
### Logic:
- Every day, we have two options: either do nothing or make a buy/sell action to increase profit. Since we must check all possibilities to get the maximum profit, we use recursion.
- Try all choices
   1. If we are allowed to buy:
      - Option 1: Skip the day and move to the next.
      - Option 2: Buy the stock (profit decreases now because we spend money) and then move to the next day.
   2. If we are holding a stock and can sell:
     -  Option 1: Skip the day and move to the next.
     -  Option 2: Sell the stock (profit increases now because we earn money) and then move to the next day.
- Return the maximum: For every day, choose the option that gives the highest profit.
- Base Case: If we have reached the end of the trading days, return 0 as no more profit can be made.

### Recursion:
```cpp
class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, int& n) {
        if (ind == n) {
            return 0;
        }
        int profit = 0;
        if (buy == 0) // we can buy
        {
            profit = max(f(ind + 1, 0, prices, n),
                         -prices[ind] + f(ind + 1, 1, prices, n));
        } else // we can sell
        {
            profit = max(f(ind + 1, 1, prices, n),
                         prices[ind] + f(ind + 1, 0, prices, n));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        return f(0, 0, prices, n);
    }
};
```
- Time complexity: O(2^n)
- space complexity: O(n)

### Memoization:
```cpp
class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, int& n,
          vector<vector<int>>& dp) {
        if (ind == n) {
            return 0;
        }
        if (dp[ind][buy] != -1) {
            return dp[ind][buy];
        }
        int profit = 0;
        if (buy == 0) // we can buy
        {
            profit = max(f(ind + 1, 0, prices, n, dp),
                         -prices[ind] + f(ind + 1, 1, prices, n, dp));
        } else // we can sell
        {
            profit = max(f(ind + 1, 1, prices, n, dp),
                         prices[ind] + f(ind + 1, 0, prices, n, dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 0, prices, n, dp);
    }
};
```
- Time complexity: O(n*2)
- Space complexity: O(n*2) + O(n) (recurisve stack space)

### Tabulation:
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = 0; i < 2; i++) {
            dp[n][i] = 0;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j >= 0; j--) {
                int profit = 0;
                if (j == 0) {
                    profit = max(dp[i + 1][0], -prices[i] + dp[i + 1][1]);
                } else {
                    profit = max(dp[i + 1][1], prices[i] + dp[i + 1][0]);
                }
                dp[i][j] = profit;
            }
        }
        return dp[0][0];
    }
};
```
- Time complexity: O(n*2)
- Space complexity: O(n*2)

### Space optimized
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        
        vector<int> prev(2,0);
        for (int i = 0; i < 2; i++) {
            prev[i] = 0;
        }
        for (int i = n - 1; i >= 0; i--) {
            vector<int> temp(2,0);
            for (int j = 1; j >= 0; j--) {
                int profit = 0;
                if (j == 0) {
                    profit = max(prev[0], -prices[i] + prev[1]);
                } else {
                    profit = max(prev[1], prices[i] + prev[0]);
                }
                temp[j] = profit;
            }
            prev=temp;
        }
        return prev[0];
    }
};
```
- Time complexity: O(n*2)
- Space complexity: O(1)

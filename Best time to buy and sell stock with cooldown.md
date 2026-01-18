## Problem statement
- We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:
  1. We can buy and sell the stock any number of times.
  2. In order to sell the stock, we need to first buy it on the same or any previous day.
  3. We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
  4. We can’t buy a stock on the very next day of selling it. This is the cooldown clause

### Logic
### Recursion
```cpp
class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, int& n)
    {
        if(ind>=n)
        {
            return 0;
        }

        int profit=0;
        if(buy==0)
        {
            profit = max(f(ind+1,0,prices,n),-prices[ind]+f(ind+1,1,prices,n));
        }
        else
        {
            profit = max(f(ind+1,1,prices,n),prices[ind]+f(ind+2,0,prices,n));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        return f(0,0,prices,n);
    }
};
```
- Time complexity: O(2^n)
- Space complexity: O(n)


## Memoization
```cpp
class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, int& n,
          vector<vector<int>>& dp) {
        if (ind >= n) {
            return 0;
        }
        if (dp[ind][buy] != -1) {
            return dp[ind][buy];
        }
        int profit = 0;
        if (buy == 0) {
            profit = max(f(ind + 1, 0, prices, n, dp),
                         -prices[ind] + f(ind + 1, 1, prices, n, dp));
        } else {
            profit = max(f(ind + 1, 1, prices, n, dp),
                         prices[ind] + f(ind + 2, 0, prices, n, dp));
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
- Space complexity: O(n)

### Tabulation
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                int profit = 0;
                if (j == 0) {
                    profit = max(dp[i + 1][0], -prices[i] + dp[i + 1][1]);
                } else {
                    profit = max(dp[i + 1][1], prices[i] + dp[i + 2][0]);
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

### Space optimized;
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<int> prev1(2, 0);
        vector<int> prev(2, 0);
        for (int i = n - 1; i >= 0; i--) {
            vector<int> temp(2, 0);
            for (int j = 0; j < 2; j++) {
                int profit = 0;
                if (j == 0) {
                    profit = max(prev[0], -prices[i] + prev[1]);
                } else {
                    profit = max(prev[1], prices[i] + prev1[0]);
                }
                temp[j] = profit;
            }
            prev1 = prev;
            prev = temp;
        }
        return prev[0];
    }
};
```
- Time complexity: O(n*2)
- Space complexity: O(2)

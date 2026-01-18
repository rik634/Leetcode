## Problem statement:
- You are given an array prices where prices[i] is the price of a given stock on the ith day.
- You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
- Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

### Brute force:
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mx = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (prices[j] >= prices[i]) {
                    mx = max(mx, prices[j] - prices[i]);
                }
            }
        }
        return mx;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(1)

### Optimized
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mx = 0;
        int mn = prices[0];
        for (int i = 1; i < n; i++) {
            int cost = prices[i] - mn;
            mx = max(mx, cost);
            mn = min(mn, prices[i]);
        }
        return mx;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)

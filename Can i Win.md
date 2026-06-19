## Problem statement
- In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. The player who first causes the running total to reach or exceed 100 wins.
- What if we change the game so that players cannot re-use integers?
- For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.
- Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a win, otherwise, return false. Assume both players play optimally.

### recusion
```cpp
class Solution {
public:
    bool dfs(int mask, int total, int& n, int& desiredTotal) {
        // If the previous player already reached or exceeded the total, you
        // lose.
        if (total >= desiredTotal) {
            return false;
        }

        for (int i = 0; i < n; i++) {
            // Check if the number (i + 1) is already used
            if (mask & (1 << i)) {
                continue;
            }
            // If picking (i + 1) forces the opponent into a losing state, you
            // win.
            if (!dfs(mask | (1 << i), total + i + 1, n, desiredTotal)) {
                return true;
            }
        }
        // If no move can force an opponent loss, you lose this state.
        return false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        // Instant win edge case
        if (desiredTotal <= 0)
            return true;

        // Instant loss edge case (sum of all choices is less than desired
        // total)
        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        if (sum < desiredTotal)
            return false;

        return dfs(0, 0, maxChoosableInteger, desiredTotal);
    }
};
```
- Time complexity: O(!n)
- Space complexity: O(n)

### memoization
```cpp
class Solution {
public:
    bool dfs(int mask, int total, int& n, int& desiredTotal,
             vector<vector<int>>& dp) {
        // If the previous player already reached or exceeded the total, you
        // lose.
        if (total >= desiredTotal) {
            return false;
        }

        if (dp[mask][total] != -1) {
            return dp[mask][total];
        }
        for (int i = 0; i < n; i++) {
            // Check if the number (i + 1) is already used
            if (mask & (1 << i)) {
                continue;
            }
            // If picking (i + 1) forces the opponent into a losing state, you
            // win.
            if (!dfs(mask | (1 << i), total + i + 1, n, desiredTotal, dp)) {
                return dp[mask][total] = true;
            }
        }
        // If no move can force an opponent loss, you lose this state.
        return dp[mask][total] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        // Instant win edge case
        if (desiredTotal <= 0)
            return true;

        // Instant loss edge case (sum of all choices is less than desired
        // total)
        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        if (sum < desiredTotal)
            return false;

        vector<vector<int>> dp(2 << maxChoosableInteger,
                               vector<int>(sum + 1, -1));
        return dfs(0, 0, maxChoosableInteger, desiredTotal, dp);
    }
};
```
- Time complexity: O((2^n)*S)
- Space complexity: O((2^n)*S)

### Tabulation
```cpp

```

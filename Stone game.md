## Problem statemnt
- Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].
- The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.
- Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.
- Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins

### memoization:
```cpp
class Solution {
public:
    int dfs(int i, int j, vector<int>& piles, vector<vector<int>>& dp) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return piles[i];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int total = accumulate(piles.begin() + i, piles.begin() + j, 0);
        int pick_left = total - dfs(i + 1, j, piles, dp);
        int pick_right = total - dp[i][j - 1];
        return dp[i][j] = max(pick_left, pick_right);
    }
    bool stoneGame(vector<int>& piles) {

        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        dfs(0, n - 1, piles, dp);
        int p1 = dp[0][n - 1];
        int p2 = accumulate(piles.begin(), piles.end(), 0) - p1;
        return p1 > p2;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n*n)

### Tabulation
```cpp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {

        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }
        for (int i = n-2; i >=0; i--) {
            for (int j = i+1; j < n; j++) {
                int total = accumulate(piles.begin() + i, piles.begin() + j+1, 0);
                dp[i][j] = max(total - dp[i + 1][j], total - dp[i][j - 1]);
            }
        }

        int p1 = dp[0][n - 1];
        int p2 = accumulate(piles.begin(), piles.end(), 0) - p1;
        return p1 > p2;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n*n)

### Space optimized
```cpp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {

        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> prev(n, 0);
        prev[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            vector<int> temp(n, 0);
            temp[i] = piles[i];
            for (int j = i + 1; j < n; j++) {
                int total =
                    accumulate(piles.begin() + i, piles.begin() + j + 1, 0);
                temp[j] = max(total - prev[j], total - temp[j - 1]);
            }
            prev = temp;
        }

        int p1 = prev[n - 1];
        int p2 = accumulate(piles.begin(), piles.end(), 0) - p1;
        return p1 > p2;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n)


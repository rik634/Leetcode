## Problem statement:
- Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
- In one step, you can delete exactly one character in either string


### Recursion
```cpp
class Solution {
public:
    int f(int i, int j, string& word1, string& word2) {
        if (i < 0 || j < 0) {
            return 0;
        }
        int mid = INT_MIN;
        int left = INT_MIN;
        int right = INT_MIN;
        if (word1[i] == word2[j]) {
            mid = 1 + f(i - 1, j - 1, word1, word2);
        }
        left = f(i - 1, j, word1, word2);
        right = f(i, j - 1, word1, word2);
        return max(mid, max(left, right));
    }
    int minDistance(string word1, string word2) {

        int n = word1.length();
        int m = word2.length();

        int l = f(n - 1, m - 1, word1, word2);
        return n + m - 2 * l;
    }
};
```
- Time complexity: O(3^(n+m))
- Space complexity: O(n+m)

### Memoization:
```cpp
class Solution {
public:
    int f(int i, int j, string& word1, string& word2,vector<vector<int>>& dp) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int mid = INT_MIN;
        int left = INT_MIN;
        int right = INT_MIN;
        if (word1[i] == word2[j]) {
            mid = 1 + f(i - 1, j - 1, word1, word2,dp);
        }
        left = f(i - 1, j, word1, word2,dp);
        right = f(i, j - 1, word1, word2,dp);
        return dp[i][j]=max(mid, max(left, right));
    }
    int minDistance(string word1, string word2) {

        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int l = f(n - 1, m - 1, word1, word2,dp);
        return n + m - 2 * l;
    }
};
```
- Time complexity: O(n*m)
- Space complexity: O(n*m) + O(n+m)

### Tabulation:
```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {

        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int l = dp[n][m];
        return n + m - 2 * l;
    }
};
```
- Time complexity: O(n*m)
- Space complexity: O(n*m)

### Space optimized
```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {

        int n = word1.length();
        int m = word2.length();
       
        vector<int> prev(m+1,0);
        for (int i = 1; i <= n; i++) {
            vector<int> temp(m+1,0);
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    temp[j] = 1 + prev[j - 1];
                } else {
                    temp[j] = max(prev[j], temp[j - 1]);
                }
            }
            prev=temp;
        }
        int l = prev[m];
        return n + m - 2 * l;
    }
};
```
- Time complexity: O(n*m)
- Space complexity: O(m)

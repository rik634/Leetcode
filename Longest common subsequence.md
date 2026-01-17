## Problem statement:
-  Given two strings str1 and str2, find the length of their longest common subsequence.
- A subsequence is a sequence that appears in the same relative order but not necessarily contiguous and a common subsequence of two strings is a subsequence that is common to both strings.

### Logic:

### Recursion:
```cpp
class Solution {
public:
    int f(int ind1, int ind2, string& text1, string& text2) {
        if (ind1 < 0 || ind2 < 0) {
            return 0;
        }
        int mid = INT_MIN;
        int left = INT_MIN;
        int right = INT_MIN;
        if (text1[ind1] == text2[ind2]) {
            mid = 1 + f(ind1 - 1, ind2 - 1, text1, text2);
        }
        left = f(ind1 - 1, ind2, text1, text2);
        right = f(ind1, ind2 - 1, text1, text2);
        return max(mid, max(left, right));
    }
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.length();
        int m = text2.length();

        return f(n - 1, m - 1, text1, text2);
    }
};
```
- Time complexity: O(2^(n+m)) or (3^max(n,m))
- Space complexity: O(n+m)

### Memoization:
```cpp
class Solution {
public:
    int f(int ind1, int ind2, string& text1, string& text2,
          vector<vector<int>>& dp) {
        if (ind1 < 0 || ind2 < 0) {
            return 0;
        }
        if (dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }
        int mid = INT_MIN;
        int left = INT_MIN;
        int right = INT_MIN;
        if (text1[ind1] == text2[ind2]) {
            mid = 1 + f(ind1 - 1, ind2 - 1, text1, text2, dp);
        }
        left = f(ind1 - 1, ind2, text1, text2, dp);
        right = f(ind1, ind2 - 1, text1, text2, dp);
        return dp[ind1][ind2] = max(mid, max(left, right));
    }
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, text1, text2, dp);
    }
};
```
- Time complexity: O(n*m)
- Space complexity: O(n*m) + O(n+m)

### Tabulation:
```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};
```
- Time complexity: O(n*m)
- Space complexity: O(n*m)

## Space optimized
```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.length();
        int m = text2.length();
        
        vector<int> prev(m+1,0);
        for (int i = 1; i <= n; i++) {
            vector<int> temp(m+1,0);
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    temp[j] = 1 + prev[j - 1];
                } else {
                    temp[j] = max(prev[j], temp[j - 1]);
                }
            }
            prev=temp;
        }
        return prev[m];
    }
};
```
- Time complexity: O(n*m)
- Space complexity: O(m)

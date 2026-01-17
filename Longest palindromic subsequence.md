## Problem statement:
- Given a string, Find the longest palindromic subsequence length in given string.
- A palindrome is a sequence that reads the same backwards as forward.
- A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

### Recursion:
```cpp
class Solution {
public:
    int f(int i, int j, string& s, string& s1) {
        if (i < 0 || j < 0) {
            return 0;
        }
        int mid = INT_MIN;
        int left = INT_MIN;
        int right = INT_MIN;
        if (s[i] == s1[j]) {
            mid = 1 + f(i - 1, j - 1, s, s1);
        }
        left = f(i - 1, j, s, s1);
        right = f(i, j - 1, s, s1);
        return max(mid, max(left, right));
    }
    int longestPalindromeSubseq(string s) {

        string s1 = s;
        reverse(s1.begin(), s1.end());
        int n = s.length();
        return f(n - 1, n - 1, s, s1);
    }
};
```
- Time complexity: O(2^(n+n))
- Space complexity: O(n+n)

### Memoization:
```cpp
class Solution {
public:
    int f(int i, int j, string& s, string& s1, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int mid = INT_MIN;
        int left = INT_MIN;
        int right = INT_MIN;
        if (s[i] == s1[j]) {
            mid = 1 + f(i - 1, j - 1, s, s1, dp);
        }
        left = f(i - 1, j, s, s1, dp);
        right = f(i, j - 1, s, s1, dp);
        return dp[i][j] = max(mid, max(left, right));
    }
    int longestPalindromeSubseq(string s) {

        string s1 = s;
        reverse(s1.begin(), s1.end());
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(n - 1, n - 1, s, s1, dp);
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n*n) + O(n+n)

### Tabulation:
```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {

        int n = s.length();
        string s1 = s;
        reverse(s1.begin(), s1.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == s1[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n*n)

### Space optimized
```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {

        int n = s.length();
        string s1 = s;
        reverse(s1.begin(), s1.end());

        vector<int> prev(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            vector<int> temp(n + 1, 0);
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == s1[j - 1]) {
                    temp[j] = 1 + prev[j - 1];
                } else {
                    temp[j] = max(prev[j], temp[j - 1]);
                }
            }
            prev = temp;
        }
        return prev[n];
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n)

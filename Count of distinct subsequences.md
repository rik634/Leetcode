## Problem statement: 
- Given two strings s and t, return the number of distinct subsequences of s that equal t.
- A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters. For example, "ace" is a subsequence of "abcde" while "aec" is not.
- The task is to count how many different ways we can form t from s by deleting some (or no) characters from s.

### Logic:
- The problem asks us to count how many ways we can form string t from string s by deleting characters. Whenever we compare characters from s and t, we have two choices, if the characters match, we can either use it (move both pointers) or skip it (move only in s).
- If the characters don’t match, the only option is to skip the character from s. This naturally gives us overlapping subproblems, so memoization works perfectly.
  1.  Define a recursive function f(i, j) which counts ways to form substring of t starting at j from substring of s starting at i
  2. If j equals length of t, return 1 because we have successfully formed t
  3. If i equals length of s but j is smaller than length of t, return 0 because s is exhausted
  4. If s[i] is equal to t[j], then we can either take this character or skip it
  5. If characters match, f(i, j) becomes f(i+1, j+1) plus f(i+1, j)
  6. If characters do not match, we can only skip the character from s so f(i, j) becomes f(i+1, j)

### Recursion:
```cpp
class Solution {
public:
    int f(int i, int j, string& s, string& t) {
        // If we have matched all characters of t
        // then we found one valid subsequence
        if (j == t.length()) {
            return 1;
        }
        // If we have exhausted s but not t
        // then no valid subsequence can be formed
        if (i == s.length()) {
            return 0;
        }
        // If current characters of s and t match
        if (s[i] == t[j]) {
            // Option 1: take this character and move both indices
            int take = f(i + 1, j + 1, s, t);
            // Option 2: skip this character of s and move only in s
            int notTake = f(i + 1, j, s, t);
            return take + notTake;
        }
        // If characters do not match, we can only skip s[i]
        return f(i + 1, j, s, t);
    }
    int numDistinct(string s, string t) {

        int n = s.length();
        int m = t.length();
        return f(0, 0, s, t);
    }
};
```
- Time complexity: O(2^n)
- Space complexity: O(n)

### Memoization:
```cpp
class Solution {
public:
    int f(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        // If we have matched all characters of t
        // then we found one valid subsequence
        if (j == t.length()) {
            return 1;
        }
        // If we have exhausted s but not t
        // then no valid subsequence can be formed
        if (i == s.length()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        // If current characters of s and t match
        if (s[i] == t[j]) {
            // Option 1: take this character and move both indices
            int take = f(i + 1, j + 1, s, t, dp);
            // Option 2: skip this character of s and move only in s
            int notTake = f(i + 1, j, s, t, dp);
            return take + notTake;
        }
        // If characters do not match, we can only skip s[i]
        return f(i + 1, j, s, t, dp);
    }
    int numDistinct(string s, string t) {

        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(0, 0, s, t, dp);
    }
};
```
- Time complexity: O(n*m)
- Space complexity: O(n*m) + O(n)

### Tabulation:
```cpp
class Solution {
public:
    const int MOD = 1e9 + 7;
    int numDistinct(string s, string t) {

        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][m] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    int take = dp[i + 1][j + 1];
                    int notTake = dp[i + 1][j];
                    dp[i][j] = (take + notTake) % MOD;
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }
};
```
- Time complexity: O(n*m)
- Space complexity: O(n*m)

### Space optimized
```cpp
class Solution {
public:
    const int MOD = 1e9 + 7;
    int numDistinct(string s, string t) {

        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int> prev(m + 1, 0);
        prev[m] = 1;
        for (int i = n - 1; i >= 0; i--) {
            vector<int> temp(m + 1, 0);
            temp[m] = 1;
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    int take = prev[j + 1];
                    int notTake = prev[j];
                    temp[j] = (take + notTake) % MOD;
                } else {
                    temp[j] = prev[j];
                }
            }
            prev = temp;
        }
        return prev[0];
    }
};
```
- Time complexity: O(n*m)
- Space complexity: O(m)

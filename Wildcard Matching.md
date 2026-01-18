## Problem statement:
- We are given two strings ‘S1’ and ‘S2’. String S1 can have the following two special characters.
  1. ‘?’ can be matched to a single character of S2.
  2. ‘*’ can be matched to any sequence of characters of S2. (sequence can be of length zero or more).
- We need to check whether strings S1 and S2 match or not.

### Logic:
- Steps to form the recursive solution
  1. Compare positions in both strings
  2. Treat one string as the pattern (letters, '?' or '*') and the other as the text. Start from the end and move backwards.
  3. Handle current characters

     a. Characters match: move back in both strings.

     b. '?' → matches exactly one character: move back in both.

     c. '*' →
           i. Match empty sequence , move back in pattern.
           ii. Match one or more characters,move back in text. 
     d. Different letters: no match.
4. Combine results: If any option leads to a match, the strings match.
5. Base cases
   a. Both strings finished : match.
   b. Pattern finished but text left: no match.
   c. Text finished but pattern left : match only if all remaining are '*'.

### Recursion:
```cpp
class Solution {
public:
    bool f(int i, int j, string& s, string& p) {
        // Base Case 1: Both strings are exhausted
        if (i < 0 && j < 0) {
            return true;
        }

        // Base Case 2: Pattern exhausted but text remains
        if (i >= 0 && j < 0) {
            return false;
        }
        // Base Case 3: Text exhausted but pattern may still have '*'
        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') {
                    return false;
                }
            }
            return true;
        }
        bool res = false;
        // If characters match or pattern has '?'
        if (s[i] == p[j] || p[j] == '?') {
            res = res || f(i - 1, j - 1, s, p);
        }

        // If pattern has '*', we have two choices:
        // 1. Treat '*' as matching empty sequence -> move pattern index i-1
        // 2. Treat '*' as matching one or more characters -> move text index
        // j-1
        else if (p[j] == '*') {
            res = res || f(i, j - 1, s, p);
            res = res || f(i - 1, j, s, p);
        }
        return res;
    }
    bool isMatch(string s, string p) {

        int n = s.length();
        int m = p.length();
        return f(n - 1, m - 1, s, p);
    }
};
```
- Time complexity: O(2^(n+m))
- Space complexity: O(n+m) (recursive stack space)

### Memoization:
```cpp
class Solution {
public:
    bool f(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        // Base Case 1: Both strings are exhausted
        if (i < 0 && j < 0) {
            return true;
        }

        // Base Case 2: Pattern exhausted but text remains
        if (i >= 0 && j < 0) {
            return false;
        }
        // Base Case 3: Text exhausted but pattern may still have '*'
        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') {
                    return false;
                }
            }
            return true;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        bool res = false;
        // If characters match or pattern has '?'
        if (s[i] == p[j] || p[j] == '?') {
            res = res || f(i - 1, j - 1, s, p, dp);
        }

        // If pattern has '*', we have two choices:
        // 1. Treat '*' as matching empty sequence -> move pattern index i-1
        // 2. Treat '*' as matching one or more characters -> move text index
        // j-1
        else if (p[j] == '*') {
            res = res || f(i, j - 1, s, p, dp);
            res = res || f(i - 1, j, s, p, dp);
        }
        return dp[i][j] = res;
    }
    bool isMatch(string s, string p) {

        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s, p, dp);
    }
};
```
- Time complexity: O(n*m)
- Space complexity: O(n*m) + O(n+m)

### Tabulation:
```cpp
class Solution {
public:
    bool isMatch(string s, string p) {

        int n = s.length();
        int m = p.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = true;
            } else {
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};
```
- Time complexity: O(n*m)
- Space complexity: O(n*m)

### Space optimized
```cpp
class Solution {
public:
    bool isMatch(string s, string p) {

        int n = s.length();
        int m = p.length();
        
        vector<bool> prev(m+1,false);
        prev[0] = true;
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                prev[j] = true;
            } else {
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            vector<bool> temp(m+1,false);
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    temp[j] = prev[j - 1];
                } else if (p[j - 1] == '*') {
                    temp[j] = temp[j - 1] || prev[j];
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

## Problem statement


### Recursion
```cpp
class Solution {
public:
    bool f(int ind, int& n, string& s, int a) {
        if (ind == n) {
            return a == 0;
        }
        if (a < 0) {
            return false;
        }
        bool flag = false;
        if (s[ind] == '(') {
            flag = flag || f(ind + 1, n, s, a + 1);
        } else if (s[ind] == ')' && a > 0) {
            flag = flag || f(ind + 1, n, s, a - 1);
        } else if (s[ind] == '*') {
            flag = flag || f(ind + 1, n, s, a + 1);
            if (a > 0) {
                flag = flag || f(ind + 1, n, s, a - 1);
            }
            flag = flag || f(ind + 1, n, s, a);
        }
        return flag;
    }
    bool checkValidString(string s) {

        int n = s.length();
        return f(0, n, s, 0);
    }
};
```
- Time complexity: O(3^n) (in worst case, where s[ind]="*", there are 3 branches)
- Space complexity: O(n)

### Memoization
```cpp
class Solution {
public:
    bool f(int ind, int& n, string& s, int a, vector<vector<int>>& dp) {
        if (ind == n) {
            return a == 0;
        }
        if (a < 0) {
            return false;
        }
        if (dp[ind][a] != -1) {
            return dp[ind][a];
        }
        bool flag = false;
        if (s[ind] == '(') {
            flag = flag || f(ind + 1, n, s, a + 1, dp);
        } else if (s[ind] == ')' && a > 0) {
            flag = flag || f(ind + 1, n, s, a - 1, dp);
        } else if (s[ind] == '*') {
            flag = flag || f(ind + 1, n, s, a + 1, dp);
            if (a > 0) {
                flag = flag || f(ind + 1, n, s, a - 1, dp);
            }
            flag = flag || f(ind + 1, n, s, a, dp);
        }
        return dp[ind][a] = flag;
    }
    bool checkValidString(string s) {

        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n, s, 0, dp);
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n*n)

### Tabulation
```cpp
class Solution {
public:
    bool checkValidString(string s) {

        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, false));
        dp[n][0] = true;
        for (int i = n - 1; i >= 0; i--) {
            for (int a = 0; a <= n; a++) {
                bool flag = false;
                if (s[i] == '(') {
                    if (a + 1 <= n) {
                        flag = flag || dp[i + 1][a + 1];
                    }
                } else if (s[i] == ')') {
                    if (a > 0) {
                        flag = flag || dp[i + 1][a - 1];
                    }
                } else if (s[i] == '*') {
                    if (a + 1 <= n) {
                        flag = flag || dp[i + 1][a + 1];
                    }
                    if (a > 0) {
                        flag = flag || dp[i + 1][a - 1];
                    }
                    flag = flag || dp[i + 1][a];
                }
                dp[i][a] = flag;
            }
        }

        return dp[0][0];
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n*n)

### Space optimized
```cpp
class Solution {
public:
    bool checkValidString(string s) {

        int n = s.length();
        vector<bool> prev(n + 1, false);
        prev[0] = true;
        for (int i = n - 1; i >= 0; i--) {
            vector<bool> temp(n + 1, false);
            for (int a = 0; a <= n; a++) {
                bool flag = false;
                if (s[i] == '(') {
                    if (a + 1 <= n) {
                        flag = flag || prev[a + 1];
                    }
                } else if (s[i] == ')') {
                    if (a > 0) {
                        flag = flag || prev[a - 1];
                    }
                } else if (s[i] == '*') {
                    if (a + 1 <= n) {
                        flag = flag || prev[a + 1];
                    }
                    if (a > 0) {
                        flag = flag || prev[a - 1];
                    }
                    flag = flag || prev[a];
                }
                temp[a] = flag;
            }
            prev = temp;
        }

        return prev[0];
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n)

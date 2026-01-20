## Problem statement
- Given an array of strings words[], the task is to return the longest string chain. A string chain is defined as a sequence of words where:
- Each word (except the first) can be formed by inserting exactly one character into the previous word.
- The first word of the chain can be any word from the words[] array.
- The task is to determine the length of the longest chain.

### Recursion
```cpp
class Solution {
public:
    bool compareAndCheck(string& s, string& t) {
        int m = s.length();
        int l = t.length();
        if ((m + 1) != l) {
            return false;
        }
        int count = 0;
        int i = 0;
        int j = 0;
        while (j != l) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        if (i == m && j == l) {
            return true;
        }
        return false;
    }
    int f(int ind, int prev, int& n, vector<string>& words) {
        if (ind == n) {
            return 0;
        }

        int notTake = f(ind + 1, prev, n, words);
        int take = 0;
        if (prev == -1 || compareAndCheck(words[prev], words[ind]) == true) {
            take = 1 + f(ind + 1, ind, n, words);
        }
        return max(notTake, take);
    }
    int longestStrChain(vector<string>& words) {

        int n = words.size();
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
        return f(0, -1, n, words);
    }
};
```
- Time complexity: O(nlogn) + O(L*(2^n)) (L=max length of a word)
- Space complexity: O(n)

### Memoization
```cpp
class Solution {
public:
    bool compareAndCheck(string& s, string& t) {
        int m = s.length();
        int l = t.length();
        if ((m + 1) != l) {
            return false;
        }
        int count = 0;
        int i = 0;
        int j = 0;
        while (j != l) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        if (i == m && j == l) {
            return true;
        }
        return false;
    }
    int f(int ind, int prev, int& n, vector<string>& words,
          vector<vector<int>>& dp) {
        if (ind == n) {
            return 0;
        }
        if (dp[ind][prev + 1] != -1) {
            return dp[ind][prev + 1];
        }
        int notTake = f(ind + 1, prev, n, words, dp);
        int take = 0;
        if (prev == -1 || compareAndCheck(words[prev], words[ind]) == true) {
            take = 1 + f(ind + 1, ind, n, words, dp);
        }
        return dp[ind][prev + 1] = max(notTake, take);
    }
    int longestStrChain(vector<string>& words) {

        int n = words.size();
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, n, words, dp);
    }
};
```
- Time complexity: O(n*n*L) + O(nlogn)
- Space complexity: O(n*n) + O(n)

### Tabulation
```cpp
class Solution {
public:
    bool compareAndCheck(string& s, string& t) {
        int m = s.length();
        int l = t.length();
        if ((m + 1) != l) {
            return false;
        }
        int count = 0;
        int i = 0;
        int j = 0;
        while (j != l) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        if (i == m && j == l) {
            return true;
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {

        int n = words.size();
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 2; j >= -1; j--) {
                int notTake = dp[i + 1][j + 1];
                int take = 0;
                if (j == -1 || compareAndCheck(words[j], words[i]) == true) {
                    take = 1 + dp[i + 1][i + 1];
                }
                dp[i][j + 1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};
```
- Time complexity: O(nlogn) + O(n*n*L)
- Space complexity: O(n*n)

### Space optimized
```cpp
class Solution {
public:
    bool compareAndCheck(string& s, string& t) {
        int m = s.length();
        int l = t.length();
        if ((m + 1) != l) {
            return false;
        }
        int count = 0;
        int i = 0;
        int j = 0;
        while (j != l) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        if (i == m && j == l) {
            return true;
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {

        int n = words.size();
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
       
        vector<int> prev(n+1,0);
        for (int i = n - 1; i >= 0; i--) {
            vector<int> temp(n+1,0);
            for (int j = n - 2; j >= -1; j--) {
                int notTake = prev[j + 1];
                int take = 0;
                if (j == -1 || compareAndCheck(words[j], words[i]) == true) {
                    take = 1 + prev[i + 1];
                }
                temp[j + 1] = max(take, notTake);
            }
            prev=temp;
        }
        return prev[0];
    }
};
```
- Time complexity: O(n*n) + O(nlogn)
- Spce complexity: O(n)

### DP with length array
```cpp
class Solution {
public:
    bool compareAndCheck(string& s, string& t) {
        int m = s.length();
        int l = t.length();
        if ((m + 1) != l) {
            return false;
        }
        int count = 0;
        int i = 0;
        int j = 0;
        while (j != l) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        if (i == m && j == l) {
            return true;
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {

        int n = words.size();
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });

        vector<int> dp(n, 1);
        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (compareAndCheck(words[j], words[i]) == true &&
                    dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};
```
- Time complexity: O(nlogn) + O(n*n)
- Space complexity: O(n)

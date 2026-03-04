## Problem statement
- Given a string s, partition s such that every substring of the partition is a palindrome.
- Return the minimum cuts needed for a palindrome partitioning of s

### Brute force
```cpp
class Solution {
public:
    bool isPalindrome(int l, int r, string& s) {
        while (l <= r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    long long f(int ind, int& n, string& s) {
        if (ind >= n) {
            return 0;
        }
        long long mx = INT_MAX;
        for (int i = ind; i <= n; i++) {
            if (isPalindrome(ind, i, s)) {
                mx = min(mx, 1 + f(i + 1, n, s));
            }
        }
        return mx;
    }
    int minCut(string s) {

        int n = s.length();
        return f(0, n, s) - 1;
    }
};
```
- Time complexity: O(n*(2^n)) (At every character index, the for loop tries to make a "cut" if the prefix is a palindrome.
  In the worst case (like the string "aaaaa"), every possible substring is a palindrome. This creates a branching structure similar to finding all subsets of a set, which is 2^n)
- Space complexity: O(n)

### Memoization
```cpp
class Solution {
public:
    bool isPalindrome(int l, int r, string& s) {
        while (l <= r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    long long f(int ind, int& n, string& s, vector<int>& dp) {
        if (ind >= n) {
            return 0;
        }
        if (dp[ind] != -1) {
            return dp[ind];
        }
        long long mx = INT_MAX;
        for (int i = ind; i <= n; i++) {
            if (isPalindrome(ind, i, s)) {
                mx = min(mx, 1 + f(i + 1, n, s, dp));
            }
        }
        return dp[ind] = mx;
    }
    int minCut(string s) {

        int n = s.length();
        vector<int> dp(n, -1);
        return f(0, n, s, dp) - 1;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n)

### Tabulation
```cpp
class Solution {
public:
    bool isPalindrome(int l, int r, string& s) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    int minCut(string s) {

        int n = s.length();
        vector<long long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            long long mx = INT_MAX;
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j, s)) {
                    mx = min(mx, 1 + dp[j + 1]);
                }
            }
            dp[i] = mx;
        }
        return dp[0] - 1;
    }
};
```
- Tima complexity: O(n*n)
- Space complexity: O(n)

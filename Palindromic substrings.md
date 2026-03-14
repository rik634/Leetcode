## Problem statement
- Given a string s, return the number of palindromic substrings in it.
- A string is a palindrome when it reads the same backward as forward.
- A substring is a contiguous sequence of characters within the string.

### Brute force
``` cpp
class Solution {
public:
    bool isPalindrome(int i, int j, string& s) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {

        int n = s.length();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j, s)) {
                    count++;
                }
            }
        }
        return count;
    }
};
```
- Time complexity: O(n*n*n)
- Space complexity: O(1)

### Better
``` cpp
class Solution {
public:
    int countSubstrings(string s) {

        int n = s.length();
        int count = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            count++;
        }
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                count++;
            }
        }
        for (int diff = 2; diff <= n; diff++) {
            for (int i = 0; i < n - diff; i++) {
                int j = i + diff;
                if (dp[i + 1][j - 1] == 1 && s[i] == s[j]) {
                    dp[i][j] = 1;
                    count++;
                }
            }
        }
        return count;
    }
};
```
- Time complexity: O(n) + O(n) + O(n*n) = O(n*n)
- Space complexity: O(n*n)

### Optimal
- expand for each index on both the sides of string.
`` cpp
class Solution {
public:
    int expand(int l, int r, string& s) {
        int c = 0;
        while (l >= 0 && r < s.length()) {
            if (s[l] != s[r]) {
                return c;
            }
            c++;
            l--;
            r++;
        }
        return c;
    }
    int countSubstrings(string s) {

        int n = s.length();
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += expand(i, i, s);
            count += expand(i, i + 1, s);
        }
        return count;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(1)

### Manacher's algorithm
```cpp
class Solution {
public:
    string preprocess(string s) {
        if (s.empty()) return "^$";
        string res = "^";
        for (char c : s) res += "#" + string(1, c);
        res += "#$"; // Use special markers for boundaries
        return res;
    }

    int countSubstrings(string s) {
        string T = preprocess(s);
        int n = T.length();
        vector<int> P(n, 0);
        int C = 0, R = 0;

        for (int i = 1; i < n - 1; i++) {
            // Use symmetry to initialize P[i]
            int i_mirror = 2 * C - i; 
            if (i < R) {
                P[i] = min(R - i, P[i_mirror]);
            }

            // Attempt to expand around i
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
                P[i]++;
            }

            // Update center and boundary if we found a palindrome reaching further right
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }

        // The count of palindromic substrings is the sum of (P[i] + 1) / 2
        int count = 0;
        for (int v : P) {
            count += (v + 1) / 2;
        }
        return count;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)

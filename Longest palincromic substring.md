## Problem statement
- Given a string s, return the longest palindromic substring in s.

### Brute force
- We are traversing from longest to smlllest string, in order to optimize the solution. SO, that if any string is palindrome, that will be longest palindrome substring.
- This will save our effort to check each and every substring.

```cpp
class Solution {
public:
    bool isPalindrome(int start, int len, string& s) {
        int end = len + start - 1;
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {

        int n = s.length();
        for (int len = n; len > 0; len--) // length
        {
            for (int start = 0; start <= n - len; start++) {
                if (isPalindrome(start, len, s)) {
                    return s.substr(start, len);
                }
            }
        }
        return "";
    }
};
```
- Time complexity: O(n^3)
- Space complexity: O(1)

### Better solution (DP)
- if aaa is palindrome, then baaab can be palindrome .
- Here, first we are checking the smallest possible palindrome string. And if the string is palindrome, we are adding the characters on both side of string and check if the resulting string is palindrome. 
```cpp
class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        string str = "";
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            ans = {i, i};
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                ans = {i, i + 1};
            }
        }

        for (int diff = 2; diff < n; diff++) {
            for (int i = 0; i < n - diff; i++) {
                int j = i + diff;
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    ans = {i, j};
                }
            }
        }
        return s.substr(ans[0], ans[1] - ans[0] + 1);
    }
};
```
- Time complexity: O(n) + O(n) + O(n*n) = O(n^2)
- Space complexity: O(n^2)

### better
- Here, for each index, we are expanding on left and right side until the string continues to be palindrome.
- We will do this for both odd(l=i,r=i) and even (l=i, r=i+1) length string.
```cpp
class Solution {
public:
    string expand(int l, int r, string& s) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l + 1, (r - 1) - (l + 1) + 1);
    }
    string longestPalindrome(string s) {

        int n = s.length();
        string ans = "";
        for (int i = 0; i < n; i++) {
            string odd = expand(i, i, s);
            if (odd.length() > ans.length()) {
                ans = odd;
            }
            string even = expand(i, i + 1, s);
            if (even.length() > ans.length()) {
                ans = even;
            }
        }
        return ans;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(1)


### optimal (manacher's algorithm)
- This is out of scope for interviews
```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        string s_prime = "#";
        for (char c : s) {
            s_prime += c;
            s_prime += "#";
        }

        int n = s_prime.length();
        vector<int> palindrome_radii(n, 0);
        int center = 0;
        int radius = 0;

        for (int i = 0; i < n; i++) {
            int mirror = 2 * center - i;

            if (i < radius) {
                palindrome_radii[i] = min(radius - i, palindrome_radii[mirror]);
            }

            while (i + 1 + palindrome_radii[i] < n &&
                   i - 1 - palindrome_radii[i] >= 0 &&
                   s_prime[i + 1 + palindrome_radii[i]] ==
                       s_prime[i - 1 - palindrome_radii[i]]) {
                palindrome_radii[i]++;
            }

            if (i + palindrome_radii[i] > radius) {
                center = i;
                radius = i + palindrome_radii[i];
            }
        }

        int max_length = 0;
        int center_index = 0;
        for (int i = 0; i < n; i++) {
            if (palindrome_radii[i] > max_length) {
                max_length = palindrome_radii[i];
                center_index = i;
            }
        }

        int start_index = (center_index - max_length) / 2;
        string longest_palindrome = s.substr(start_index, max_length);

        return longest_palindrome;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)


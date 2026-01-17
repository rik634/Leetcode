## Proble statement:
- We are given two strings ‘S1’ and ‘S2’. We need to convert S1 to S2. The following three operations are allowed:
  1. Deletion of a character.
  2. Replacement of a character with another one.
  3. Insertion of a character.
- We have to return the minimum number of operations required to convert S1 to S2 as our answer.

### Logic:
To convert one string to another, we can perform three operations: insert, delete, or replace a character. So, for each character of the two strings, we explore all valid operations recursively.
  1. Represent the problem using two indices i and j, pointing to the current character in S1 and S2 respectively.
  2. If S1[i] == S2[j], no operation is needed. Move both pointers one step back: f(i - 1, j - 1).
  3. If S1[i] != S2[j], we explore all three operations:
  4. Insert: Insert S2[j] into S1. This keeps i unchanged and decreases j: 1 + f(i, j - 1).
  5. Delete: Remove S1[i]. This decreases i and keeps j unchanged: 1 + f(i - 1, j).
  6. Replace: Replace S1[i] with S2[j]. Decrease both indices: 1 + f(i - 1, j - 1).
  7. Among the three operations, return the minimum value.
  8. If either i or j becomes -1, return the number of remaining characters in the other string (i.e., insert all or delete all).

### Recursion:
```cpp
class Solution {
public:
    int f(int i, int j, string& word1, string& word2) {
        if (i < 0) {
            return j + 1;
        }
        if (j < 0) {
            return i + 1;
        }
        // If the characters at the current positions match, no operation is
        // needed
        if (word1[i] == word2[j]) {
            return f(i - 1, j - 1, word1, word2);
        }
        // Minimum of three choices:
        // 1. Replace the character at S1[i] with the character at S2[j]
        // 2. Delete the character at S1[i]
        // 3. Insert the character at S2[j] into S1
        return 1 +
               min(f(i - 1, j - 1, word1, word2),
                   min(f(i - 1, j, word1, word2), f(i, j - 1, word1, word2)));
    }
    int minDistance(string word1, string word2) {

        int n = word1.length();
        int m = word2.length();

        int len = f(n - 1, m - 1, word1, word2);
        return len;
    }
};
```
- Time complexity: O(3^(max(n,m)))
- Space complexity: O(n+m)


### Memoization:
```cpp
class Solution {
public:
    int f(int i, int j, string& word1, string& word2,vector<vector<int>>& dp) {
        if (i < 0) {
            return j + 1;
        }
        if (j < 0) {
            return i + 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        // If the characters at the current positions match, no operation is
        // needed
        if (word1[i] == word2[j]) {
            return f(i - 1, j - 1, word1, word2,dp);
        }
        // Minimum of three choices:
        // 1. Replace the character at S1[i] with the character at S2[j]
        // 2. Delete the character at S1[i]
        // 3. Insert the character at S2[j] into S1
        return 1 +
               min(f(i - 1, j - 1, word1, word2,dp),
                   min(f(i - 1, j, word1, word2,dp), f(i, j - 1, word1, word2,dp)));
    }
    int minDistance(string word1, string word2) {

        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int len = f(n - 1, m - 1, word1, word2,dp);
        return len;
    }
};
```
- Time complexity: O(n*m)
- Space complexity: O(n+m)+ O(n*m)


### Tabulation:
```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {

        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1],
                                       min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }
        int len = dp[n][m];
        return len;
    }
};
```
- Time complexity: O(n) + O(m) + O(n*m)
- Space complexity: O(n*m)

### Space optimzied:
```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {

        int n = word1.length();
        int m = word2.length();

        vector<int> prev(m + 1, 0);
        for (int j = 0; j <= m; j++) {
            prev[j] = j;
        }

        for (int i = 1; i <= n; i++) {
            vector<int> temp(m + 1, 0);
            temp[0] = i;
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    temp[j] = prev[j - 1];
                } else {
                    temp[j] = 1 + min(prev[j - 1], min(prev[j], temp[j - 1]));
                }
            }
            prev = temp;
        }
        int len = prev[m];
        return len;
    }
};
```
- Time complexity: O(n*m) + O(m)
- Space complexity: O(m)

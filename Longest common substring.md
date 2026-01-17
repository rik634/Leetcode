## Problem statement:
- Given two strings str1 and str2, find the length of their longest common substring.
- A substring is a contiguous sequence of characters within a string.

### Logic:
- If S1[i-1] != S2[j-1], the characters at position i-1 and j-1 do not match, which breaks the consecutiveness of the characters in the substring. In this case, we set dp[i][j] to 0 because there is no common substring ending at this point.
- If S1[i-1] == S2[j-1], the characters match. This means that we can extend the current common substring. In this case, we set dp[i][j] = 1 + dp[i-1][j-1]. The reason is that dp[i-1][j-1] gives us the length of the longest common substring until the previous characters (i.e., S1[i-2] and S2[j-2]). As the current characters match, we increment this length by 1 to account for the new matching character.
- It is important to note that dp[n][m] will not give us the answer directly. This is because the longest common substring may not necessarily end at the last character of both strings. Instead, we need to find the maximum value in the entire dp array. The maximum value in the dp array will represent the length of the longest common substring, as it will be the largest length found while traversing through the entire table.

### Recursion:
```cpp
class Solution {
public:
    int solve(int i, int j, string& s1, string& s2, int& maxLen) {
        // Base case: if we run out of characters in either string
        if (i < 0 || j < 0) {
            return 0;
        }

        // We MUST explore all branches to ensure we check every possible start point
        // These calls don't contribute to the current suffix but explore other paths
        solve(i - 1, j, s1, s2, maxLen);
        solve(i, j - 1, s1, s2, maxLen);

        int currentSuffix = 0;
        // If characters match, the length is 1 + length of common suffix before it
        if (s1[i] == s2[j]) {
            currentSuffix = 1 + solveSuffix(i - 1, j - 1, s1, s2);
            // Update the global maximum length found so far
            maxLen = max(maxLen, currentSuffix);
        }

        return currentSuffix;
    }

    // Helper function specifically to find consecutive matches (suffix)
    int solveSuffix(int i, int j, string& s1, string& s2) {
        if (i < 0 || j < 0 || s1[i] != s2[j]) {
            return 0;
        }
        return 1 + solveSuffix(i - 1, j - 1, s1, s2);
    }

    int longestCommonSubstr(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int maxLen = 0;
        
        // Start the recursion
        solve(n - 1, m - 1, str1, str2, maxLen);
        
        return maxLen;
    }
};
```
- Time complexity: O(3^(n+m))
- Space complexity: O(max(n,m))

### Memoization
```cpp
class Solution {
public:
    int solve(int i, int j, string& s1, string& s2, int& maxLen,vector<vector<int>>& dp) {
        // Base case: if we run out of characters in either string
        if (i < 0 || j < 0) {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // We MUST explore all branches to ensure we check every possible start point
        // These calls don't contribute to the current suffix but explore other paths
        solve(i - 1, j, s1, s2, maxLen,dp);
        solve(i, j - 1, s1, s2, maxLen,dp);

        int currentSuffix = 0;
        // If characters match, the length is 1 + length of common suffix before it
        if (s1[i] == s2[j]) {
            currentSuffix = 1 + solveSuffix(i - 1, j - 1, s1, s2);
            // Update the global maximum length found so far
            maxLen = max(maxLen, currentSuffix);
        }

        return dp[i][j]=currentSuffix;
    }

    // Helper function specifically to find consecutive matches (suffix)
    int solveSuffix(int i, int j, string& s1, string& s2) {
        if (i < 0 || j < 0 || s1[i] != s2[j]) {
            return 0;
        }
        return 1 + solveSuffix(i - 1, j - 1, s1, s2);
    }

    int longestCommonSubstr(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int maxLen = 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        // Start the recursion
        solve(n - 1, m - 1, str1, str2, maxLen,dp);
        
        return maxLen;
    }
};
```
- Time complexity: O(n*m)
- Space complexity: O(n*m) + O(max(n,m))

### Tabulation:
```cpp
class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    mx=max(mx,dp[i][j]);
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        return mx;
    }
};
```
- Time complexity: O(n*m)
- Space complexity: O(n*m)

 ### Space optimized
 ```cpp
class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n = s1.length();
        int m = s2.length();
       
        vector<int> prev(m+1,0);
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            vector<int> temp(m+1,0);
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    temp[j]=1+prev[j-1];
                    mx=max(mx,temp[j]);
                }
                else
                {
                    temp[j]=0;
                }
            }
            prev=temp;
        }
        return mx;
    }
};
```
- Time complexity: O(n*m)
- Space complexity: O(m)

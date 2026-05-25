## Problem statement
- You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:
  - i + minJump <= j <= min(i + maxJump, s.length - 1), and
  - s[j] == '0'.
- Return true if you can reach index s.length - 1 in s, or false otherwise.

### Solution
```cpp
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.length();
        if (s[n - 1] == '1') {
            return false;
        }
        vector<bool> dp(n, false);
        dp[0] = true;
        int count = 0;
        for (int i = 1; i < n; i++) {
            if (i >= minJump && dp[i - minJump]) {
                count++;
            }
            if (i > maxJump && dp[i - maxJump - 1]) {
                count--;
            }
            if (s[i] == '0' && count > 0) {
                dp[i] = true;
            }
        }
        return dp[n - 1];
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)

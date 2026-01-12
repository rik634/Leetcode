// level: easy
// problem statement:

// recursion;
class Solution {
public:
    int f(int n) {
        if (n <= 2) {
            return n;
        }
        return f(n - 1) + f(n - 2);
    }
    int climbStairs(int n) { return f(n); }
};
// Time complexity: O(2^n)
// space complexity: O(n) (recursive stack space)

// Memoization
class Solution {
public:
    int f(int n, vector<int>& dp) {
        if (n <= 2) {
            return dp[n] = n;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = f(n - 1, dp) + f(n - 2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};
// Time complexity: O(n)
// space complexity: O(n) (dp) + O(n) (recursive stack space)

// tabulation
class Solution {
public:
    int climbStairs(int n) {

        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        if (n == 1) {
            return 1;
        }
        dp[2] = 2;
        if (n == 2) {
            return dp[n];
        }
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
// Time complexity: O(n)
// space complexity: O(n) (dp)

// space optimized
class Solution {
public:
    int climbStairs(int n) {

        if (n <= 2) {
            return n;
        }
        int prev2 = 1;
        int prev = 2;
        int curr;
        for (int i = 3; i <= n; i++) {
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
// Time complexity: O(n)
// space complexity: O(1)

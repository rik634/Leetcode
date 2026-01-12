// level: medium
// problem statement:

// recursion
class Solution {
public:
    int f(int x, int y) {
        if (x == 0 && y == 0) {
            return 1;
        }
        if (x == 0 || y == 0) {
            return 1;
        }

        int up = f(x - 1, y);
        int left = f(x, y - 1);
        return up + left;
    }
    int uniquePaths(int m, int n) { return f(m - 1, n - 1); }
};
// Time complexity: O(2^(m+n))
// space complexity: O(m+n)

// memmoization
class Solution {
public:
    int f(int x, int y,vector<vector<int>>& dp) {
        if (x == 0 && y == 0) {
            return dp[x][y]=1;
        }
        if (x == 0 || y == 0) {
            return dp[x][y]=1;
        }
        if(dp[x][y]!=-1)
        {
            return dp[x][y];
        }
        int up = f(x - 1, y,dp);
        int left = f(x, y - 1,dp);
        return dp[x][y]=up + left;
    }
    int uniquePaths(int m, int n) { 
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m - 1, n - 1,dp); }
};
// Time complexity: O(m*n)
// space compleity: O(m*n) + O(m+n) (stack space) 

// tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {
            dp[i][0]=1;
        }
        for(int i=0;i<n;i++)
        {
            dp[0][i]=1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
// Time complexity: O(m) + O(n) + O(m*n)
// space complexity: O(m*n)

// space optimized
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<int> prev(n,1);
        for(int i=1;i<m;i++)
        {
            vector<int> temp(n,0);
            temp[0]=1;
            for(int j=1;j<n;j++)
            {
                temp[j]=prev[j]+temp[j-1];
            }
            prev=temp;
        }
        return prev[n-1];
    }
};
// Time complexity: O(m*n)
// Space complexity: O(n)


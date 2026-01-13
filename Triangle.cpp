// Level: Medium
// problem statement:

// recurison:
class Solution {
public:
    int f(int x, int y, vector<vector<int>>& triangle) {
        if (x < 0 || y < 0 || y > x) {
            return 1e8;
        }
        if (x == 0 && y == 0) {
            return triangle[0][0];
        }
        int up = triangle[x][y] + f(x - 1, y, triangle);
        int dig = triangle[x][y] + f(x - 1, y - 1, triangle);
        return min(up, dig);
    }
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        int mnPath = INT_MAX;
        for (int i = 0; i < n; i++) {
            int path = f(n - 1, i, triangle);
            mnPath = min(mnPath, path);
        }
        return mnPath;
    }
};
// time complexity: O(n*(2^n))
// space complexity: O(n)

// Memoization
class Solution {
public:
    int f(int x, int y, vector<vector<int>>& triangle,vector<vector<int>>& dp) {
        if (x < 0 || y < 0 || y > x) {
            return 1e8;
        }
        if (x == 0 && y == 0) {
            return dp[0][0]=triangle[0][0];
        }
        if(dp[x][y]!=INT_MAX)
        {
            return dp[x][y];
        }
        int up = triangle[x][y] + f(x - 1, y, triangle,dp);
        int dig = triangle[x][y] + f(x - 1, y - 1, triangle,dp);
        return dp[x][y]=min(up, dig);
    }
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        int mnPath = INT_MAX;
        for (int i = 0; i < n; i++) {
            int path = f(n - 1, i, triangle,dp);
            mnPath = min(mnPath, path);
        }
        return mnPath;
    }
};
// Time complexity: O(n*n)
// space complexity: O(n*n) + (n)



// tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = triangle[0][0];
                } else {
                    int up = triangle[i][j];
                    if (j <= (i - 1)) {
                        up += dp[i - 1][j];
                    } else {
                        up += 1e8;
                    }
                    int dig = triangle[i][j];
                    if (j - 1 >= 0) {
                        dig += dp[i - 1][j - 1];
                    } else {
                        dig += 1e8;
                    }
                    dp[i][j] = min(up, dig);
                }
            }
        }
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            mn = min(mn, dp[n - 1][i]);
        }
        return mn;
    }
};
// time complexity: O(n^2)
// space complexity: O(n^2)

// space optimized
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        vector<int> prev(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            vector<int> temp(i + 1, INT_MAX);
            for (int j = 0; j <= i; j++) {
                if (i == 0 && j == 0) {
                    temp[j] = triangle[0][0];
                } else {
                    int up = triangle[i][j];
                    if (j <= (i - 1)) {
                        up += prev[j];
                    } else {
                        up += 1e8;
                    }
                    int dig = triangle[i][j];
                    if (j - 1 >= 0) {
                        dig += prev[j - 1];
                    } else {
                        dig += 1e8;
                    }
                    temp[j] = min(up, dig);
                }
            }
            prev = temp;
        }
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            mn = min(mn, prev[i]);
        }
        return mn;
    }
};
// time complexity: O(n^2)
// space complexity: O(n)

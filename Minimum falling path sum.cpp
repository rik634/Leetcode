// level: Medium
// problem statement: 

// recursion:
class Solution {
public:
    int f(int x, int y, vector<vector<int>>& matrix) {
        if (x < 0 || y < 0) {
            return 1e8;
        }
        if (x == 0) {
            return matrix[x][y];
        }
        int up = matrix[x][y] + f(x - 1, y, matrix);
        int dLeft = 1e8;
        int dRight = 1e8;
        if ((y - 1) >= 0) {
            dLeft = matrix[x][y] + f(x - 1, y - 1, matrix);
        }
        if ((y + 1) < matrix.size()) {
            dRight = matrix[x][y] + f(x - 1, y + 1, matrix);
        }
        return min(up, min(dLeft, dRight));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = f(n - 1, i, matrix);
            mn = min(mn, sum);
        }
        return mn;
    }
};
// Time complexity: O(n*(3^n))
// space complexity: O(n) (recursive stack space)

// Memoization
class Solution {
public:
    int f(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (x < 0 || y < 0) {
            return 1e8;
        }
        if (x == 0) {
            return dp[x][y] = matrix[x][y];
        }
        if (dp[x][y] != 1e8) {
            return dp[x][y];
        }
        int up = matrix[x][y] + f(x - 1, y, matrix, dp);
        int dLeft = 1e8;
        int dRight = 1e8;
        if ((y - 1) >= 0) {
            dLeft = matrix[x][y] + f(x - 1, y - 1, matrix, dp);
        }
        if ((y + 1) < matrix.size()) {
            dRight = matrix[x][y] + f(x - 1, y + 1, matrix, dp);
        }
        return dp[x][y] = min(up, min(dLeft, dRight));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e8));
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = f(n - 1, i, matrix, dp);
            mn = min(mn, sum);
        }
        return mn;
    }
};
// Time complexity:    Time complexity: O(n*n)
// space complexty: O(n*n) + O(n+n)

// tabulation:
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e8));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    dp[i][j] = matrix[i][j];
                } else {
                    int up = matrix[i][j] + dp[i - 1][j];
                    int dL = 1e8;
                    int dR = 1e8;
                    if ((j - 1) >= 0) {
                        dL = matrix[i][j] + dp[i - 1][j - 1];
                    }
                    if ((j + 1) < n) {
                        dR = matrix[i][j] + dp[i - 1][j + 1];
                    }
                    dp[i][j] = min(up, min(dL, dR));
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
// Time complexity: O(n*n)
// space complexity: O(n*n)

// space optimzied
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<int> prev(n, 1e8);
        for (int i = 0; i < n; i++) {
            vector<int> temp(n, 1e8);
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    temp[j] = matrix[i][j];
                } else {
                    int up = matrix[i][j] + prev[j];
                    int dL = 1e8;
                    int dR = 1e8;
                    if ((j - 1) >= 0) {
                        dL = matrix[i][j] + prev[j - 1];
                    }
                    if ((j + 1) < n) {
                        dR = matrix[i][j] + prev[j + 1];
                    }
                    temp[j] = min(up, min(dL, dR));
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
// Time complexity: O(n*n)
// space complexity: O(n)

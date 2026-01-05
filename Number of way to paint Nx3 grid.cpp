// level: hard
// problem statement:

// brute force (backtracking)
class Solution {
public:
    int solveGrid(int r, int c, int& n, vector<vector<int>>& grid) {
        if (r == n) {
            return 1;
        }
        int next_r = (c == 2) ? r + 1 : r;
        int next_c = (c == 2) ? 0 : c + 1;
        long long count = 0;
        for (int color = 1; color <= 3; color++) {
            if (r > 0 && grid[r - 1][c] == color) {
                continue;
            }
            if (c > 0 && grid[r][c - 1] == color) {
                continue;
            }
            grid[r][c] = color;
            count = count + solveGrid(next_r, next_c, n, grid);
            grid[r][c] = 0;
        }
        return count;
    }
    int numOfWays(int n) {

        vector<vector<int>> grid(n, vector<int>(3, 0));
        return solveGrid(0, 0, n, grid);
    }
};
// time complexity: O(3^(3*n))
// space complexity: O(3*n) (space) + O(3*n) (recursion stack trace)


//space optimized (pattern based):
class Solution {
public:
    int numOfWays(int n) {
        
        const int MOD=1e9+7;
        long long x=6,y=6;
        long long new_x,new_y;
        for(int i=2;i<=n;i++)
        {
            new_x = (3*x+2*y)%MOD;
            new_y=(2*x+2*y)%MOD;
            x=new_x;
            y=new_y;
        }
        return (x+y)%MOD;
    }
};
// time complexity: O(n)
// space complexity: O(1)

// optimized

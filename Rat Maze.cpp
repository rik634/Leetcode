// problem statement:  Given a grid of dimensions n x n. A rat is placed at coordinates (0, 0) and wants to reach at coordinates (n-1, n-1). Find all possible paths that rat can take to travel from (0, 0) to (n-1, n-1). 
//The directions in which rat can move are 'U' (up) , 'D' (down) , 'L' (left) , 'R' (right).
//The value 0 in grid denotes that the cell is blocked and rat cannot use that cell for travelling, whereas value 1 represents that rat can travel through the cell. If the cell (0, 0) has 0 value, then mouse cannot move to any other cell.

// solution: 
class Solution {
public:
    // Function to check if the cell is within maze and valid to move
    bool isSafe(int x, int y, int n, vector<vector<int>> &maze, 
                vector<vector<int>> &visited) {
        return (x >= 0 && x < n && y >= 0 && y < n && 
                maze[x][y] == 1 && visited[x][y] == 0);
    }

    // Function to solve maze using backtracking
    void solve(int x, int y, int n, vector<vector<int>> &maze, 
               vector<vector<int>> &visited, string path, 
               vector<string> &res) {

        // If destination reached, store the path
        if (x == n - 1 && y == n - 1) {
            res.push_back(path);
            return;
        }

        // Mark the cell visited
        visited[x][y] = 1;

        // Try moving Down
        if (isSafe(x + 1, y, n, maze, visited)) {
            solve(x + 1, y, n, maze, visited, path + "D", res);
        }
        // Try moving Left
        if (isSafe(x, y - 1, n, maze, visited)) {
            solve(x, y - 1, n, maze, visited, path + "L", res);
        }
        // Try moving Right
        if (isSafe(x, y + 1, n, maze, visited)) {
            solve(x, y + 1, n, maze, visited, path + "R", res);
        }
        // Try moving Up
        if (isSafe(x - 1, y, n, maze, visited)) {
            solve(x - 1, y, n, maze, visited, path + "U", res);
        }

        // Backtrack: unmark cell as visited
        visited[x][y] = 0;
    }

    // Main function to find all paths
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        vector<string> res;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        if (maze[0][0] == 1) {
            solve(0, 0, n, maze, visited, "", res);
        }
        return res;
    }
};
// time complexity: O(4^(N*N)),, because on every cell we need to try 4 different directions.
//Space Complexity: O(N*N), additional space for visited array and maximum Depth of the recursion tree(auxiliary space).

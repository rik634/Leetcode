// level: Medium
// problem statement: You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of the cell (row, col). 
//You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e.,0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
//A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// solution:
class Solution {
public:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    int minimumEffortPath(vector<vector<int>>& heights) {

        int row = heights.size();
        int col = heights[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
        dist[0][0] = 0;
        q.push({0, {0, 0}});

        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            int x = p.first;
            int y = p.second.first;
            int diff = p.second.second;

            for (int i = 0; i < 4; i++) {
                int r = dx[i] + x;
                int c = dy[i] + y;
                if (r >= 0 && r < row && c >= 0 && c < col) {
                    int w = abs(heights[r][c] - heights[x][y]);
                    if (dist[r][c] > max(diff, w)) {
                        dist[r][c] = max(diff, w);
                        q.push({r, {c, dist[r][c]}});
                    }
                }
            }
        }
        return dist[row - 1][col - 1];
    }
};
// Time complexity: O(4*row*col)
// space complexity:O(row*col)

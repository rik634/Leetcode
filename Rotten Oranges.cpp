// level: Medium
// problem statement: Given an n x m grid, where each cell has the following values : 2 - represents a rotten orange , 1 - represents a Fresh orange , 0 - represents an Empty Cell .
//Every minute, if a fresh orange is adjacent to a rotten orange in 4-direction ( upward, downwards, right, and left ) it becomes rotten.
//Return the minimum number of minutes required such that none of the cells has a Fresh Orange. If it's not possible, return -1..

// solution (BFS)
class Solution {
public:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int total = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    total++;
                }
            }
        }
        if (total == 0) {
            return 0;
        }
        int time = -1;
        int count = 0;
        while (!q.empty()) {
            int size = q.size();
            time++;

            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;
                for (int j = 0; j < 4; j++) {
                    int x = dx[j] + r;
                    int y = dy[j] + c;
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        count++;
                        q.push({x, y});
                    }
                }
            }
        }
        if (count == total) {
            return time;
        }
        return -1;
    }
};
//Time Complexity: O(n × n × 4) In the worst case, every cell in the grid may contain an orange, and for each rotten orange we explore 4 directions (up, down, left, right). 
       //So we iterate through all cells (n × n) and perform 4 operations per orange. Hence, the complexity becomes O(n × n × 4), which simplifies to O(n²).
//Space Complexity: O(n × n) In the worst case, all the oranges might be rotten and will be stored in the queue simultaneously. 
       //The maximum size of the queue can be equal to the total number of oranges in the grid, i.e., n × n. Therefore, the space complexity is O(n²).

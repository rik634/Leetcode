## Problem statement
- A robot on an infinite XY-plane starts at point (0, 0) facing north. The robot receives an array of integers commands, which represents a sequence of moves that it needs to execute. There are only three possible types of instructions the robot can receive:
  1. -2: Turn left 90 degrees.
  2. -1: Turn right 90 degrees.
  3. 1 <= k <= 9: Move forward k units, one unit at a time.
- Some of the grid squares are obstacles. The ith obstacle is at grid point obstacles[i] = (xi, yi). If the robot runs into an obstacle, it will stay in its current location (on the block adjacent to the obstacle) and move onto the next command.
- Return the maximum squared Euclidean distance that the robot reaches at any point in its path (i.e. if the distance is 5, return 25).
- Note:

- There can be an obstacle at (0, 0). If this happens, the robot will ignore the obstacle until it has moved off the origin. However, it will be unable to return to (0, 0) due to the obstacle.
- North means +Y direction.
- East means +X direction.
- South means -Y direction.
- West means -X direction.

### Solution
```cpp
class Solution {
public:
    vector<int> dir = {'N', 'E', 'S', 'W'};
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        int ind = 0;
        int n = commands.size();
        set<pair<int, int>> st;
        for (auto it : obstacles) {
            st.insert({it[0], it[1]});
        }
        int mx = INT_MIN;
        int x = 0;
        int y = 0;
        for (int i = 0; i < n; i++) {
            if (commands[i] == -2) {
                ind = (ind == 0) ? 3 : ind - 1;
            } else if (commands[i] == -1) {
                ind = (ind == 3) ? 0 : ind + 1;
            } else {
                int k = commands[i];
                for (int i = 1; i <= k; i++) {

                    if (st.find({x + dx[ind], y + dy[ind]}) == st.end()) {
                        x += dx[ind];
                        y += dy[ind];
                    } else {
                        break;
                    }
                }
            }
            mx = max(mx, x * x + y * y);
        }
        return mx;
    }
};
```
- Time complexity: O(mlogm) (m=number of obstacles) + O(n*k*logm) (find operation on set)
- Space complexity: O(m)

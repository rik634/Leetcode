## Problem statement
- You are given an m x n matrix of characters boxGrid representing a side-view of a box. Each cell of the box is one of the following:
- - A stone '#'
  - A stationary obstacle '*'
  - Empty '.'
- The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.
- It is guaranteed that each stone in boxGrid rests on an obstacle, another stone, or the bottom of the box.
- Return an n x m matrix representing the box after the rotation described above.

### Solution
```cpp
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>> res(n, vector<char>(m, '.'));
        for (int i = 0; i < m; i++) // col
        {
            int x = m - 1 - i;
            int j = n - 1;
            for (int y = n - 1; y >= 0; y--) // row
            {
                if (boxGrid[x][y] == '.') {
                    continue;
                } else if (boxGrid[x][y] == '*') {
                    res[y][i] = '*';
                    j = y - 1;
                } else {
                    res[j][i] = '#';
                    j--;
                }
            }
        }
        return res;
    }
};
```
- Time complexity: O(mn)
- Space complexity: O(mn)

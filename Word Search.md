## Problem statement
- Given an m x n grid of characters board and a string word, return true if word exists in the grid.
- The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

### Solution
```cpp
class Solution {
public:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    bool dfs(int ind, int x, int y, vector<vector<char>>& board, string& word) {

        if (board[x][y] != word[ind]) {
            return false;
        }
        if (ind == word.length() - 1) {
            return true;
        }

        char temp = board[x][y];
        board[x][y] = '#';
        for (int i = 0; i < 4; i++) {
            int r = dx[i] + x;
            int c = dy[i] + y;
            if (r >= 0 && r < board.size() && c >= 0 && c < board[0].size()) {
                if (dfs(ind + 1, r, c, board, word)) {
                    return true;
                }
            }
        }
        board[x][y] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(0, i, j, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};
```
- Time complexity: O(m*n*(4^L))
- Space complexity: O(L)

## Problem statement
- You are given coordinates, a string that represents the coordinates of a square of the chessboard. Below is a chessboard for your reference.
- Return true if the square is white, and false if the square is black.
- The coordinate will always represent a valid chessboard square. The coordinate will always have the letter first, and the number second.

### Solution
```cpp
class Solution {
public:
    bool squareIsWhite(string coordinates) {

        int x = coordinates[0] - 'a';
        int y = coordinates[1] - '1';

        if ((x % 2 == 0 && y % 2 != 0) || (x % 2 != 0 && y % 2 == 0)) {
            return true;
        }
        return false;
    }
};
```
- TC - O(1)
- SC= O(1)

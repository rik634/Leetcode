## Problem statement
- You are given a string moves of length n consisting only of characters 'L', 'R', and '_'. The string represents your movement on a number line starting from the origin 0.
- In the ith move, you can choose one of the following directions:
  1. move to the left if moves[i] = 'L' or moves[i] = '_'
  2. move to the right if moves[i] = 'R' or moves[i] = '_'
- Return the distance from the origin of the furthest point you can get to after n moves.

### Solution
```cpp
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {

        int count = 0;
        int add = 0;
        for (auto it : moves) {
            if (it == 'L') {
                count--;
            } else if (it == '_') {
                add++;
            } else {
                count++;
            }
        }
        if (count >= 0) {
            return count + add;
        }
        return abs(count) + add;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)

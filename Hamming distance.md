## Problem statement
- The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
- Given two integers x and y, return the Hamming distance between them.

### Solution
```cpp
class Solution {
public:
    int hammingDistance(int x, int y) { return __builtin_popcount(x ^ y); }
};
```
- Time complexity: O(1)
- Space complexity: O(1)

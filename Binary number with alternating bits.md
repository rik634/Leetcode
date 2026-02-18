## Problem statement
- Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

### Solution
```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int rem = n%2;
        n=n/2;
        while(n>0)
        {
            if(rem==n%2)
            {
                return false;
            }
            rem = n%2;
            n=n/2;
        }   
        return true;
    }
};
```
- time complexity: O(d) (d=number of bits)
- Space complexity: O(1)

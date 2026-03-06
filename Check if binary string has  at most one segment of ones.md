## Problem statement
- Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.

### Solution
```cpp
class Solution {
public:
    bool checkOnesSegment(string s) {

        int n = s.length();
        if (n == 1) {
            return true;
        }
        int one = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                one++;
            } else {
                if (one >= 1) {
                    count++;
                }
                one = 0;
            }
        }
        if (one >= 1) {
            count++;
        }

        return count <= 1;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)

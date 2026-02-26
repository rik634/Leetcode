## Problem statement
- Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:
  1. If the current number is even, you have to divide it by 2.
  2. If the current number is odd, you have to add 1 to it.
- It is guaranteed that you can always reach one for all test cases.

### Solution:
```cpp
class Solution {
public:
    int numSteps(string s) {

        int n = s.length();
        int count = 0;
        while (s != "1") {
            count++;
            if (s.back() == '0') {
                s.pop_back();
            } else {
                int i = s.length() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                if (i < 0) {
                    s = '1' + s;
                } else {
                    s[i] = '1';
                }
            }
        }
        return count;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)

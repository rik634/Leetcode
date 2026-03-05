## Problem statement
- You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.
- The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.
- Return the minimum number of operations needed to make s alternating.

### Solution
```cpp
class Solution {
public:
    int minOperations(string s) {

        int n = s.length();
        int c1 = 0;
        int c2 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                c1 += (s[i] == '0') ? 0 : 1;
            } else {
                c1 += (s[i] == '1') ? 0 : 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                c2 += (s[i] == '1') ? 0 : 1;
            } else {
                c2 += (s[i] == '0') ? 0 : 1;
            }
        }
        return min(c1, c2);
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)

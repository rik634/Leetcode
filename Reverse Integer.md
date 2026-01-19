## Problem statament:
- Given an integer N return the reverse of the given number.
- Note: If a number has trailing zeros, then its reverse will not include them. For e.g , reverse of 10400 will be 401 instead of 00401.

### Solution
```cpp
class Solution {
public:
    int reverse(int x) {

        int flag = 0;
        if (x < 0) {
            flag = 1;
        }
        long long num = 0;
        long long rev = abs((long long)x);
        while (rev > 0) {
            int rem = rev % 10;
            num = num * 10 + rem;
            rev = rev / 10;
        }
        if (num > INT_MAX || num < INT_MIN) {
            return 0;
        }

        if (flag == 1) {
            return -1 * num;
        }
        return num;
    }
};
```
- Time complexity: O(d)
- Space complexity: O(1)

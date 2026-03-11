## Problem statement
- The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
- For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
-
- Given an integer n, return its complement.


### Solution
```cpp
class Solution {
public:
    int bitwiseComplement(int n) {

        if (n == 0) {
            return 1;
        }
        int temp = n;
        string str = "";
        while (temp > 0) {
            str += (temp % 2 == 0) ? '1' : '0';
            temp = temp / 2;
        }
        reverse(str.begin(), str.end());

        return (int)stoi(str, 0, 2);
    }
};
```
- Time complexity: O(logn)
- Space complexity: O(1)

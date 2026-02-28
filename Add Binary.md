## Problem statement
- Given two binary strings a and b, return their sum as a binary string.

### Solution
```cpp
class Solution {
public:
    string addBinary(string a, string b) {

        int m = a.length();
        int n = b.length();

        int i = m - 1;
        int j = n - 1;
        string s = "";
        int carry = 0;

        while (i >= 0 && j >= 0) {
            if (a[i] == '0' && b[j] == '0') {
                s += (carry == 0) ? '0' : '1';
                carry = 0;
            } else if ((a[i] == '0' && b[j] == '1') ||
                       (a[i] == '1' && b[j] == '0')) {

                s += (carry == 0) ? '1' : '0';
                carry = (carry == 0) ? 0 : 1;
            } else if (a[i] == '1' && b[j] == '1') {
                s += (carry == 0) ? '0' : '1';
                carry = 1;
            }
            i--;
            j--;
        }
        while (i >= 0) {
            if (a[i] == '0') {
                s += (carry == 0) ? '0' : '1';
                carry = 0;
            } else {
                s += (carry == 0) ? '1' : '0';
            }
            i--;
        }
        while (j >= 0) {
            if (b[j] == '0') {
                s += (carry == 0) ? '0' : '1';
                carry = 0;
            } else {
                s += (carry == 0) ? '1' : '0';
            }
            j--;
        }
        if (carry == 1) {
            s += '1';
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
```
- Time complexity: O(max(m,n))
- Space complexity: O(max(m,n))

## Problem statement


### Solution
```cpp
class Solution {
public:
    string invert(string str) {
        for (int j = 0; j < str.length(); j++) {
            str[j] = (str[j] == '0') ? '1' : '0';
        }
        return str;
    }
    char findKthBit(int n, int k) {

        string s = "0";
        for (int i = 2; i <= n; i++) {
            string temp = s;
            string inv = invert(temp);
            reverse(inv.begin(), inv.end());
            s = temp + "1" + inv;
        }
        return s[k - 1];
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n)

### Optimized

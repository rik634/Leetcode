## Problem statement
- Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

### Brute force
```cpp
class Solution {
public:
    bool hasAllCodes(string s, int k) {

        if (k > s.length()) {
            return false;
        }
        unordered_set<string> st;

        for (int i = 0; i <= s.length() - k; i++) {
            st.insert(s.substr(i, k));
        }
        int total = (int)pow(2, k);
        return total == st.size();
    }
};
```
- Time complexity: O(n)
- Space complexity:O(2^k)

## Problem statement
- You are given a string s of length n consisting of lowercase English letters.
- Return the smallest index i such that s[i] == s[n - i - 1].
- If no such index exists, return -1.

### Solution
```cpp
class Solution {
public:
    int firstMatchingIndex(string s) {

        int n = s.length();
        int i = 0;
        int j = n - 1;
        while (i <= j) {
            if (s[i] == s[j]) {
                return i;
            }
            i++;
            j--;
        }
        return -1;
    }
};
```
- Time complexity: O(logn)
- Space complexity: O(1)

## Problem statement
- Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

### Solution
```cpp

class Solution {
public:
    int firstUniqChar(string s) {

        unordered_map<char, int> mp;
        for (auto it : s) {
            mp[it]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (mp[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)

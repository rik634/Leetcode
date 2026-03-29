## Problem statement
- You are given two strings s1 and s2, both of length 4, consisting of lowercase English letters.
- You can apply the following operation on any of the two strings any number of times:
  1. Choose any two indices i and j such that j - i = 2, then swap the two characters at those indices in the string.
- Return true if you can make the strings s1 and s2 equal, and false otherwise

### Solution
```cpp
class Solution {
public:
    bool canBeEqual(string s1, string s2) {

        int n = s1.length();
        unordered_map<char, int> mp;
        int i = 0;
        int j = 0;
        while (i < 4 && j < 4) {

            if (s1[i] != s2[j]) {
                if (i + 2 < 4 && s1[i + 2] == s2[j]) {
                    char temp = s1[i + 2];
                    s1[i + 2] = s1[i];
                    s1[i] = temp;
                } else {
                    return false;
                }
            }
            i++;
            j++;
        }
        return true;
    }
};
```
- Time complexity: O(1)
- Space complexity: O(1)

## Problem statement
- You are given a string s consisting only of the characters 'a', 'b', and 'c'.
- A substring of s is called balanced if all distinct characters in the substring appear the same number of times.
- Return the length of the longest balanced substring of s.

### Brute force
```cpp
class Solution {
public:
    int longestBalanced(string s) {

        int n = s.length();
        unordered_map<char, int> mp;
        int u = 0;
        int f = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mp.clear();
            u = 0;
            f = 0;
            for (int j = i; j < n; j++) {
                if (mp.find(s[j]) == mp.end()) {
                    u++;
                }
                mp[s[j]]++;
                f = max(f, mp[s[j]]);

                if (u * f == (j - i + 1)) {
                    mx = max(mx, j - i + 1);
                }
            }
        }
        return mx;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(1)

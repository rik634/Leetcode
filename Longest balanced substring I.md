## Problem statement
- You are given a string s consisting of lowercase English letters.
- A substring of s is called balanced if all distinct characters in the substring appear the same number of times.
- Return the length of the longest balanced substring of s.


### Brute force:
```cpp
class Solution {
public:
    bool checkALL(unordered_map<char, int>& mp) {
        int t = -1;
        for (auto it : mp) {
            if (t == -1) {
                t = it.second;
            } else if (it.second != t) {
                return false;
            }
        }
        return true;
    }
    int longestBalanced(string s) {

        int n = s.length();
        int mx = 0;

        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp.clear();
            for (int j = i; j < n; j++) {
                mp[s[j]]++;
                if (checkALL(mp)) {
                    mx = max(mx, j - i + 1);
                }
            }
        }
        return mx;
    }
};
```
- Time complexity: O(n*n*n)
- Space complexity: O(k) (k~=n)

### Optimized
```cpp
class Solution {
public:
    int longestBalanced(string s) {

        int n = s.length();
        int mx = 0;

        for (int i = 0; i < n; i++) {
            vector<int> mp(26, 0);
            int u = 0;
            int f = 0;
            for (int j = i; j < n; j++) {
                // There was no this char before => one more uniq
                if (mp[s[j] - 'a'] == 0) {
                    u++;
                }
                mp[s[j] - 'a']++;
                f = max(f, mp[s[j] - 'a']);
                
                // Check if all uniq chars have maxfreq frequency then update the result
                if ((j - i + 1) == u * f && mx < (j - i + 1)) {
                    mx = j - i + 1;
                }
            }
        }
        return mx;
    }
};
```
- Time complexity: O(n*n)
- space complexity: O(26) = O(1)

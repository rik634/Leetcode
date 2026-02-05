## Problem statement
- Given a string, S. Find the length of the longest substring without repeating characters.

### Brute force
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();

        int mx = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<char> st;
            for (int j = i; j < n; j++) {
                if (st.find(s[j]) != st.end()) {
                    break;
                }
                st.insert(s[j]);
                mx = max(mx, j - i + 1);
            }
        }
        return mx;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n)

### Optimal
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        int l=0;
        int r=0;
        int mx=0;
        unordered_set<char> st;
        while(r<n)
        {
            while(st.find(s[r])!=st.end())
            {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            mx=max(mx,r-l+1);
            r++;
        }
        return mx;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)

### more optimized: The "Jump" Optimization
- Instead of using a set and incrementing l one by one, we can store the last seen index of each character. When we hit a duplicate, we don't slide; we jump the left pointer directly to the position after the last occurrence of that character.

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        int l=0;
        int r=0;
        int mx=0;
        unordered_map<char,int> mp;
        while(r<n)
        {
             // If the character was seen before AND it's within our current window
            if(mp.find(s[r])!=mp.end() && mp[s[r]]>=l)
            {
                l=mp[s[r]]+1;
            }
            mp[s[r]]=r;
            mx=max(mx,r-l+1);
            r++;
        }
        return mx;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(min(m,n)) (n is the total length of the string.m is the size of the character set (e.g., 26 for lowercase English, 128 for ASCII, or much larger for Unicode))

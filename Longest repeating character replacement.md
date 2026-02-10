## Problem statement
- Given an integer k and a string s, any character in the string can be selected and changed to any other uppercase English character.
- This operation can be performed up to k times. After completing these steps, return the length of the longest substring that contains the same letter.

### Brute force
```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.length();
        int mx=0;
        int mxLen=0;
        for(int i=0;i<n;i++){
            mx=0;
            unordered_map<char,int> mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                mx=max(mx,mp[s[j]]);
                int m = mx;
                int len = j-i+1;
                int extra = len-m;
                if(extra>k)
                {
                    break;
                }
                mxLen=max(mxLen,j-i+1);
            }
        }
        return mxLen;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n)

### Optimized:
```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.length();
        int mxLen = 0;
        int l = 0;
        int r = 0;
        unordered_map<char, int> mp;
        int mx = 0;
        while (r < n) {
            mp[s[r]]++;
            mx = max(mx, mp[s[r]]);
            int len = r - l + 1;
            int extra = len - mx;
            while ((r - l + 1 - mx) > k) {
                mp[s[l]]--;
                l++;
            }
            mxLen = max(mxLen, r - l + 1);
            r++;
        }
        return mxLen;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)


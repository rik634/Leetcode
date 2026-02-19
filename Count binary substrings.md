## Problem statement


### Brute force
```cpp
class Solution {
public:
    int countBinarySubstrings(string s) {

        int n = s.length();
        vector<int> group(n, 0);
        group[0] = 1;
        int ind = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                group[++ind] = 1;
            } else {
                group[ind]++;
            }
        }
        int res = 0;
        for (int i = 1; i < n; i++) {
            res += min(group[i], group[i - 1]);
        }
        return res;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)


## linear 
```cpp
class Solution {
public:
    int countBinarySubstrings(string s) {

        int n = s.length();
        int res=0;
        int prev=0;
        int curr=1;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
               res+=min(prev,curr);
               prev=curr;
               curr=1;
            } else {
              curr++;
            }
        }
        res+=min(prev,curr);
        return res;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)
  

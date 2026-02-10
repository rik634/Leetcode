## Problem statement
- Given a string s , consisting only of characters 'a' , 'b' , 'c'.Find the number of substrings that contain at least one occurrence of all these characters 'a' , 'b' , 'c'.

### Brute force
```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.length();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int a = 0, b = 0, c = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == 'a') {
                    a++;
                } else if (s[j] == 'b') {
                    b++;
                } else {
                    c++;
                }
                if (a > 0 && b > 0 && c > 0) {
                    count++;
                }
            }
        }
        return count;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(1)

### Optimized
```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.length();
        int l = 0;
        int r = 0;
        vector<int> freq(3, 0);
        int count = 0;
        while (r < n) {
            freq[s[r] - 'a']++;
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                count += (n - r);
                freq[s[l] - 'a']--;
                l++;
            }
            r++;
        }
        return count;
    }
};
```
- Time complexity: O(n)
- Space complexity:O(1)

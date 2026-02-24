## Problem statement
- Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.
- Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

### Using rabin karp algorithm
```cpp
class Solution {
public:
    int d = 256;
    int q = 1e9 + 7;
    bool rabinKarp(string pattern, string text) {
        int m = pattern.length();
        int n = text.length();
        long long h = 1;
        long long p = 0; // initial hash for pattern
        long long t = 0; // initial hash for text

        for (int i = 0; i < m - 1; i++) {
            h = (h * d) % q;
        }

        for (int i = 0; i < m; i++) {
            p = (d * p + pattern[i]) % q;
            t = (d * t + text[i]) % q;
        }
        for (int i = 0; i <= (n - m); i++) {
            if (p == t) {
                int j;
                for (j = 0; j < m; j++) {
                    if (pattern[j] != text[i + j]) {
                        break;
                    }
                }
                if (j == m) {
                    return true;
                }
            }
            if (i < (n - m)) {
                t = (d * (t - text[i] * h) + text[i + m]) % q;
                if (t < 0) {
                    t = t + q;
                }
            }
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {

        int count = 1;
        string temp = a;
        while (temp.length() < b.length()) {
            count++;
            temp = temp + a;
        }
        if (temp == b) {
            return count;
        }
        if (rabinKarp(b, temp)) {
            return count;
        }
        if (rabinKarp(b, temp + a)) {
            return count + 1;
        }
        return -1;
    }
};
```
- Time complexity: O(n+m)
- Space complexity: O(n+m) This is required to store the concatenated version of string a.

### Using KMP algorithm

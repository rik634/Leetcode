## Problem statement
- The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
  1. countAndSay(1) = "1"
  2. countAndSay(n) is the run-length encoding of countAndSay(n - 1).
- Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run).
- For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".
- Given a positive integer n, return the nth element of the count-and-say sequence.


### Solution
```cpp
class Solution {
public:
    string countAndSay(int n) {

        if (n == 1) {
            return "1";
        }
        string prev = "1";
        for (int i = 2; i <= n; i++) {
            char ch = prev[0];
            int f = 1;
            string temp = "";
            for (int j = 1; j < prev.length(); j++) {
                if (prev[j] == ch) {
                    f++;
                } else {
                    temp += to_string(f) + ch;
                    ch = prev[j];
                    f = 1;
                }
            }
            temp += to_string(f) + ch;
            prev = temp;
        }
        return prev;
    }
};
```
- Time Complexity: O(n * 2^n), there can be n iterations, with string length of upto 2^n characters.
- Space Complexity: O(2^n), Final string length can reach upto 2^n

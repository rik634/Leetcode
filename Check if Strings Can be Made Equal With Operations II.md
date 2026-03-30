## Problem statement
- You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.
- You can apply the following operation on any of the two strings any number of times:
  1. Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.
- Return true if you can make the strings s1 and s2 equal, and false otherwise

### Logic:
- Imagine you have two strings, and you are allowed to shuffle the letters around. Usually, to see if they are "the same," you just count the letters. But here, even-indexed letters never mix with odd-indexed letters.
- Think of it like two separate tracks:
  1. The Even Track: Indices 0, 2, 4, 6...
  2. The Odd Track: Indices 1, 3, 5, 7...
- For s1 to become s2, the letters on the Even Track of s1 must be exactly the same as the letters on the Even Track of s2. The same goes for the Odd Track.
- The code uses a single array called counts with 256 slots. To keep the Even Track and Odd Track from mixing, it splits the array in half:
  1. Slots 0–127: Used for characters at Even positions.
  2. Slots 128–255: Used for characters at Odd positions.
- The line int offset = (i & 1) << 7; is just a fancy way of saying:
  1. If i is even (0, 2, 4...$), offset = 0.
  2. If i is odd (1, 3, 5...$), offset = 128.
- When the code does counts[offset + s1[i]]++, it’s putting the character into the correct "half" of the array based on its position.
- After the loop finishes, the code checks every single slot in that 256-slot array.
  1. If a slot is positive, s1 had more of that character at that parity than s2.
  2. If a slot is negative, s2 had more.
  3. If all slots are 0, it means the characters matched perfectly on both tracks!
- 


### Solution
```cpp
class Solution {
public:
    bool checkStrings(string s1, string s2) {

        if (s1.length() != s2.length()) {
            return false;
        }
        vector<int> count(256, 0);

        for (int i = 0; i < s1.length(); i++) {
            int offset = (i & 1) << 7;
            count[offset + s1[i]]++;
            count[offset + s2[i]]--;
        }

        for (int i = 0; i < 256; i++) {
            if (count[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
```
- Time complexity: O(N)
- Space complexity: O(1)

## Problem statement
- Reverse bits of a given 32 bits signed integer.

### Logic
Approach
- Initialize a variable res to 0.
- Run a loop 32 times (since it's a 32-bit integer).
- In each iteration: 
  - Left-shift res by 1 (res <<= 1).
  - Extract the last bit of n using the bitwise AND operator (n & 1) and add it to res.
  - Right-shift n by 1 (n >>= 1).
- After the loop, res will contain the reversed bits.
- Note on Signed Integers:
  - In C++, bitwise operations on signed integers (especially right shifts) can behave differently depending on the compiler (arithmetic vs. logical shift).
  - For competitive programming, it is safer to treat the input as an unsigned int during the reversal process to ensure bits are shifted in as 0s.
 
### Solution
```cpp
class Solution {
public:
    int reverseBits(int n) {

        int rev = 0;
        for (int i = 0; i < 32; i++) {
            rev <<= 1;
            rev |= (n & 1);
            n >>= 1;
        }
        return rev;
    }
};
```
- Time complexity: O(1)
- Space complexity: O(1)

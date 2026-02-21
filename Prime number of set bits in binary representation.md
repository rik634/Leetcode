## Problem statement
- Given two integers left and right, return the count of numbers in the inclusive range [left, right] having a prime number of set bits in their binary representation.
- Recall that the number of set bits an integer has is the number of 1's present when written in binary.

### Solution
```cpp
class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {

        int count = 0;
        for (int i = left; i <= right; i++) {
            int c = __builtin_popcount(i);
            if (isPrime(c)) {
                count++;
            }
        }
        return count;
    }
};
```
- Time complexity:O((right - left) * log(right) + (right - left) * sqrt(log(right)))
- Space complexity: O(1)

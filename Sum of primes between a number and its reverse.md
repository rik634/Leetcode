## Problem statement
- You are given an integer n.
- Let r be the integer formed by reversing the digits of n.
- Return the sum of all prime numbers between min(n, r) and max(n, r), inclusive.

### Solution
```cpp
class Solution {
public:
    int findSum(int l, int r) {
        vector<bool> isPrime(r + 1, true);
        int sum = 0;
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= r; i++) {
            if (isPrime[i]) {
                if (i >= l) {
                    sum += i;
                }
                for (int j = 2 * i; j <= r; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return sum;
    }
    int sumOfPrimesInRange(int n) {

        int rev = 0;
        int temp = n;
        while (temp > 0) {
            int rem = temp % 10;
            rev = rev * 10 + rem;
            temp = temp / 10;
        }
        int mn = min(rev, n);
        int mx = max(rev, n);
        return findSum(mn, mx);
    }
};
```
- Time complexity: O(nloglogn) (sieve of eratosthenes)
- Space complexity: O(max(n,reverse(n))

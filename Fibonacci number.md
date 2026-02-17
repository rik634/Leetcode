## Problem statement


### Brute force (recursion)
```cpp
class Solution {
public:
    int fib(int n) {

        if (n <= 1) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
};
```
 - Time complexity: O(2^n)
 - Space complexity: O(n)

### DP
```cpp
class Solution {
public:
    int fib(int n) {

        if (n <= 1) {
            return n;
        }
        int p1 = 0;
        int p2 = 1;
        int curr = 0;
        for (int i = 2; i <= n; i++) {
            curr = p1 + p2;
            p1 = p2;
            p2 = curr;
        }
        return curr;
    }
};
```
- Time complexity: O(n)
- Space complexity:O(1)


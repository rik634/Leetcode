## Problem statement
- Given two integers N1 and N2, find their greatest common divisor.

### Brute force
``` cpp
int findGcd(int n1, int n2) {
    int gcd = 1;

    for(int i = 1; i <= min(n1, n2); i++) {
        if(n1 % i == 0 && n2 % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}
```
- Time complexity: O(min(n1,n2))
- Space complexity: O(1)


### Better
``` cpp
int findGcd(int n1, int n2) {

    for(int i = min(n1, n2); i > 0; i--) {
        if(n1 % i == 0 && n2 % i == 0) {
            return i;
        }
    }
    return 1;
}
```
- Time complexity: O(min(n1,n2))
- Space complexity: O(1)

### Optimal (Euclidean Algorithm)
```cpp
int findGcd(int a, int b) {
    while(a > 0 && b > 0) {
        if(a > b) {
            a = a % b;
        }
        else {
            b = b % a; 
        }
    }
    if(a == 0) {
        return b;
    }
    return a;
}
```
- Time complexity: O(min(n1,n2))
- Space complexity: O(1)

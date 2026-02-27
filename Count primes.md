## Problem statement
- Given an integer n, return the number of prime numbers that are strictly less than n.

### Solution (sieve of erotosthenes):
```cpp
class Solution {
public:
    int countPrimes(int n) {
        
        if(n==0)
        {
            return 0;
        }
        int count=0;
        vector<bool> isPrime(n,true);
        isPrime[0]=false;
        isPrime[1]=false;
        
        for(int i=2;i<n;i++)
        {
            if(isPrime[i])
            {
                count++;
            }
            for(int j=i+i;j<n;j+=i)
            {
                isPrime[j]=false;
            }
        }
        return count;
    }
};
```
- Time complexity: O(nloglogn)
- Space complexity: O(n)

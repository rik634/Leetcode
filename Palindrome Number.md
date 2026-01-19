## Problem statement
- Given an integer N, return true if it is a palindrome else return false.
- A palindrome is a number that reads the same backward as forward. For example, 121, 1331, and 4554 are palindromes because they remain the same when their digits are reversed.

### Solution
```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        
        bool flag=false;
        if(x<0)
        {
            return false;
        }
        long long num = abs((long long)x);
        long long rev=0;
        while(num>0)
        {
            int rem = num%10;
            rev=rev*10 + rem;
            num = num/10;
        }        

        if(rev>INT_MAX || rev<INT_MIN)
        {
            return false;
        }

        return rev==(long long)x;
    }
};
```
- Time complexity: O(logx+1) (base 10)
- Space complexity: O(1)

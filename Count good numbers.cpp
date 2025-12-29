// level: Medium
// problem statment:  A digit string is considered good if the digits at even indices (0-based) are even digits (0, 2, 4, 6, 8) and the digits at odd indices are prime digits (2, 3, 5, 7).
//Given an integer n, return the total number of good digit strings of length n. As the result may be large, return it modulo 109 + 7.
//A digit string is a string consisting only of the digits '0' through '9'. It may contain leading zeros.

// brute force
class Solution {
public:
    const int MOD=1e9+7;
    int countGoodNumbers(long long n) {

        long long ans = 1;
        for (int i = 0; i < n; i++) {
            if(i%2==0)
            {
                ans=(ans*5)%MOD;
            }
            else
            {
                ans=(ans*4)%MOD;
            }
        }
        return(int) ans%MOD;
    }
};
// time complexity:O(n)
// space complexity:O(1)

// optimized


// Level: Medium
// Link: https://leetcode.com/problems/count-good-numbers/description/
// Solution:
long long mod = (long long)(1e9+7);
long long power(long long base, long long exp)
    {
        long long res=1;
        while(exp>0)
        {
            if(exp%2==1)
            {
                res= (res*base)%mod;
            }
            base = (base*base)%mod;
            exp=exp/2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        
        long long result;
        if(n%2==0)
        {
           result = (power(5,n/2)*power(4,n/2))%mod;
        }
        else
        {
            result = (power(5,(n/2)+1)*power(4,n/2))%mod;
        }
        return (int) result;
    }

//level:easy
//link: https://leetcode.com/problems/palindrome-number/description/
//solution

class Solution {
public:
    bool isPalindrome(int x) {
        
        int num=x;
        if(x<0)
        {
            return false;
        }
        long long rev=0;
       
        while(x>0)
        {
            int rem=x%10;
            rev=rev*10+rem;
            x=x/10;
        }
        return rev==num;
    }
};

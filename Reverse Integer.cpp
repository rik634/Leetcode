//level: medium
//link: https://leetcode.com/problems/reverse-integer/description/
//solution


class Solution {
public:
    int reverse(int x) {
        
        int flag=0;
        if(x<0)
        {
            flag=1;
        }
        long long num=0;
        x = abs(x);
        while(x>0)
        {
            int rem = x% 10;
            num = num * 10 + rem;
            x = x / 10;
        }
        if( num > INT_MAX || num < INT_MIN)
        {
            return 0;
        }
        
        if(flag == 1)
        {
            return -1 * num;
        }
        return num;
    }
};

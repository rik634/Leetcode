//level: Medium
//link: https://leetcode.com/problems/count-total-number-of-colored-cells/description/
//solution
class Solution {
public:
    long long coloredCells(int n) {
        
        if(n==1)
        {
            return 1;
        }
        long long num=1;
        for(int i=2;i<=n;i++)
        {
            num = num + 4*(i-1);
        }
        return num;
    }
};

//level:Easy
//link: https://leetcode.com/problems/n-th-tribonacci-number/description/?envType=study-plan-v2&envId=leetcode-75
//solution

class Solution {
public:
    int tribonacci(int n) {
        if(n==0 || n==1)
        {
            return n;
        }
        if(n==2)
        {
            return 1;
        }
        int p1=0,p2=1,p3=1;
        int temp;
        for(int i=3;i<=n;i++)
        {
            temp=p1+p2+p3;
            p1=p2;
            p2=p3;
            p3=temp;
        }
        return p3;
    }
};

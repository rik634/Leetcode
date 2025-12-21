// level: easy
class Solution {
public:
    int reverseNum(int num)
    {
        int temp=num;
        int sum=0;
        while(temp>0){
            int rem = temp%10;
            sum = sum*10 + rem;
            temp = temp/10;
        }
        return sum;
    }
    int mirrorDistance(int n) {

        int rev = reverseNum(n);
        return abs(n-rev);
    }
};
// Time complexity: O(d)
// space complexity: O(1)

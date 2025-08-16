// Level: easy
class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n==1)
        {
            return true;
        }
        if(n<3)
        {
            return false;
        }
        int x = n;
        while(x>1)
        {
           
           if(x%4!=0)
           {
            return false;
           }
           x=x/4;

        }
        return true;
    }
};
// time complexity: O(logN, base 4)
// space complexity: O(1)

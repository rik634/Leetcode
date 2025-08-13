// Level: easy
class Solution {
public:
    bool isPowerOfThree(int n) {
        
        if(n<=0)
        {
            return false;
        }
        int x=n;
        while(x>1)
        {
            
            if(x%3!=0)
            {
                return false;
            }
            x=x/3;
        }
        return true;
    }
};
// time complexity: O(logn base 3)
// space complexity: O(1)

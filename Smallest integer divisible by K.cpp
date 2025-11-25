// leveL: Medium
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        
        int result=0;
        int i=1;
        if(k%2==0 || k%5==0)
        {
            return -1;
        }
        while(i<=k)
        {
            result = ((result*10) + 1)% k;
           
            if(result==0)
            {
                return i;
            }
            i++;
            
           
        }
        return -1;
    }
};
// Time complexity: O(k)
// Space complexity: O(1)

// Level: Easy
class Solution {
public:
    int smallestNumber(int n) {
        
        int res=1;
        while(res<n)
        {
            res = (res*2+1);
        }
        return res;
    }
};
// Time complexity: O(logn)
// space complexity: O(1)

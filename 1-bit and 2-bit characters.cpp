// Level: Easy
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        int n = bits.size();
        int i=0;
        for(i=0;i<n-1;)
        {
            i+=bits[i]+1;
        }
        return i==n-1;
       
    }
};
// Time complexity: O(n)
// Space complexity: O(1)

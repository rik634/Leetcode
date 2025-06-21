// Level: Easy
// Link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/
// Solution
class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int ans = start ^ goal;
        int count=0;
        while(ans>0)
        {
            if(ans&1==1) // odd
            {
                count++;
            }
            ans = ans >> 1;
        }
        if(ans==1)
        {
            count++;
        }
        return count;
    }
};
// Time Complexity: O(log (start^goal)) (base is 2)
// Space Complexity: O(1)

// Level: Easy
// Link: https://leetcode.com/problems/power-of-two/description/
// Solution
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(  (n>0) && (n & (n-1))==0 )
        {
            return true;
        }
        return false;
    }
};

// Time Complexity: O(1)
// Space Complexity: O(1)

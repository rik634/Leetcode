// Level: easy
// Link: https://leetcode.com/problems/jump-game/description/
// Solution
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        int maxIndex=0;
        for(int i=0;i<n;i++)
        {
            if(i>maxIndex)
            {
                return false;
            }
            maxIndex=max(maxIndex,i+nums[i]);
        }
        return true;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(1)

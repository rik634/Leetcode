// Level: Medium
// Link: https://leetcode.com/problems/jump-game-ii/description/
// Solution
class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        int jumps=0;
        int l=0,r=0;
        while(r<(n-1))
        {
            int farthest=0;
            for(int i=l;i<=r;i++)
            {
                farthest=max(i+nums[i],farthest);
            }
            l=r+1;
            jumps++;
            r=farthest;
        }
        return jumps;
    }
};
// - Time Complexity: O(N) // here, even if there are 2 loops, the while loop is just to check if we reached the end. In real, we are traversing the array once, so, it is O(N)
// - Space Complexity: O(1)

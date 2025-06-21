// Level: Medium
// Link: https://leetcode.com/problems/subsets/
// Solution
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        int subset = 1 << n ;
        vector<vector<int>> ans;
        for(int i=0;i<subset;i++)
        {
            vector<int> v;
            for(int j=0;j<n;j++)
            {
                if(( i & (1 << j)) > 0) // bit is set
                {
                    v.push_back(nums[j]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};
// Time Complexity: O(n*(2^n)) (nested for loops)
// Space Complexity: O(n*(2^n)) (there are total (2^n) subsets, in worst case each subset can have n elements)

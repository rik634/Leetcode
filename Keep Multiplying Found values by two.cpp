// LeveL: easy
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(auto it:nums)
        {
            if(original==it)
            {
                original=2*original;
            }
        }
        return original;
    }
};
// Time complexity: O(nlogn)
// Space complexity: O(1)

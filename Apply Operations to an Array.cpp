//level:medium
//link:https://leetcode.com/problems/apply-operations-to-an-array/description/?envType=daily-question&envId=2025-03-01
//solution
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int index=0;
        while(index<n-1)
        {
            if(nums[index]==nums[index+1])
            {
                nums[index]=2*nums[index];
                nums[index+1]=0;
            }
            index++;
        }
        stable_partition(nums.begin(), nums.end(), [](int n) { 
                                       return n != 0; });
        return nums;
    }
};

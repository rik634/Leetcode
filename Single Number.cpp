// Level: Easy
// Link: https://leetcode.com/problems/single-number/description/
// Solution
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num =0;
        for(int i=0;i<nums.size();i++)
        {
            num = num ^ nums[i];
        }
        return num;
    }
};
// Time Complexity: O(N) (N = Number of elements in array)
// Space Complexity: O(1)

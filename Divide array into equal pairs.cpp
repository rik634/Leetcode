//level: easy
//link: https://leetcode.com/problems/divide-array-into-equal-pairs/description/
//time complexity: O(n)
//space complexity: O(n)
//solution:
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        int m = nums.size();
        int n = m/2;
        int num=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])==mp.end())
            {
                mp.insert({nums[i],1});
            }
            else
            {
                mp[nums[i]]++;
            }
        }
        for(auto it: mp)
        {
            if(it.second%2!=0)
            {
                return false;
            }
        }
        return true;
    }
};

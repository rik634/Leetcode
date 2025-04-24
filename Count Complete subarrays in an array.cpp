//level: medium
//Link: https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/
//solution
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        int r=0;
        int num = s.size();
        int count=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0)
            {
                int rem = nums[i-1];
                mp[rem]--;
                if(mp[rem]==0)
                {
                    mp.erase(rem);
                }
            }
            while(r<nums.size() && mp.size()<num)
            {
                int add = nums[r];
                mp[add]++;
                r++;
            }
            if(mp.size()==num)
            {
                count+=(nums.size()-r+1);
            }
        }
        return count;

    }
};

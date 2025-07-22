// level: medium

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int l=0;
        int r=1;
        unordered_map<int,int> s;
        s.insert({nums[0],0});
        int sum=nums[0];
        int mx=nums[0];
        while(r<n)
        {
            while(s.find(nums[r])!=s.end())
            {
                s.erase(nums[l]);
                sum-=nums[l];
                l++;
               
            }
            s.insert({nums[r],r});
            sum+=nums[r];
            r++;
            mx=max(mx,sum);
        }
        return mx;
    }
};
// - Time complexity: O(N)
//   - space complexity: O(1)

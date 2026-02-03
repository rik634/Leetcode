// Level: Medium
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int count=1;
        int preCount=0;
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
                
            {
                count++;
            }
            else
            {
                preCount=count;
                count=1;
            }
            ans=max(ans,min(preCount,count));
            ans = max(ans,count/2);
        }
        return ans>=k;
    }
};

// time complexity: O(n)
// space complexity: O(1)

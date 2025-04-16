// Level: Medium
// Link: https://leetcode.com/problems/target-sum/description/
// Solution
class Solution {
public:
   
    int f(int ind, vector<int>& nums, int target,vector<vector<int>>& dp)
    {
        if(ind==0)
        {
            if(target==0)
            {
                return dp[ind][target]=nums[0]==0 ? 2 : 1;
            }
            else
            {
                return dp[ind][target]= (target==nums[0]);
            }
        }
        if(dp[ind][target]!=-1)
        {
            return dp[ind][target];
        }
        int notTake = f(ind-1,nums,target,dp);
        int take=0;
        if(nums[ind]<=target)
        {
            take = f(ind-1,nums,target-nums[ind],dp);
        }
        return dp[ind][target]=notTake + take;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum=0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if((sum-target)%2!=0 || (sum-target)<0)
        {
            return 0;
        }
        target = (sum-target)/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(n-1,nums,target,dp);
    }
};

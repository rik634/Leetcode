//Level:Medium
//Link:
//Solution

class Solution {
public:
    int maxS(vector<int> arr)
    {
        
        int n = arr.size();
        if(n==0)
        {
            return 0;
        }
        vector<int> dp(n,INT_MIN);
        dp[0]=arr[0];
        if(n==1)
        {
            return dp[0];
        }
        dp[1]=max(arr[0],arr[1]);
        if(n==2)
        {
            return dp[1];
        }
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        if(nums.size()==1)
        {
            return nums[0];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0)
            {
                temp1.push_back(nums[i]);
            }
            if(i!=(nums.size()-1))
            {
                temp2.push_back(nums[i]);
            }
        }
        return max(maxS(temp1),maxS(temp2));
    }
};

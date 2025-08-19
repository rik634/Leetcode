// Level: Medium
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0]==0 ? 1 : 0;
        long long len=nums[0]==0 ? 1 : 0;
        long long sum=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=0)
            {
                sum+=(len*(len+1))/2;
                len=0;
            }
            else
            {
                len++;
            }
            dp[i]=(len*(len+1))/2;
        }
        sum+=(len*(len+1))/2;
        return sum;
    }
};
// Time complexity: O(n)
// space complexity: O(n)

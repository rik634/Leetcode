// Level: Medium
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       
        // Code hereint lis[n];
        int n = nums.size();
        vector<int> lis(n,0);
        vector<int> dp(n,1);
        sort(nums.begin(),nums.end());
        
        int res=1;
        int lastIndex=0;
        for(int i=1;i<n;i++)
        {
            lis[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && (1+dp[j])>dp[i])
                {
                    lis[i]=j;
                    dp[i]=1+ dp[j];
                }
            }
            if(dp[i]>res)
            {
                res=dp[i];
                lastIndex=i;
            }
        }
        vector<int> arr;
        while(lis[lastIndex]!=lastIndex)
        {
            arr.push_back(nums[lastIndex]);
            lastIndex = lis[lastIndex];
        }
        arr.push_back(nums[lastIndex]);
        reverse(arr.begin(),arr.end());
        return arr;
    }
    
};

// - Time Complexity: O(n^2) (as we are storing the results of subproblem) + O(n) (for backtracking of LIS) + O(n*logn) (to sort array)
// - Space Complexity: O(n) (for the dp array) + O(n) (for the lis array)

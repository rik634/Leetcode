// level: medium
class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code hereint lis[n];
        int n = arr.size();
        vector<int> lis(n,0);
        vector<int> dp(n,1);
        
        
        int res=1;
        int lastIndex=0;
        for(int i=1;i<n;i++)
        {
            lis[i]=i;
            for(int j=0;j<i;j++)
            {
                if(arr[j]<arr[i] && (1+dp[j])>dp[i])
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
        vector<int> nums;
        while(lis[lastIndex]!=lastIndex)
        {
            nums.push_back(arr[lastIndex]);
            lastIndex = lis[lastIndex];
        }
        nums.push_back(arr[lastIndex]);
        reverse(nums.begin(),nums.end());
        return nums;
    }
};


// - Time Complexity: O(n^2) (as we are storing the results of subproblem) + O(n) (for backtracking of LIS)
// - Space Complexity: O(n) (for the dp array) + O(n) (for the lis array)

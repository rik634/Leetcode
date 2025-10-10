// Level: Medium
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        
        int n = energy.size();
        vector<int> dp(n+k,INT_MIN);
        for(int i=0;i<n;i++)
        {
            dp[i]= energy[i];
        }
        int mx=INT_MIN;
        for(int i=k;i<(n+k);i++)
        {
            if(i<n)
            {
                dp[i]=max(dp[i],dp[i-k]+dp[i]);
            }
            if(i>=n)
            {
                dp[i]=dp[i-k];
                mx=max(mx,dp[i]);
            }
        }
        return mx;
       
    }
};
// time complexity: O(2*n)
// soace complexity: O(n+k)

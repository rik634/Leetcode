// level: Medium
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {

        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=costs[0]+1;
        if(n==1)
        {
            return dp[1];
        }
        dp[2]=min(dp[0]+costs[1]+4,dp[1]+costs[1]+1);
        if(n==2)
        {
            return dp[2];
        }
        for(int i=3;i<=n;i++){
            
            int a = dp[i-1]+costs[i-1]+(1);
            int b = dp[i-2]+costs[i-1]+4;
            int c = dp[i-3]+costs[i-1]+9;
            dp[i]=min(a,min(b,c));
        }
        return dp[n];
    }
};
// time complexity: O(n)
// space complexity: O(n)

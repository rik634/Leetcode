//Levek: easy
//Link: https://leetcode.com/problems/minimum-cost-to-reach-every-position/
//Solution
class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {

        int n = cost.size();
        vector<int> dp(n,0);
        dp[0]=cost[0];
        for(int i=1;i<n;i++)
            {
                if(cost[i]<dp[i-1])
                {
                        dp[i]=cost[i];
                }
                else
                {
                    dp[i]=dp[i-1];
                }
            }
        return dp;
    }
};

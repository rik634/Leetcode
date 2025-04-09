//solution-1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        
        return profit;        
    }
};

//solution-2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> dp(n,0);
        dp[0]=0;
        if(n==1)
        {
            return dp[0];
        }
        dp[1]=max(dp[1],prices[1]-prices[0]);
        if(n==2)
        {
            return dp[1];
        }
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i],prices[i]-prices[0]);
            for(int j=1;j<=i;j++)
            {
                dp[i]=max(dp[i],dp[j-1]+prices[i]-prices[j]);
            }
        }
        return dp[n-1];
    }
};

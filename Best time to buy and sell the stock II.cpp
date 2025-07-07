// Level: medium
// recursion

class Solution {
  public:
    int f(int ind, int day,vector<int>& prices)
    {
        if(ind==prices.size())
        {
            return 0;
        }
        int profit;
        if(day)
        {
            profit = max(-prices[ind]+f(ind+1,0, prices),f(ind+1,1,prices));
        }
        else
        {
            profit = max(prices[ind]+f(ind+1,1,prices),f(ind+1,0,prices));
        }
        return profit;
    }
    int maximumProfit(vector<int> &prices) {
        // code here
        return f(0,1,prices);
    }
};

// time complexity: O(2^n)
// space complexity: O(N)

// memoization
class Solution {
public:
   int f(int ind, int day,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(ind==prices.size())
        {
            return 0;
        }
        if(dp[ind][day]!=-1)
        {
            return dp[ind][day];
        }
        int profit;
        if(day)
        {
            profit = max(-prices[ind]+f(ind+1,0, prices,dp),f(ind+1,1,prices,dp));
        }
        else
        {
            profit = max(prices[ind]+f(ind+1,1,prices,dp),f(ind+1,0,prices,dp));
        }
        return dp[ind][day]=profit;
    }
    int maxProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};
// time complexity: O(2*n)
//- Space complexity:O(n) (auxiliary space for recursion stack) + O(n * 2) = O(n) (for the dp array)


// tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                {
                    dp[i][buy] = max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else
                {
                    dp[i][buy] = max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};

// - Time complexity: O(n)
//- Space complexity: O(n) (for the dp array)

// space optimized

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(2,0);
        vector<int> temp(2,0);
        prev[0]=prev[1]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                {
                    temp[buy] = max(-prices[i]+prev[0],prev[1]);
                }
                else
                {
                    temp[buy] = max(prices[i]+prev[1],prev[0]);
                }
            }
            prev=temp;
        }
        return prev[1];
    }
};

// - Time complexity: O(n)
// - Space complexity: O(1) (for the temp array)



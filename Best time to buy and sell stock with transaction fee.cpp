// level: medium
// recursion
class Solution {
public:
    int f(int ind, int buy, vector<int>& prices,int fee)
    {
        if(ind>=prices.size())
        {
            return 0;
        }
        int profit=0;
        if(buy)
        {
            profit = max(-prices[ind]-fee+f(ind+1,0,prices,fee),f(ind+1,1,prices,fee));
        }
        else
        {
            profit = max(prices[ind]+f(ind+1,1,prices,fee),f(ind+1,0,prices,fee));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices,int fee) {
        
        int n = prices.size();
    
        return f(0,1,prices,fee);
    }
};
// - Time complexity: O(2^n) (for each day, we have two choices: buy or not buy)
// - Space complexity: O(n) (for the recursion stack)

// memoization
class Solution {
public:
    int f(int ind, int buy, vector<int>& prices,int fee,vector<vector<int>>& dp)
    {
        if(ind>=prices.size())
        {
            return 0;
        }
        if(dp[ind][buy]!=-1)
        {
            return dp[ind][buy];
        }
        int profit=0;
        if(buy)
        {
            profit = max(-prices[ind]-fee+f(ind+1,0,prices,fee,dp),f(ind+1,1,prices,fee,dp));
        }
        else
        {
            profit = max(prices[ind]+f(ind+1,1,prices,fee,dp),f(ind+1,0,prices,fee,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices,int fee) {
        
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,prices,fee,dp);
    }
};

// - Time complexity: O(n * 2) = O(n) (since we are storing the results of subproblem)
// - Space complexity: O(n) (auxiliary space for recursion stack) + O(n * 2) = O(n) (for the dp array)


// tabulation
class Solution {
public:
    
    int maxProfit(vector<int>& prices,int fee) {
        
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                {
                    dp[ind][buy] = max(-prices[ind]-fee+dp[ind+1][0],dp[ind+1][1]);
                }
                else
                {
                    dp[ind][buy] = max(prices[ind]+dp[ind+1][1],dp[ind+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};


// - Time complexity: O(n * 2) = O(n) (since we are storing the results of subproblem)
// - Space complexity: O(n) (auxiliary space for recursion stack) + O(n * 2) = O(n) (for the dp array)

// space optimized
class Solution {
public:
    
    int maxProfit(vector<int>& prices,int fee) {
        
        int n = prices.size();
        vector<int> prev(2,0);
        vector<int> temp(2,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            temp[1] = max(-prices[ind]-fee+prev[0],prev[1]);
            temp[0] = max(prices[ind]+prev[1],prev[0]);
            prev=temp;
        }
        return prev[1];
    }
};

// - Time complexity: O(n) (we are iterating through the prices array once)
// - Space complexity: O(1) (we are using only a few variables to store the state)


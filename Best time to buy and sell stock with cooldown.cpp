// level: medium
// recursion
class Solution {
public:
    int f(int ind, int buy, vector<int>& prices)
    {
        if(ind>=prices.size())
        {
            return 0;
        }
        int profit=0;
        if(buy)
        {
            profit = max(-prices[ind]+f(ind+1,0,prices),f(ind+1,1,prices));
        }
        else
        {
            profit = max(prices[ind]+f(ind+2,1,prices),f(ind+1,0,prices));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        return f(0,1,prices);
    }
};

// - Time complexity: O(2^n) (for each day, we have two choices: buy or not buy)
// - Space complexity: O(n) (for the recursion stack)

//memoization
class Solution {
public:
    int f(int ind, int buy, vector<int>& prices,vector<vector<int>>& dp)
    {
        if(ind>=prices.size())
        {
            return 0;
        }
        int profit=0;
        if(dp[ind][buy]!=-1)
        {
            return dp[ind][buy];
        }
        if(buy)
        {
            profit = max(-prices[ind]+f(ind+1,0,prices,dp),f(ind+1,1,prices,dp));
        }
        else
        {
            profit = max(prices[ind]+f(ind+2,1,prices,dp),f(ind+1,0,prices,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};
// - Time complexity: O(n * 2) = O(n) (since we are storing the results of subproblem)
// - Space complexity: O(n) (auxiliary space for recursion stack) + O(n * 2) = O(n) (for the dp array)

// tabulation
class Solution {
public:
   
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy)
                {
                    profit = max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
                }
                else
                {
                    profit = max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);
                }
                dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }
};

// - Time complexity: O(n * 2) = O(n) (since we are storing the results of subproblem)
// - Space complexity: O(n) (auxiliary space for recursion stack) + O(n * 2) = O(n) (for the dp array) 

// space optimzed solution
class Solution {
public:
   
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> prev1(2,0);
        vector<int> prev2(2,0);
        vector<int> temp(2,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy)
                {
                    profit = max(-prices[ind]+prev1[0],prev1[1]);
                }
                else
                {
                    profit = max(prices[ind]+prev2[1],prev1[0]);
                }
                temp[buy]=profit;
            }
            prev2=prev1;
            prev1=temp;
        }
        return prev1[1];
    }
};


// - Time complexity: O(n*2) (since we are iterating through the prices array)
// - Space complexity: O(2*3) (we are using only a constant amount of space for variables)


// more optimized
class Solution {
public:
   
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> prev1(2,0);
        vector<int> prev2(2,0);
        vector<int> temp(2,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            temp[1] = max(-prices[ind]+prev1[0],prev1[1]);
            temp[0] = max(prices[ind]+prev2[1],prev1[0]);
                
            
            prev2=prev1;
            prev1=temp;
        }
        return prev1[1];
    }
};
// time complexity: O(n)
// space complexity: O(1)

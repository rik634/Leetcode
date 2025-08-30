// level: hard
// recursion


int f(int ind, int buy, int cap, vector<int>& prices)
    {
        if(cap==0)
        {
            return 0;
        }
        if(ind==prices.size())
        {
            return 0;
        }
        int profit=0;
        if(buy)
        {
            profit = max(-prices[ind]+f(ind+1,0,cap,prices),f(ind+1,1,cap,prices));
        }
        else
        {
            profit = max(prices[ind]+f(ind+1,1,cap-1,prices),f(ind+1,0,cap,prices));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        
        return f(0,1,2,prices);
    }
// - Time complexity:O(2^n) (for each day, we have two choices: buy or not buy)
// - space complexity:O(n) (for the recursion stack)

// memoization
class Solution {
public:
    int f(int ind, int buy, int cap, vector<int>& prices,vector<vector<vector<int>>>& dp)
    {
        if(cap==0)
        {
            return 0;
        }
        if(ind==prices.size())
        {
            return 0;
        }
        if(dp[ind][buy][cap]!=-1)
        {
            return dp[ind][buy][cap];
        }
        int profit=0;
        if(buy)
        {
            profit = max(-prices[ind]+f(ind+1,0,cap,prices,dp),f(ind+1,1,cap,prices,dp));
        }
        else
        {
            profit = max(prices[ind]+f(ind+1,1,cap-1,prices,dp),f(ind+1,0,cap,prices,dp));
        }
        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,prices,dp);
    }
};

// - Time complexity: O(n * 2 * 3) = O(n) (since we are storing the results of subproblem)
// - Space complexity: O(n * 2 * 3) + O(n) (auxiliary space for recursion stack) = O(n) (for the dp array)

// tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
         
         int n = prices.size();
         vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
         for(int i=0;i<=n;i++)
         {
            for(int buy=0;buy<=1;buy++)
            {
                dp[i][buy][0]=0;
            }
         }
         for(int buy=0;buy<=1;buy++)
         {
            for(int cap=0;cap<=2;cap++)
            {
                dp[n][buy][cap]=0;
            }
         }
         for(int ind=n-1;ind>=0;ind--)
         {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=2;cap++)
                {
                    int profit=0;
                    if(buy)
                    {
                        profit = max(-prices[ind]+dp[ind+1][0][cap],dp[ind+1][1][cap]);
                    }
                    else
                    {
                        profit = max(prices[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
                    }
                    dp[ind][buy][cap]=profit;
                }
            }
         }
         return dp[0][1][2];
    }
};

// - Time complexity: O(n*2*3) = O(n) (since we are storing the results of subproblem)
// - Space complexity: O(n*2*3) + O(n) (auxiliary space for recursion stack) = O(n) (for the dp array)

// space optimized
class Solution {
public:
    int maxProfit(vector<int>& prices) {
         
         int n = prices.size();
        vector<vector<int>> prev(2,vector<int>(3,0));
        vector<vector<int>> temp(2,vector<int>(3,0));

         for(int ind=n-1;ind>=0;ind--)
         {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=2;cap++)
                {
                    int profit=0;
                    if(buy)
                    {
                        profit = max(-prices[ind]+prev[0][cap],prev[1][cap]);
                    }
                    else
                    {
                        profit = max(prices[ind]+prev[1][cap-1],prev[0][cap]);
                    }
                    temp[buy][cap]=profit;
                }
            }
            prev=temp;
         }
         return prev[1][2];
    }
};
// - time complexity: O(n*2*3)
//- space complexity: O(2*3) = O(1) (for the dp array)

// further optimized solution
class Solution {
public:
    int f(int ind, int tran,vector<int>& prices)
    {
        if(ind==prices.size() || tran==4)
        {
            return 0;
        }
        int profit=0;
        if(tran%2==0) // buy
        {
            profit = max(-prices[ind]+f(ind+1,tran+1,prices),f(ind+1,tran,prices));
        }
        else // sell
        {
            profit = max(prices[ind]+f(ind+1,tran+1,prices),f(ind+1,tran,prices));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        return f(0,0,prices);
    }
};
// - time complexity: O(2^n) (for each day, we have two choices: buy or not buy)
// - space complexity: O(n) (for the recursion stack)

// memoization
class Solution {
public:
    int f(int ind, int tran,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(ind==prices.size() || tran==4)
        {
            return 0;
        }
        int profit=0;
        if(dp[ind][tran]!=-1)
        {
            return dp[ind][tran];
        }
        if(tran%2==0) // buy
        {
            profit = max(-prices[ind]+f(ind+1,tran+1,prices,dp),f(ind+1,tran,prices,dp));
        }
        else // sell
        {
            profit = max(prices[ind]+f(ind+1,tran+1,prices,dp),f(ind+1,tran,prices,dp));
        }
        return dp[ind][tran]=profit;
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return f(0,0,prices,dp);
    }
};
// - time complexity: O(n * 4) = O(n) (since we are storing the results of subproblem)
// - space complexity: O(n * 4) + O(n) (auxiliary space for recursion stack) = O(n) (for the dp array)


// tabulation
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(5,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int tran=3;tran>=0;tran--)
            {
                int profit=0;
                if(tran%2==0) // buy
                {
                    profit = max(-prices[ind]+dp[ind+1][tran+1],dp[ind+1][tran]);
                }
                else // sell
                {
                    profit = max(prices[ind]+dp[ind+1][tran+1],dp[ind+1][tran]);
                }
                dp[ind][tran]=profit;
            }
        }
        return dp[0][0];
    }
};

// - Time complexity: O(n * 4) = O(n) (since we are storing the results of subproblem)
// - Space complexity: O(n * 4) = O(n) (for the dp array)

// space optimized
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> prev(5,0);
        vector<int> temp(5,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int tran=3;tran>=0;tran--)
            {
                int profit=0;
                if(tran%2==0) // buy
                {
                    profit = max(-prices[ind]+prev[tran+1],prev[tran]);
                }
                else // sell
                {
                    profit = max(prices[ind]+prev[tran+1],prev[tran]);
                }
                temp[tran]=profit;
            }
            prev=temp;
        }
        return prev[0];
    }
};

// - Time complexity: O(n * 4) = O(n) (since we are storing the results of subproblem)
// - Space complexity: O(5) = O(1) (for the dp array)  


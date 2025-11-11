// Level: Medium
// Link: https://leetcode.com/problems/ones-and-zeroes/description/
//Solution: 

class Solution {
public:
    
    int f(int ind, int m, int n, vector<string>& strs,vector<vector<vector<int>>>& dp)
    {
        if(m<=0 && n<=0)
        {
            return 0;
        }
        int zero=0;
        int one =0;
        for(int i=0;i<strs[ind].size();i++)
        {
            if(strs[ind][i]=='1')
            {
                one++;
            }
            else
            {
                zero++;
            }
        }
        if(ind==0)
        {
            if(zero<=m && one<=n)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(dp[ind][m][n]!=-1)
        {
            return dp[ind][m][n];
        }
        int notTake = f(ind-1,m,n,strs,dp);
        int take=INT_MIN;
        if(zero<=m && one<=n)
        {
            take = 1+f(ind-1,m-zero,n-one,strs,dp);
        }
        return dp[ind][m][n]=max(notTake, take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<vector<int>>> dp(len,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return f(len-1,m,n,strs,dp);
        
    }
};
// time complexity: O((s*m*n)* constant)
// space complexity: O(s*m*n)

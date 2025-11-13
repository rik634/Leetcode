// level:Medium
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        int initial_score = grid[0][0];
        int initial_cost = grid[0][0] == 0 ? 0 : 1;
        if (initial_cost <= k) {
              dp[0][0][initial_cost] = initial_score; // Set the base case
        }
        for(int j=1;j<n;j++)
        {
            int score = grid[0][j];
            int cost = grid[0][j]==0 ? 0 : 1;
            for(int l=0;l<=k;l++)
            {
               if((l+cost)<=k && dp[0][j-1][l]!=-1)
               {
                  dp[0][j][l+cost]=max(dp[0][j][l+cost],dp[0][j-1][l]+score);
               }
            }
        }
        for(int i=1;i<m;i++)
        {
            int score = grid[i][0];
            int cost = grid[i][0]==0 ? 0 : 1;
            for(int l=0;l<=k;l++)
            {
                if((l+cost)<=k && dp[i-1][0][l]!=-1)
                {
                    dp[i][0][l+cost]=max(dp[i][0][l+cost],dp[i-1][0][l]+score);
                }
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                int score = grid[i][j];
                int cost = grid[i][j]==0 ? 0 : 1;
                for(int l=0;l<=k;l++)
                {
                    if((l+cost)<=k)
                    {
                        
                        if(dp[i-1][j][l]!=-1)
                        {
                            dp[i][j][l+cost]=max(dp[i][j][l+cost],dp[i-1][j][l]+score);
                        }
                        if(dp[i][j-1][l]!=-1)
                        {
                            dp[i][j][l+cost]=max(dp[i][j][l+cost],dp[i][j-1][l]+score);
                        }
                    }
                }

            }
        }

        int mx=INT_MIN;
        for(int i=0;i<=k;i++)
        {
            mx=max(mx,dp[m-1][n-1][i]);
        }
        return mx;

    }
};
// Time complexity: O(n*k) + O(m*k)+O(m*n*k) + O(k) ~= O(m*n*k)
// Space complexity: O(m*n*k)

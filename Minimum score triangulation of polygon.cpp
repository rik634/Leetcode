// Level: Medium
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        
        int n = values.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n-1;i++)
        {
            dp[i][i+1]=0;
            
        }
        dp[n-1][n-1]=0;
        for(int g=2;g<n;g++)
        {
            for(int i=0;i+g<n;i++)
            {
                int j = i+g;
                for(int k=i+1;k<j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+values[i]*values[j]*values[k]);
                }
            }
        }
        return dp[0][n-1];
    }
};
// time complexity: O(n^3)
// space complexity: O(n^2)

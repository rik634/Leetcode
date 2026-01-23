// level: Medium
// problem statement:

// solution (BFS)
class Solution {
public:
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        
      int n = mat[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0){
                    dp[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            int d = dp[p.first][p.second];
            for(int i=0;i<4;i++)
            {
                int r = dx[i]+p.first;
                int c = dy[i]+p.second;
                if(r>=0 && r<m && c>=0 && c<n && dp[r][c]==-1)
                {
                    dp[r][c]=1+d;
                    q.push({r,c});
                }
            }
        }
        return dp;
    }
};
// Time complexity: O(n*m*4) + O(n*m)  = O(n*m)
// space complexity: O(n*m) (dp) + O(n*m) (queue) = O(n*m)

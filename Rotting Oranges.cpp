//level: Medium
//link: https://leetcode.com/problems/rotting-oranges/description/?envType=study-plan-v2&envId=leetcode-75
//solution

class Solution {
public:
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int f=0;
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    f++;
                }
                if(grid[i][j]==2)
                {
                    vis[i][j]=true;
                    q.push({i,j});
                }
            }
        }
        if(f==0)
        {
            return 0;
        }
        int t=-1;
        while(!q.empty())
        {
            int size = q.size();
            t++;
            for(int i=0;i<size;i++)
            {
                auto p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                for(int j=0;j<4;j++ )
                {
                    int r = dx[j]+x;
                    int c = dy[j]+y;
                    if(r>=0 && r<m && c>=0 && c<n && grid[r][c]==1 && vis[r][c]==false)
                    {
                        count++;
                        q.push({r,c});
                        vis[r][c]=true;
                    }
                }
            }
        }
        if(f==count)
        {
            return t;
        }
        return -1;
    }
};

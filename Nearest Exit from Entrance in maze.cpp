//level:Medium
//link: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/?envType=study-plan-v2&envId=leetcode-75
//solution
class Solution {
public:
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int m = maze.size();
        int n = maze[0].size();
        int sr=entrance[0];
        int sc=entrance[1];
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc]=true;
        int count=0;
        if(maze[sr][sc]=='+')
        {
            return -1;
        }
        while(!q.empty())
        {
           int size = q.size();
           
           for(int j=0;j<size;j++)
           {
                auto p = q.front();
                q.pop();
            
                int x = p.first;
                int y = p.second;

                if((x==0 || x==m-1 || y==0 || y==n-1) )
             {
                if(x!=sr || y!=sc)
                {
                    return count;
                }
             }
            for(int i=0;i<4;i++)
            {
                int r = x + dx[i];
                int c = y + dy[i];
                if(r>=0 && r<m && c>=0 && c<n && vis[r][c]==false && maze[r][c]=='.')
                {
                    vis[r][c]=true;
                    q.push({r,c});
                }
            }
           }
           count++;
        }
        return -1;

    }
};

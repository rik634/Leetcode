// level: Medium
// problem statement:

// solution
class Solution {
public:
    vector<int> dx={0,0,1,-1,1,1,-1,-1};
    vector<int> dy={1,-1,0,0,1,-1,1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0)
        {
            return -1;
        }
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,pair<int,int>>> q;
        dist[0][0]=1;
        q.push({0,{0,1}});
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second.first;
            int len = p.second.second;
            if(x==n-1 && y==n-1)
            {
                return len;
            }
            for(int i=0;i<8;i++)
            {
                int r = x + dx[i];
                int c = y + dy[i];
                if(r>=0 && r<n && c>=0 && c<n && grid[r][c]==0 && dist[r][c]>(len+1))
                {
                    dist[r][c]=len+1;
                    q.push({r,{c,len+1}});
                }
            }
        }
        return -1;
        
    }
};
// Time complexity: O(n*n) (dist) + O(n*n) (queue) = O(8*n*n)
// space complexity: O(n*n)

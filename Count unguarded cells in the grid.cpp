// Level: Medium
class Solution {
public:
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        int count=0;
        queue<pair<int,int>> q;
        vector<vector<char>> grid(m,vector<char>(n,'0'));
        for(int i=0;i<guards.size();i++)
        {
            grid[guards[i][0]][guards[i][1]]='G';
            q.push({guards[i][0],guards[i][1]});
        }
        for(int i=0;i<walls.size();i++)
        {
            grid[walls[i][0]][walls[i][1]]='W';
        }
        // 0 for not visites and 1 for visites
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            for(int i=0;i<4;i++)
            {
                int x = r + dx[i];
                int y = c + dy[i];
                while(x>=0 && x<m && y>=0 && y<n && grid[x][y]!='G' && grid[x][y]!='W')
                {
                    
                    if(grid[x][y]=='0')
                    {
                        count++;
                        grid[x][y]='1';
                    }
                    x = x + dx[i];
                    y = y + dy[i];
                }
            }
        }
        return m*n-count-guards.size()-walls.size();
    }
};
// Time complexity: O(guard size) + O(walss size)+ O(guarsSize*4*max(m,n))
// Space complexity: O(n*m) + O(guardSize)

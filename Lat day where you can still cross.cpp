// level: hard

public:
    vector<int> dx = {1, -1, 0,0};
    vector<int> dy = {0, 0, 1,-1};
    bool isValid(int& row, int& col,vector<vector<int>>& cells, int index) {

        vector<vector<int>> dp(row,vector<int>(col,0));
        for(int i=0;i<=index;i++)
        {
            dp[cells[i][0]-1][cells[i][1]-1]=1;
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < col; i++) {
            if (dp[0][i]==0) {
                q.push({0, i});
            }
        }
        if (q.size() == 0) {
            return false;
        }
        int count = 1;
        while (!q.empty()) {
            int size = q.size();
            
            for (int j = 0; j < size; j++) {
                auto p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                if (x == row - 1) {
                    return true;
                }

                for (int i = 0; i < 4; i++) {
                    int r = dx[i] + x;
                    int c = dy[i] + y;
                    if (r >= 0 && r < row && c >= 0 && c < col &&
                        dp[r][c]==0) {
                        q.push({r, c});
                        dp[r][c]=1;
                    }
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    // initially land
        int ind = 0;
        int n = cells.size();
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            bool flag = isValid(row,col,cells,mid);
            if(flag)
            {
                ind=mid+1;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }

        }
        return ind;
    }
};
// time complexity: O(row*col*log(row*col))
// space complexity:O(row*col)

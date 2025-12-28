// level:easy
// problem statement:

// brute force
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]<0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
// time complexity:O(m*n)
// space complexity:O(1)

// binary search (optimized)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int i=m-1;
        int j=0;
        int count=0;
        while(i>=0 && j<n)
        {
            if(grid[i][j]<0)
            {
                count+=(n-j);
                i--;
            }
            else
            {
                j++;
            }
        }
        return count;
    }
};
// time complexity:O(m+n)
// space complexity:O(1)

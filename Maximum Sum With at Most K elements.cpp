//level:Medium
//link: https://leetcode.com/problems/maximum-sum-with-at-most-k-elements/description/
//solution

class Solution {
public:
    static bool myComp(const pair<int,int>& a, const pair<int,int>& b)
    {
        return a.first>b.first;
    }
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        
        vector<pair<int,int>> arr;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr.push_back({grid[i][j],i});
            }
        }

        sort(arr.begin(),arr.end(),myComp);
        vector<int> count(n,0);
        long long sum=0;
        int selected=0;
        for(auto it:arr)
        {
            int value = it.first;
            int rowIndex=it.second;
            if((count[rowIndex]<limits[rowIndex]) && selected<k)
            {
                sum+=value;
                count[rowIndex]++;
                selected++;
            }
            if(selected==k)
            {
                break;
            }
        }
        return sum;
    }
};

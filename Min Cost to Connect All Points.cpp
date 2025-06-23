// Level: Medium
// Link: https://leetcode.com/problems/min-cost-to-connect-all-points/
// Solution

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,0});
        vector<bool> vis(n,false);
        int total=0;
        while(!q.empty())
        {
            auto p = q.top();
            q.pop();
            int cost = p.first;
            int index = p.second;
            int x = points[index][0];
            int y = points[index][1];
            if(vis[index]==true)
            {
                continue;
            }
            vis[index]=true;
            total+=cost;
            for(int i=0;i<n;i++)
            {
                if(i==index)
                {
                    continue;
                }
                if(vis[i]==false)
                {
                    int dist = abs(points[i][0]-x) + abs(points[i][1]-y);
                    q.push({dist,i});
                }

            }
        }
        return total;
    }
};
// Time Complexity: E*logE (E = number of points)
// Space Complexity: O(E) 

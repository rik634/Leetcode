// level: Medium
// Memoization 
class Solution {
public:
    static bool myComp(const pair<int,pair<int,int>>&a, const pair<int,pair<int,int>>&b)
    {
        if(a.first==b.first)
        {
            return a.second.first<=b.second.first;
        }
        return a.first<b.first;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        
        int n = events.size();
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({events[i][0],{events[i][1],events[i][2]}});
        }
        sort(v.begin(),v.end(),myComp);
        int mx=0;
        for(int i=0;i<n-1;i++)
        {
            mx=max(mx,v[i].second.second);
            for(int j=i+1;j<n;j++)
            {
                mx=max(mx,v[j].second.second);
                if(v[i].second.first<v[j].first)
                {
                    mx=max(mx,v[i].second.second+v[j].second.second);
                }
            }
        }
        return mx;
    }
};
// Time complexity: sorting O(nlogn)+ binary search for each index O(3*n*logn) = O(nlogn)
// space complexity: O(3*n) = O(n)

// 

//level:medium
//link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
//solution

class Solution {
public:
    const long long M = 1000000007;
    unordered_map<int,int> mp;
    
    int dfs(int& n, vector<vector<pair<int,int>>>& adj)
    {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,greater<>> pq;
        vector<long long> dist(n,LLONG_MAX);
        dist[0]=0;
        mp.insert({0,1});
        pq.push({0,0});
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            int node = p.second;
            long long time = p.first;
            if(time > dist[node])
            {
                continue;
            }
            for(auto& it:adj[node])
            {
                if(dist[it.first]>(time+it.second))
                {
                    dist[it.first]=time + it.second;
                    mp[it.first]=mp[node];
                    pq.push({dist[it.first],it.first});
                }
                else if(dist[it.first]==time + it.second)
                {
                    mp[it.first]=(mp[it.first]+mp[node])%M;
                }
            }
        }
        return mp[n-1];
    }
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<roads.size();i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            int t = roads[i][2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        int d =n-1;
        return dfs(n,adj);
       
    }
};

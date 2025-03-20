//level:hard
//link: https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/description/
//solution

class Solution {
public:
    void dfs(int& u, int& cId, int& mn,vector<int>& component,vector<vector<pair<int, int>>>& adj)
    {
         component[u]=cId;
         for(auto it:adj[u])
         {
            mn = mn&it.second;
            if(component[it.first]==-1)
            {
                dfs(it.first,cId,mn,component, adj);
            }
         }

    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        
       // vector<pair<int,int>> adj[n];
       vector<vector<pair<int, int>>> adj(n);
       vector<int> component(n,-1);
       vector<int> dist(n,INT_MAX);
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int cId=0;
        for(int i=0;i<n;i++)
        {
            if(component[i]==-1)
            {
                int mn=INT_MAX;
                dfs(i,cId,mn,component, adj);
                dist[cId]=mn;
                cId++;
            }
        }
        vector<int> res;
        for(int i=0;i<query.size();i++)
        {
            int s = query[i][0];
            int d = query[i][1];
            if(component[s]!=component[d])
            {
                res.push_back(-1);
            }
            else
            {
                res.push_back(dist[component[s]]);
            }
        }
        return res;
    }
};

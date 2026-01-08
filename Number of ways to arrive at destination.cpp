//level:medium
//link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
// problem statement:


// brute force (array)
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const long long MOD = (long long)1e9 + 7;
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int time = roads[i][2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        vector<long long> time(n, LLONG_MAX);
        vector<int> ways(n, 0);
        vector<bool> vis(n,false);
        time[0] = 0;
        ways[0] = 1;
        for(int i=0;i<n;i++){
            int u =-1;
            for(int v=0;v<n;v++){
                if(vis[v]==false && (u==-1 || time[v]<time[u])){
                    u=v;
                }
            }

            if(time[u]==LLONG_MAX) {
                break;
            }
            for(auto it:adj[u]) {
                long long t = it.second;
                long long v = it.first;
                if((time[u]+t)<time[v]) {
                    time[v]=time[u]+t;
                    ways[v]=ways[u];
                }else if(time[u]+t==time[v]){
                    ways[v]=(ways[v]+ways[u])%MOD;
                }
            }
            vis[u]=true;
        }
        return ways[n-1]%MOD;
    }
};
// Time complexity: O(V*V+E)
// space complexity: O(V+E)

// further optimized (using queue)
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        const long long MOD=(long long)1e9+7;
        vector<pair<int,int>> adj[n];
        for(int i=0;i<roads.size();i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            int time = roads[i][2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        vector<long long> time(n,LLONG_MAX);
        vector<int> ways(n,0);
        time[0]=0;
        ways[0]=1;
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>> q;
        q.push({time[0],0});
        while(!q.empty())
        {
            auto p = q.top();
            q.pop();
            long long t = p.first;
            long long u = p.second;
            if(t>time[u])
            {
                continue;
            }
            for(auto it:adj[u])
            {
                long long tt = it.second;
                long long v = it.first;
                if((t+tt)<time[v])
                {
                    time[v]=time[u]+tt;
                    ways[v]=ways[u];
                    q.push({time[v],v});
                }
                else if(time[v]==(time[u]+tt))
                {
                    ways[v]=(ways[v]+ways[u])%MOD;
                }
            }
        }
        return ways[n-1]%MOD;

    }
};
// Time complexity: O(ElogV)
// space complexity: O(V+E)



// optimized (using set)
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        const long long MOD=(long long)1e9+7;
        vector<pair<int,int>> adj[n];
        for(int i=0;i<roads.size();i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            int time = roads[i][2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        vector<long long> time(n,LLONG_MAX);
        vector<int> ways(n,0);
        time[0]=0;
        ways[0]=1;
       
        set<pair<long long,long long>> q;
        q.insert({time[0],0});
        while(!q.empty())
        {
            
            long long t = q.begin()->first;
            long long u = q.begin()->second;
            q.erase(q.begin());
            if(t>time[u])
            {
                continue;
            }
            for(auto it:adj[u])
            {
                long long tt = it.second;
                long long v = it.first;
                if((t+tt)<time[v])
                {
                    if(time[v]!=LLONG_MAX)
                    {
                        q.erase({time[v],v});
                    }
                    time[v]=time[u]+tt;
                    ways[v]=ways[u];
                    q.insert({time[v],v});
                }
                else if(time[v]==(time[u]+tt))
                {
                    ways[v]=(ways[v]+ways[u])%MOD;
                }
            }
        }
        return ways[n-1]%MOD;

    }
};
// Time complexity: O(ElogV)
// space complexity: O(E+V)

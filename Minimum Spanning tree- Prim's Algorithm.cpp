int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<bool> vis(V,false);
        q.push({0,0});
        
        int sum=0;
        while(!q.empty())
        {
            auto p = q.top();
            q.pop();
            int node = p.second;
            int wt = p.first;
            if(vis[node]==true)
            {
                continue;
            }
            //adding to mst
            vis[node]=true;
            sum+=wt;
            for(auto it:adj[node])
            {
                if(vis[it[0]]==false)
                {
                    q.push({it[1],it[0]});
                }
            }
        }
        return sum;
    }

// Time Complexity: E*logE
// Space Complexity: O(E+V)

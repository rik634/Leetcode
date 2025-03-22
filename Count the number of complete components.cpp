//level: medium
//link: https://leetcode.com/problems/count-the-number-of-complete-components/description/
//solution

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int count=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                vector<int> component;
                queue<int> q;
                q.push(i);
                vis[i]=true;
                while(!q.empty())
                {
                    auto p = q.front();
                    q.pop();
                    component.push_back(p);
                    for(auto it:adj[p])
                    {
                        if(vis[it]==false)
                        {
                            q.push(it);
                            vis[it]=true;
                        }
                    }
                }
                bool isComplete= true;
                for(auto node: component)
                {
                    if(adj[node].size()!=component.size()-1)
                    {
                        isComplete=false;
                        break;
                    }
                }
                if(isComplete==true)
                {
                    count++;
                }
            }

        }
        return count;
    }
};

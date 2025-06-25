//level: Medium
//link: https://leetcode.com/problems/number-of-provinces/description/?envType=study-plan-v2&envId=leetcode-75
//solution

// using DFS
class Solution {
public:
    void dfs(vector<int> adj[],vector<bool>& vis, int u)
    {
        vis[u]=true;
        for(auto v:adj[u])
        {
            if(vis[v]==false)
            {
                dfs(adj,vis,v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                count++;
                dfs(adj,vis,i);
            }
        }
        return count;
    }
};

// Using disjoint set

class DisjointSet{
  vector<int> rank, parent, size;
public:
  DisjointSet(int n)
  {
    rank.resize(n+1,0);
    size.resize(n+1,1);
    parent.resize(n+1);
    for(int i=0;i<=n;i++)
    {
      parent[i]=i;
    }
  }
  int findUPar(int node)
  {
    if(node==parent[node])
    {
      return node;
    }
    return parent[node]=findUPar(parent[node]);
  }
  void unionByRank(int u, int v)
  {
    int pu = findUPar(u);
    int pv = findUPar(v);
    if(pu==pv)
    {
      return;
    }
    if(rank[pu]<rank[pv])
    {
      parent[pu]=pv;
    }
    else if(rank[pv]<rank[pu])
    {
      parent[pv]=pu;
    }
    else
    {
      parent[pv]=pu;
      rank[pu]++;
    }
  }
  void unionBySize(int u, int v)
  {
    int pu = findUPar(u);
    int pv = findUPar(v);
    if(pu==pv)
    {
      return;
    }
    if(size[pu]<size[pv])
    {
      parent[pu]=pv;
      size[pv]+=size[pu];
    }
    else
    {
      parent[pv]=pu;
      size[pu]+=pv;
    }
  }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int V = isConnected.size();
        DisjointSet ds(V);
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(isConnected[i][j]==1)
                {
                    ds.unionBySize(i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<V;i++)
        {
            if(ds.findUPar(i)==i)
            {
                count++;
            }
        }
        return count;
    }
};
// - Time Complexity: O(N^2) + O(N*4*alpha) (let's say, each node is independent, and for each of those, we are calling the findUPar function )
// - Space Complexity: O(N^2)


// Level: Medium
// Link: https://www.geeksforgeeks.org/problems/number-of-islands/0
// Solution
// User function Template for C++
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
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int count=0; // number of components
        vector<int> res;
        for(auto it:operators)
        {
            int r = it[0];
            int c = it[1];
            if(vis[r][c]==true)
            {
                res.push_back(count); 
                continue;// there is no change in the number of components
            }
            vis[r][c]=true;
            count++;
            for(int i=0;i<4;i++)
            {
                int x = dx[i]+r;
                int y = dy[i]+c;
                if(x>=0 && x<n && y>=0 && y<m && vis[x][y]==true)
                {
                    // let's check if they are already connected
                    int node = r*m+c;
                    int adj = x*m+y;
                    if(ds.findUPar(node)!=ds.findUPar(adj))
                    {
                        count--;
                        ds.unionBySize(node, adj);
                    }
                   
                }
            }
            res.push_back(count);
        }
        
        return res;
        
    }
};

// - Time Complexity: O(Q*4*alpha)
// - Space Complexity: O(Q) + O(2*n*m) (parent and size array)

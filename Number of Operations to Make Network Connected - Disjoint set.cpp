// Level: Medium
// Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
// Solution
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        DisjointSet ds(n);
        int extraEdges=0;
        for(auto it:connections)
        {
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u)==ds.findUPar(v))
            {
                extraEdges++;
            }
            else
            {
                ds.unionBySize(u,v);
            }
        }
        int noOfComponents = 0;
        for(int i=0;i<n;i++)
        {
            if(ds.findUPar(i)==i)
            {
                noOfComponents++;
            }
            
        }
        if(extraEdges>=(noOfComponents-1))
        {
            return noOfComponents-1;
        }
        return -1;
    }
};

// - Time Complexity: O(E*4*alpha) (To calculate the extra edges) + O(N*4*alpha) (To calculate the count of components)
// - Space Complexity: O(2*N) (To store parent and size array)



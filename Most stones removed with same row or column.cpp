// Level:Medium
// Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
// Solution

class DisjointSet{
  
public:
vector<int> rank, parent, size;
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
      size[pu]+=size[pv];
    }
  }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size(); // number of stones
        int maxRowIndex =0;
        int maxColIndex =0;
        for(auto it:stones)
        {
            maxRowIndex = max(maxRowIndex, it[0]);
            maxColIndex = max(maxColIndex,it[1]);
        }
        DisjointSet ds(maxRowIndex+maxColIndex+1); // +1 for safe-side
        unordered_map<int,int> stoneNodes;
        for(auto it:stones)
        {
            int row = it[0];
            int col = it[1] + maxRowIndex + 1;
            ds.unionBySize(row, col);
            stoneNodes[row]=1;
            stoneNodes[col]=1;
        }
        int count=0;
        for(auto it:stoneNodes)
        {
            if(ds.findUPar(it.first)==it.first)
            {
                count++;
            }
        }
        return n-count; 

    }
};

// - Time Complexity: O(N) + O(N) + O(4*alpha) = O(N)
// - Space Complexity: O(2*(maxRowIndex+maxColIndex)) (parent and size array)

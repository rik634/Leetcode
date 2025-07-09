// Level: Medium
// Link: https://leetcode.com/problems/accounts-merge/description/
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mp;
        // O(N+E) (N= number of indices, E = number of emails) 
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(mp.find(accounts[i][j])==mp.end())
                {
                    mp.insert({accounts[i][j],i});
                }
                else
                {
                    ds.unionBySize(mp[accounts[i][j]],i);
                }
            }
        }
        vector<vector<string>> mergedMail(n);
        vector<vector<string>> res;
        // O(E*4*alpha) (in worst case, we will call find E times, for each mail)
        for(auto it:mp)
        {
            string mail = it.first;
            int uPar = ds.findUPar(it.second);
            mergedMail[uPar].push_back(mail);
        }
        // O(N*(E*logE + E))
        for(int i=0;i<n;i++)
        {
            if(mergedMail[i].size()==0)
            {
                continue;
            }
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedMail[i])
            {
                temp.push_back(it);
            }
            res.push_back(temp);
        }
        return res;
    }
};

// - Time Complexity: O(N+E) + O(E*4*alpha) + O(N*(E*logE + E))
// - Space Complexity: O(N+E) (merged mail) + O(N+E) (res array) + O(3*N) (parent, size, rank)

// Level: Medium
// Link: https://leetcode.com/problems/accounts-merge/description/
// problem statement: 


// solution:
class DisjointSet {
    vector<int> parent, rank, size;

public:
    DisjointSet(int n) {
        parent.resize(n, 0);
        rank.resize(n, 0);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 0;
        }
    }
    int findParent(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    void unionBySize(int x, int y) {
        int px = findParent(x);
        int py = findParent(y);
        if (px == py) {
            return;
        }
        if (size[px] <= size[py]) {
            parent[px] = py;
            size[py] += size[px];
        } else {
            parent[py] = px;
            size[px] += size[py];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();
        unordered_map<string, int> mp;
        DisjointSet ds(n);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mp.find(mail) == mp.end()) {
                    mp[mail] = i;
                } else {
                    ds.unionBySize(i, mp[mail]);
                }
            }
        }
        vector<string> res[n];
        for (auto it : mp) {
            string s = it.first;
            int node = ds.findParent(it.second);
            res[node].push_back(s);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (res[i].size() == 0) {
                continue;
            }
            sort(res[i].begin(), res[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : res[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
//Time Complexity: O(N+E) + O(E*4ɑ) + O(N*(ElogE + E)) where N = no. of indices or nodes and E = no. of emails. 
     //The first term is for visiting all the emails. The second term is for merging the accounts. And the third term is for sorting the emails and storing them in the answer array.
//Space Complexity: O(N)+ O(N) +O(2N) ~ O(N) where N = no. of nodes/indices.
      //The first and second space is for the ‘mergedMail’ and the ‘ans’ array. The last term is for the parent and size array used inside the Disjoint set data structure.

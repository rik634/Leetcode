// Level: Medium
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        
        map<int,unordered_set<int>> mp; // languages known by each user
        for(int i=0;i<languages.size();i++)
        {
            for(int j=0;j<languages[i].size();j++)
            {
                mp[i+1].insert(languages[i][j]);
            }
        }
        unordered_set<int> s;
        for(auto it:friendships)
        {
            bool flag=false;
            for(auto u:mp[it[0]])
            {
                if(mp[it[1]].find(u)!=mp.end())
                {
                    flag=true;
                    break;
                }
            }
            if(flag==false)
            {
                s.insert(it[0]);
                s.insert(it[1]);
            }
        }
        int cc=s.size();
        unordered_map<int,int> mp1;
        for(auto it:s)
        {
            for(auto v:mp[it])
            {
                mp1[v]++;
            }
        }
        int mx=0;
        for(auto it:mp1)
        {
            if(mx<it.second)
            {
                mx=it.second;
            }
        }
        return cc-mx;

    }
};

// time complexity: O(m*n) + O(500*m)+ O(n)
// space complexity: O(m*n)+O(m) +O(n) 

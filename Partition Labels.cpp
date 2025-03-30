//Level: Medium
//Link: https://leetcode.com/problems/partition-labels/description/
//Solution

class Solution {
public:
    static bool myComp(const pair<int,int>& a, const pair<int,int>& b)
    {
        if(a.first!=b.first)
        {
            return a.first<b.first;
        }
        else
        {
            return a.second<b.second;
        }
    }

    vector<int> partitionLabels(string s) {
        
        int n = s.length();
        unordered_map<char,pair<int,int>> mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])==mp.end())
            {
                mp.insert({s[i],{i,i}});
            }
            else
            {
                mp[s[i]].second=i;
            }
        }
        vector<pair<int,int>> v;
        for(auto it:mp)
        {
            v.push_back({it.second.first,it.second.second});
        }
        sort(v.begin(),v.end(),myComp);
        vector<int> res;
        int mx=v[0].second;
        int count=0;
        int start=0;
        for (int i = 1; i < v.size(); i++) 
        {
            if (v[i].first > mx) 
            {
                res.push_back(mx - start + 1);
                start = v[i].first;
                mx = v[i].second;
            } 
            else 
            {
                mx = max(mx, v[i].second);
            }
        }
        res.push_back(mx - start + 1);
        return res;
    }
};

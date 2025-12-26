// level: Medium
// problem statement:You are given a string s. Return the array of unique characters, sorted by highest to lowest occurring characters.
//If two or more characters have same frequency then arrange them in alphabetic order.

// brute force
class Solution {
public:
    static bool myComp(const pair<char,int>&a, const pair<char,int>& b)
    {
        if(a.second==b.second)
        {
            return a.first<b.first;
        }
        return a.second>b.second;
    }
    string frequencySort(string s) {
        
        int n = s.length();
        unordered_map<char,int> mp;
        for(auto it:s)
        {
            mp[it]++;
        }
        vector<pair<char,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({s[i],mp[s[i]]});
        }
        sort(v.begin(),v.end(),myComp);
        string res="";
        for(auto it:v)
        {
            res+=it.first;
        }
        return res;
    }
};
// time complexity:O(n)+ O(n) + O(nlogn)+ O(n) = O(3n+nlogn)= O(n*(1+logn))
// space complexity: O(n)+O(n)+O(n)=O(n)

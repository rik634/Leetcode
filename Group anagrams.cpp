// level:Medium
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;
        int n = strs.size();

        for(int i=0;i<n;i++)
        {
            string word = strs[i];
            sort(word.begin(),word.end());
            mp[word].push_back(strs[i]);
        }
        for(auto it:mp)
        {
            res.push_back(it.second);
        }
        return res;
    }
};
// time complexity: O(n*klogk)
// space complexity: o(n*k) (k=average length of string, n= number of strings)

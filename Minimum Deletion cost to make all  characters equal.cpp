// level:Medium
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {

        int n = s.length();
        unordered_map<char,long long> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]+=cost[i];
        }
        long long sum=0;
        long long mx=0;
        for(auto it:mp){
            mx= max(it.second,mx);
            sum+=it.second;
        }
        return sum-mx;
    }
};
// Time complexity: O(n)
// space complexity: O(n)

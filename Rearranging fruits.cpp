// level: Hard
// link: https://leetcode.com/problems/rearranging-fruits/description/
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        
        int n  = basket1.size();
        unordered_map<int,int> mp;
        int mn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mp[basket1[i]]++;
            mp[basket2[i]]--;
           
            mn=min(mn,min(basket1[i],basket2[i]));
        }
        long long cost =0;
        vector<int> res;
        
        for(auto it: mp)
        {
            if(it.second%2!=0)
            {
                return -1;
            }
            for(int j=0;j<abs(it.second)/2;j++)
            {
                res.push_back(it.first);
            }
        }
        
        sort(res.begin(),res.end());
        for(int i=0;i<res.size()/2;i++)
        {
           cost = cost + min(2*mn,res[i]);
           
        }
        return cost;
    }
};

// time complexity: O(n)+ O(nlogn) = O(nlogn)
// space complexity: O(n)

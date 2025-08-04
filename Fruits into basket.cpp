// level: medium
// link: https://leetcode.com/problems/fruit-into-baskets/description/

// topic: sliding window and hash
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n = fruits.size();
        int l=0;
        int r =0;
        int total=0;
        int mx=INT_MIN;
        unordered_map<int,int> mp;
        while(r<n)
        {
            mp[fruits[r]]++;
            while(mp.size()>2)
            {
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0)
                {
                    mp.erase(fruits[l]);
                }
                l++;
                total--;
                
            }
           
            total++;
            mx=max(mx,total);
            r++;
        }
        return mx;
    }
};

// time complexity: O(n)
// space complexity: O(n)

// level: Medium
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int l=0;
        int r=0;
        int mx=0;
        unordered_map<char,int> mp;
        while(r<n)
        {
            while(mp.find(s[r])!=mp.end())
            {
                mp.erase(s[l]);
                l++;
            }
            if(mp.find(s[r])==mp.end()) // not present
            {
               mp.insert({s[r],1});
               mx=max(mx,r-l+1);
            }
            r++;
        }
        return mx;
    }
};
// time complexity: O(2*N)
// space complexity: O(N)

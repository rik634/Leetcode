// level:Medium
// problem statemnt: The beauty of a string is defined as the difference between the frequency of the most frequent character and the least frequent character (excluding characters that do not appear) in that string.
//Given a string s, return the sum of beauty values of all possible substrings of s.

// brute force
class Solution {
public:
    int findBeautySum(unordered_map<char,int>& mp)
    {
        int mx=INT_MIN;
        int mn=INT_MAX;
        for(auto it:mp)
        {
            mx=max(mx,it.second);
            mn=min(mn,it.second);
        }
        return mx-mn;
    }
    int beautySum(string s) {
        
        int n = s.length();
        int bSum=0;
        for(int i=0;i<n;i++)
        {
            string temp="";
            unordered_map<char,int> mp;
            for(int j=i;j<n;j++)
            {
                mp[s[j]]++;
                bSum+=findBeautySum(mp);
            }
        }
        return bSum;
    }
};
// time complexity: O(n*n*26)=O(n*n)
// space complexity:O(26)=O(1)

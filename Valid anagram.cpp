// level: easy
// problem statement:  Given two strings, check if two strings are anagrams of each other or not.
//brute force (sort)
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int n = s.length();
        if(s.length()!=t.length())
        {
            return false;
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
                return false;
            }
        }
        return true;

    }
};
// time complexity:O(nlogn)
// space complexity:O(1)

// hash (optimized)
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int n = s.length();
        if(s.length()!=t.length())
        {
            return false;
        }
        unordered_map<char,int> mp;
        for(auto it:s)
        {
            mp[it]++;
        }
        for(auto it:t)
        {
            mp[it]--;
        }
        for(auto it:mp)
        {
            if(it.second!=0)
            {
                return false;
            }
        }
        return true;

    }
};
// time complexity: O(3*n) = O(n)
// space complexity:O(n)


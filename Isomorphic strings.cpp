// level: easy
// problem statement: Given two strings s and t, determine if they are isomorphic. Two strings s and t are isomorphic if the characters in s can be replaced to get t.
//All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

// brute force
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char,char> mp;
        if(s.length()!=t.length())
        {
            return false;
        }
        int n = s.length();
        unordered_set<char> st;
        for(int i=0;i<n;i++)
        {
            int src = s[i];
            int dest = t[i];
            if(st.find(t[i])!=st.end() && mp[src]!=dest)// found
            {
                return false;
            }
            else
            {
                st.insert(t[i]);
                if(mp.find(s[i])==mp.end())
                    {
                        mp[s[i]]=t[i];
                    }
                    else if(mp.find(s[i])!=mp.end() && mp[s[i]]!=t[i])
                    {
                        return false;
                    }
            }
        }
        return true;
    }
};
// time complexity:O(n)
// space complexity: O(2*n)


// space  optimized
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int m1[256]={0};
        int m2[256]={0};
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(m1[s[i]]!=m2[t[i]])
            {
                return false;
            }
            m1[s[i]]=i+1;
            m2[t[i]]=i+1;
        }
        return true;
    }
};
// time complexity:O(n)
// space complexity:O(1)

// level:easy
// problem statement: Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string "".

// brute force
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string res="";
        int n = strs.size();
        int mn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int m = strs[i].length();
            mn=min(mn,m);
        }
        int count=0;
        for(int i=0;i<mn;i++)
        {
            char ch=strs[0][i];
            count=1;
            for(int j=1;j<n;j++)
            {
                if(strs[j][i]!=ch)
                {
                    return res;
                }
                count++;
            }
            if(count==n)
            {
                res+=ch;
            }
        }
        return res;
    }
};
// time complexity: O(N) + O(m*n)m=minimum length of string) = O(m*n)
// space complexity:O(1)

// another approach
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        if(n==0)
        {
            return "";
        }
        sort(strs.begin(),strs.end());
        string first = strs[0];
        string last = strs[n-1];
        string res="";
        int mn = min(first.length(),last.length());
        for(int i=0;i<mn;i++)
        {
            if(first[i]!=last[i])
            {
                return res;
            }
            res+=first[i];
        }
        return res;
    }
};
// time complexity: O(nlogn) + O(mn)
// space complexity:O(1)

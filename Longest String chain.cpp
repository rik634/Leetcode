// Level: Medium
// Link: https://leetcode.com/problems/longest-string-chain/

class Solution {
public:
    bool compareString(string &s1, string& s2)
    {
        if(s1.size()!=(1+s2.size()))
        {
            return false;
        }
        int first=0; // pointer for s1
        int second =0; // pointer fro s2
        while(first!=s1.size())
        {
            if(s1[first]==s2[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }
        if(first==s1.size() && second==s2.size())
        {
            return true;
        }
        return false;
    }
    static bool comp(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),comp); // sort according to length
        int n = words.size();
        vector<int> dp(n,1);
        int mx=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(compareString(words[i],words[j]) && dp[i]<(1+dp[j]))
                {
                    dp[i]=1+dp[j];
                }
            }
            mx=max(mx,dp[i]);
        }
        return mx;
    }
};

// - Time Complexity: O(n^2 * m), where n is the number of strings and m is the average length of the strings.
// - Space Complexity: O(n), for the dp array. 



// level: Medium
// problem statement:

// brute force
class Solution {
public:
    bool checkWordBreak(int ind, string& s, unordered_set<string>& st)
    {
        if(ind==s.length())
        {
            return true;
        }
        string temp="";
        for(int i=ind;i<s.length();i++)
        {
            temp+=s[i];
            if(st.find(temp)!=st.end())
            {
                if(checkWordBreak(i+1,s,st))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        
        return checkWordBreak(0,s,st);

    }
};
// time complexity: O(n*n*n)
// space complexity: O(w*k) (w=size of set, k=max length of word) + O(n) (recursive stack space)

// optimized
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1, false);
        dp[0] = true;  // Empty string is always "segmented"
        int maxLen = 0;

        // Find the maximum length of the words in the dictionary
        for (const string& word : wordDict) {
            maxLen = max(maxLen, (int)word.size());
        }

        // DP to check if the string can be segmented
        for (int i = 1; i <= n; ++i) {
            for (int j = max(0, i - maxLen); j < i; ++j) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;  // Early termination when we find a valid word
                }
            }
        }

        return dp[n];  // Return if the entire string can be segmented
    }
};

// time complexity: O(n/m) (n=length of S, m = avarage length of words in set)
// space complexity: O(n)

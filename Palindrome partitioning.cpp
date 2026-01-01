// level: Medium
// problme statement: You are given a string s, partition it in such a way that every substring is a palindrome. Return all such palindromic partitions of string s. A palindrome string is a string that reads the same backward as forward.
// solution:
class Solution {
public:
    bool isPalindrome(string str)
    {
        int n = str.length();
        for(int i=0;i<(n/2);i++)
        {
            if(str[i]!=str[n-i-1])
            {
                return false;
            }
        }
        return true;
    }
    void findPartitions(int ind, string& s, vector<string> ans,
                        vector<vector<string>>& res) {
        if (ind == s.length()) {
            res.push_back(ans);
            return;
        }
        string temp = "";
        for (int i = ind; i < s.length(); i++) {
            temp += s[i];
            if (isPalindrome(temp)) {
                ans.push_back(temp);
                findPartitions(i + 1, s, ans, res);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {

        vector<vector<string>> res;
        vector<string> ans;
        findPartitions(0, s, ans, res);
        return res;
    }
};

// time complexity: O(2^N * N), we create all possible partitions and check whether they are palindrome or not.
// space complexity: O(2^N * N) + O(N), additional space used to store all possible results and auxiliary stack space.


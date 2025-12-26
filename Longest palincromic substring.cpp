// level:Medium
// problem statement:  Given a string s, return the longest palindromic substring in s.
// brute force
class Solution {
public:
    bool isPalindrome(string str)
    {
        int m = str.length();
        for(int i=0;i<m;i++)
        {
            if(str[i]!=str[m-i-1])
            {
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        
        string res="";
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            string temp="";
            for(int j=i;j<n;j++)
            {
                temp+=s[j];
                if(isPalindrome(temp))
                {
                    if(res.length()<temp.length())
                    {
                        res=temp;
                    }
                }
            }
        }
        return res;
    }
};
// time complexity: O(n*n*n)
// space complexity:O(1)

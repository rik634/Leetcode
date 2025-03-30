//Level: Medium
//Link: https://leetcode.com/contest/weekly-contest-443/problems/longest-palindrome-after-substring-concatenation-i/
//Solution
class Solution {
public:
    bool isPalindrome(const string &s1) 
   {
       int left = 0, right = s1.length() - 1;
       while (left < right) 
       {
           if (s1[left] != s1[right]) {
              return false;
           }
           left++;
            right--;
        }
        return true;
    }

    int longestPalindrome(string s, string t) {

        int maxLength = 0;
        for (int i = 0; i < s.length(); ++i) 
        {
            string substr1;
            for (int j = i; j < s.length(); ++j) 
            {
                substr1+=s[j];
                for (int k = 0; k < t.length(); ++k) 
                {
                    string substr2;
                    for (int l = k; l < t.length(); ++l) 
                    {
                          substr2+=t[l];
                          string combined = substr1 + substr2;
                          if (isPalindrome(combined)) 
                          {
                                maxLength = max(maxLength, (int)combined.length());
                           }
                          if (isPalindrome(substr1)) {
                               maxLength = max(maxLength, (int)substr1.length());
                           }
                           if (isPalindrome(substr2)) {
                               maxLength = max(maxLength, (int)substr2.length());
                           }
                    }
                }
            }
        }
        if(isPalindrome(s))
        {
            maxLength=max(maxLength,(int)s.length());
        }
        if(isPalindrome(t))
        {
            maxLength=max(maxLength,(int)t.length());
        }
        if(maxLength==0 && (s.length()!=0 || s.length()!=0))
        {
            return maxLength+1;
        }
    return maxLength;

    }
};©leetcode

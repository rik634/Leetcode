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

// optimized
class Solution {
public:
    string longestPalindrome(string str) {
        int start = 0, end = 0;

        // Iterate through each character as center
        for (int center = 0; center < str.length(); center++) {
            // Expand around odd length palindrome
            int lenOdd = expandFromCenter(str, center, center);
            // Expand around even length palindrome
            int lenEven = expandFromCenter(str, center, center + 1);
            // Get the max of both lengths
            int maxLen = max(lenOdd, lenEven);

            // Update the longest palindrome boundaries
            if (maxLen > end - start) {
                start = center - (maxLen - 1) / 2;
                end = center + maxLen / 2;
            }
        }

        // Return the longest palindromic substring
        return str.substr(start, end - start + 1);
    }

private:
    int expandFromCenter(const string& str, int left, int right) {
        // Expand while characters match and within bounds
        while (left >= 0 && right < str.length() && str[left] == str[right]) {
            left--;
            right++;
        }
        // Return the length of the palindrome
        return right - left - 1;
    }
};
// time complexity:O(n*n)
// space complexity:O(1)

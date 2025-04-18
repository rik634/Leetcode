//Level: Medium
// Link: https://leetcode.com/problems/count-and-say/description/
//Solution
class Solution {
public:
    string countAndSay(int n) {
        
        if(n==1)
        {
            return "1";
        }
        string s = countAndSay(n-1);
        string str="";
        int count=1;
        for(int i=1;i<s.length();i++)
        {
           if(s[i]==s[i-1])
           {
             count++;
           }
           else
           {
             str+=to_string(count);
             str+=s[i-1];
             count=1;
           }
        }
        str += to_string(count);
        str += s[s.length() - 1];

        return str;
    };
};

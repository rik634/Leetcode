//level: easy
//link: https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/description/
//solution

class Solution {
public:
    bool hasSameDigits(string s) {

        int n = s.length();
        string str;
        int num;
        while(n!=2)
            {
                for(int i=0;i<n-1;i++)
                    {
                        num =((s[i]-'0')+(s[i+1]-'0'))%10;
                        str+=to_string(num);
                    }
                s=str;
                str="";
                n=s.length();
            }
        return s[0]==s[1];
    }
};

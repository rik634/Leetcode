// Level: Easy
// Link: https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/description/
//Solution
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        
        int n = s.length();
        vector<string> res;
        int i;
        for(i=0;(i+k-1)<n;i+=k)
        {
            string str = s.substr(i,k);
            res.push_back(str);
        }
        if(n%k==0)
        {
            return res;
        }
        string str1 = s.substr(i,s.length()-i+1);
        int len = str1.length();
        while(len < k)
        {
            str1+=fill;
            len++;
        }
        if(str1.length()!=0)
        {
            res.push_back(str1);
        }
        return res;
    }
};

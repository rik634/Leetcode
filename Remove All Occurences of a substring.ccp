// level: high
//link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/?envType=daily-question&envId=2025-02-11
//solution:


class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        int n = s.length();
        int k = part.length();
        while(s.length()!=0)
        {
            if(s.find(part)!=string::npos)
            {
                s.erase(s.find(part),k);
            }
            else
            {
                break;
            }
        }
        return s;
    }
};

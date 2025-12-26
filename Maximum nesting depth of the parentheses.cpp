// level: easy
// problem statement: Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

// brute force
class Solution {
public:
    int maxDepth(string s) {
        
        int n = s.length();
        int count=0;
        int temp=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                temp++;
            }
            else if(s[i]==')')
            {
                count=max(count,temp);
                temp--;
            }
        }
        return count;
    }
    
};
// time complexity:O(n)
// space complexity:O(1)

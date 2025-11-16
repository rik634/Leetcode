// Level: Medium
// weekly contest 476
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a=0;
        int b=0;
        for(int i=0;i<s.length();i++)
        {
            a+= s[i]=='a' ?1 : 0;
            b+= s[i]=='b' ?1 : 0;
        }
        return abs(a-b);
    }
};
// time complexity: O(n)
// space complexity: O(1)

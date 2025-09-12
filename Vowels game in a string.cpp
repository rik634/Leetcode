// Level: Medium
class Solution {
public:
    bool isVowel(char ch)
    {
        ch = toupper(ch);
        if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
        {
            return true;
        }
        return false;
    }
    bool doesAliceWin(string s) {
        
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            if(isVowel(s[i]))
            {
                return true;
            }
        }
        return false;
    }
};
// time complexity: O(n)
// space complexity: O(1)

// Level: Easy
class Solution {
public:
    bool isVowel(char c)
    {
        c=toupper(c);
        if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
        {
            return true;
        }
        return false;
    }
    int maxFreqSum(string s) {
        
        unordered_map<char,int> vowel;
        unordered_map<char,int> consonent;
        for(auto ch:s)
        {
            if(isVowel(ch))
            {
                vowel[ch]++;
            }
            else
            {
                consonent[ch]++;
            }
        }
        int mxv=0;
        int mxc=0;
        for(auto it:vowel)
        {
            mxv=max(it.second,mxv);
        }
        for(auto it:consonent)
        {
            mxc=max(mxc,it.second);
        }
        return mxv+mxc;
    }
};
// time complexity: O(n)
// space complexity: O(1)

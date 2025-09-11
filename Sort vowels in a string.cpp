// Level: Medium
class Solution {
public:
    bool isVowel(char a)
    {
        char c = toupper(a);
        if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
        {
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        
        int n = s.length();
        vector<char> vowel;
        for(auto ch:s)
        {
            if(isVowel(ch))
            {
                vowel.push_back(ch);
            }
        }
        sort(vowel.begin(),vowel.end());
        string t =s;
        int index=0;
        for(char& x:t)
        {
            if(isVowel(x))
            {
                x=vowel[index];
                index++;
            }
        }
        return t;


    }
};
// time complexity: O(n) + O(nlogn)
// space complexity: O(n)

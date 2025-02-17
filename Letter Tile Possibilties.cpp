//level: medium
//link: https://leetcode.com/problems/letter-tile-possibilities/description/
//solution

class Solution {
public:
    void countSubsequence(vector<int>& freq, int& count)
    {
        for(int i=0;i<26;i++)
        {
            if(freq[i]>0)
            {
                freq[i]--;
                count++;
                countSubsequence(freq,count);
                freq[i]++;
            }
        }
        
    }
    int numTilePossibilities(string tiles) {
        
        vector<int> freq(26,0);
        for(int i=0;i<tiles.length();i++)
        {
            freq[tiles[i]-'A']++;
        }
        int count=0;
        countSubsequence(freq,count);
        return count;
    }
};

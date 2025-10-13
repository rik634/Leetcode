// Level: Easy
class Solution {
public:
    bool isAnagram(string& word1, string& word2)
    {
        vector<int> freq(26,0);
        for(auto it:word1)
        {
            freq[it-'a']++;
        }
        for(auto it:word2)
        {
            freq[it-'a']--;
        }
        for(auto it:freq)
        {
            if(it!=0)
            {
                return false;
            }
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        
        int n = words.size();
        vector<string> res;
        res.push_back(words[0]);
        int index=0;
        for(int i=1;i<n;i++)
        {
            if(isAnagram(words[i],words[i-1]))
            {
                continue;
            }
            res.push_back(words[i]);
        }
        return res;

    }
};

// time complexity: O(n*m) (n=length of array, m = max length of string)
// space complexity: O(n)

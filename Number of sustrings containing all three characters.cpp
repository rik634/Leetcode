//level: medium
//link:
//time complexity : O(n), as we are using sliding window here
//space complexity : O(1)
//solution
class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n = s.length();
        int l=0,r=0;
        vector<int> freq(3,0);
        int count=0;
        while(r<n)
        {
            char curr = s[r];
            freq[curr-'a']++;
            while(hasAllThree(freq))
            {
                count = count + (n-r);
                freq[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return count;
    }
    bool hasAllThree(vector<int>& freq)
    {
        return freq[0]>=1 && freq[1]>=1 && freq[2]>=1;
    }
};

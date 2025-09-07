// level: medium
class Solution {
public:
    int minOperations(string s) {
        
        int count=0;
        map<char,int> mp;
        for(auto ch:s)
        {
            mp[ch]++;
        }
        if(mp.size()==1 && s[0]=='a')
        {
            return 0;
        }
        for(auto it: mp)
        {
            if(it.first=='a')
            {
                continue;
            }
            char c = it.first;
            int f = it.second;
           if(c=='z')
           {
            mp['a']+=it.second;
           }
           else
           {
             mp[c+1]+=it.second;
           }
            it.second=0;
            count++;
        }
        return count;
    }
};
// time complexity: O(n) + O(n)
// space complexity: O(n)

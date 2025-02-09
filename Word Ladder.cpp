// Level: Hard
// Link: https://leetcode.com/problems/word-ladder/description/
// solution:

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> s(wordList.begin(),wordList.end());
        s.erase(beginWord);

        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            string word=p.first;
            int count=p.second;
            if(word==endWord)
            {
                return count;
            }
            for(int i=0;i<word.size();i++)
            {
                char original=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(s.find(word)!=s.end())
                    {
                        s.erase(word);
                        q.push({word,1+count});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};

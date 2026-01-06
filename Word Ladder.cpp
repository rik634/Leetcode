// Level: Hard
// Link: https://leetcode.com/problems/word-ladder/description/
// problem statement: iven are the two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord..
//In this problem statement, we need to keep the following conditions in mind:
//A word can only consist of lowercase characters.//Only one letter can be changed in each transformation.
//Each transformed word must exist in the wordList including the targetWord. //startWord may or may not be part of the wordList
//Note:  If there’s no possible way to transform the sequence from startWord to targetWord return 0.
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

// here, as soon as we find the work in set, we remove it, as we dont want to repeatedly come to same word, also, we need to find the min length to get the endword
//Time Complexity: O(N * L * 26), where N is the number of words in the list and L is the length of each word. For each word, we attempt to change each of its L characters to 26 possible letters.
//Space Complexity: O(N * L), for the set storing all words and the queue used for BFS.

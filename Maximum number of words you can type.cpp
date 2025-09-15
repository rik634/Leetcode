// Level: Easy
class Solution {
public:
    vector<string> split_sentence(string sen) {
  
    vector<string> words;
    string word = "";
    for (char c : sen) {
        if (c == ' ') {
            words.push_back(word);
            word = "";
        }
        else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}

    int canBeTypedWords(string text, string brokenLetters) {
        
        vector<string> words = split_sentence(text);
        unordered_set<char> s;
        for(auto it: brokenLetters){
            s.insert(it);
        }
        int count=0;
        for(int i=0;i<words.size();i++)
        {
            bool flag=true;
            for(auto it: words[i])
            {
                if(s.find(it)!=s.end())
                {
                    flag=false;
                    break;
                }
            }
            if(flag==true)
            {
                count++;
            }
        }
        return count;
    }
};

// time complexity: O(n) + O(n*26)
// space complexity: O(n)+ O(26)

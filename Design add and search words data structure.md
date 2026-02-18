## Problem statement
- Design a data structure that supports adding new words and finding if a string matches any previously added string.
- Implement the WordDictionary class:
  1. WordDictionary() Initializes the object.
  2. void addWord(word) Adds word to the data structure, it can be matched later.
  3. bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 
### Logic:
- DFS + Trie

### Solution
```cpp
struct Node {
    Node* links[26];
    bool isEnd;
    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
        isEnd = false;
    }
};
class WordDictionary {
public:
    Node* root;
    int mx;
    WordDictionary() {
        root = new Node();
        mx = 0;
    }

    void addWord(string word) {

        Node* curr = root;
        for (auto ch : word) {
            if (curr->links[ch - 'a'] == NULL) {
                curr->links[ch - 'a'] = new Node();
            }
            curr = curr->links[ch - 'a'];
        }
        mx = max(mx, (int)word.length());
        curr->isEnd = true;
    }

    bool search(string word) {

        if (word.length() > mx) {
            return false;
        }
        return prefix(root, 0, word);
    }
    bool prefix(Node* node, int ind, string& word) {
        for (int i = ind; i < word.size(); i++) {
            char ch = word[i];
            if (ch == '.') {
                for (int j = 0; j < 26; j++) {
                    if (node->links[j] != NULL &&
                        prefix(node->links[j], i + 1, word)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (node->links[ch - 'a'] == NULL) {
                    return false;
                }
                node = node->links[ch - 'a'];
            }
        }
        return node->isEnd;
    }
};
```
- addWord: time - O(L), Space -O(L)
- search:  Time - O(26^L)worst case (all dots) . Space - O(L) call stack
- Trie storage: O(N · L · 26)

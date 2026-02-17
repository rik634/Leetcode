## Problem statement
- Implement "TRIE” data structure from scratch with the following functions.
  1. Trie(): Initialize the object of this “TRIE” data structure.
  2. insert(“WORD”): Insert the string “WORD” into this “TRIE” data structure.
  3. countWordsEqualTo(“WORD”): Return how many times this “WORD” is present in this “TRIE”.
  4. countWordsStartingWith(“PREFIX”): Return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.
  5. erase(“WORD”): Delete one occurrence of the string “WORD” from the “TRIE”.
 
### Solution:
```cpp
struct Node {
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void increaseEnd() {
        cntEndWith++;
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void deleteEnd() {
        cntEndWith--;
    }

    void reducePrefix() {
        cntPrefix--;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;=
        for (int i = 0; i < word.size(); i++) {

            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {

            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
            } else {
                return 0;
            }
        }
        return node->cntEndWith;
    }

    int countWordsStartingWith(string word) {

        Node* node = root;
        
        for (int i = 0; i < word.size(); i++) {
         
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
            } else {
                return 0;
            }
        }
        return node->cntPrefix;
    }

    void erase(string word) {

        Node* node = root;
     
        for (int i = 0; i < word.size(); i++) {

            if (node->containsKey(word[i])) {
               
                node = node->get(word[i]);
                node->reducePrefix();
            } else {
                return;
            }
        }
        node->deleteEnd();
    }
};
```
- Time Complexity: O(N), where N is the length of the word or prefix being processed. Each method (inserting a word, counting words equal to a given word, counting words starting with a prefix, and erasing a word) involves traversing the Trie for each character of the input word or prefix. Thus, the time complexity is linear relative to the length of the word or prefix being processed.
- Space Complexity: O(N), where N is the total number of characters across all words inserted into the Trie. The space complexity depends on the number of unique words added to the Trie and the average length of these words.

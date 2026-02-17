## Problem statement
- Implement the Trie class:
- Trie(): Initializes the trie object. void insert (String word): Inserts the string word into the trie.
- boolean search (String word): Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
- boolean startsWith (String prefix): Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.


### Solution
```cpp
class Node {
public:
    Node* child[26];
    bool isEndOfNode;
    Node() {
        isEndOfNode = false;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};
class Trie {
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* curr = root;
        for (auto ch : word) {
            if (curr->child[ch - 'a'] == NULL) {
                curr->child[ch - 'a'] = new Node();
            }
            curr = curr->child[ch - 'a'];
        }
        curr->isEndOfNode = true;
    }

    bool search(string word) {

        Node* curr = root;
        for (auto ch : word) {
            if (curr->child[ch - 'a'] == NULL) {
                return false;
            }
            curr = curr->child[ch - 'a'];
        }
        return curr->isEndOfNode;
    }

    bool startsWith(string prefix) {

        Node* curr = root;
        for (auto ch : prefix) {
            if (curr->child[ch - 'a'] == NULL) {
                return false;
            }
            curr = curr->child[ch - 'a'];
        }
        return true;
    }
};
```
- Time Complexity:
  1. Insertion: O(N), where N is the length of the word being inserted. This is because we need to go through each letter of the word to either find its corresponding node or create a new node as needed.
  2. Search: O(N), where N is the length of the word being searched for. During a Trie search, we traverse each letter of the word starting from the root, checking if the current node has a child node at the position of the next letter. This continues until we either reach the end of the word or find a missing letter node.
  3. Prefix Search: O(N), where N is the length of the prefix being searched for. Just like in word search, we go through each letter of the prefix to find its corresponding node.

- Space Complexity: O(N), where N is the total number of characters across all unique words inserted into the Trie. For each character in a word, a new node might need to be created, resulting in space usage that is proportional to the total number of characters.
